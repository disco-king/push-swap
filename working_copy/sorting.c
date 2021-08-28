#include "sort_stack.h"

int init_push(t_data *data)
{
	int i = 0;
	
	if(!data->b)
		data->mid = data->max / 2 + data->next;
	else
		data->mid = (data->max - data->next) / 2 + data->next;
	data->len = lst_len(data->a);
	while(i++ < data->len && !data->a->turn)
	{
		if(data->a->order <= data->mid)
			px(&(data->a), &(data->b), 'b');
		else
			rx(&(data->a), 'a');
	}
	return(i - 1);
}

void sub_sort(t_data *data)
{
	if(data->len == 2)
	{
		if(data->b->num > data->b->next->num)
			sx(&(data->b), 'b');
	}
	else
		sort_three(&(data->b), data, 'b');
	while(data->b)
	{
		px(&(data->b), &(data->a), 'b');
		if(data->a->order == data->next)
		{
			rx(&(data->a), 'a');
			data->next++;
		}
	}
}

int divide_b(t_data *data)
{
	int i = 0;

	data->len = lst_len(data->b);
	data->turn++;
	if(data->len == 2 || data->len == 3)
	{
		sub_sort(data);
		return (0);
	}
	data->max = data->mid;
	data->mid = (data->max - data->next) / 2 + data->next;
	while(i++ < data->len)
	{
		if(data->b->order == data->next)
		{
			data->b->turn = data->turn;
			px(&(data->b), &(data->a), 'a');
			rx(&(data->a), 'a');
			data->next++;
		}
		else if(data->b->order >= data->mid)
		{
			data->b->turn = data->turn;
			px(&(data->b), &(data->a), 'a');
		}
		else
			rx(&(data->b), 'b');
	}
	return(i - 1);
}
int re_turn(t_data *data)
{
	int lim;

	lim = data->a->turn;
	while(data->a->turn == lim)
	{
		if(data->a->order == data->next)
		{
			data->next++;
			rx(&(data->a), 'a');
		}
		else
			px(&(data->a), &(data->b), 'b');
	}
	// ft_printf("\nstack a:\n\n");
	// print_list(data->a);
	// ft_printf("\nstack b:\n\n");
	// print_list(data->b);
	// ft_printf("\nnext %d\n", data->next);
	return(lim);
}

int sort_cycle(t_data *data)
{
	divide_b(data);
	while(data->a->turn || data->b)
	{
		while(data->b)
			divide_b(data);
		if(data->a->turn && data->a->order >= data->next)
			re_turn(data);
		if(list_sorted(data))
			return (1);
	}
	return(0);
}

int check_bottom(t_data *data)
{
	t_list *ptr;

	ptr = data->a;
	while(ptr->next)
		ptr = ptr->next;
	while(ptr->order > data->next)
	{
		ptr = ptr->prev;
		rrx(&(data->a), 'a');
	}
	return(0);
}

int list_sorted(t_data *data)
{
	t_list *ptr;

	if(data->b)
		return(0);
	ptr = data->a;
	while(ptr->next)
	{
		if(ptr->next->num < ptr->num)
			return(0);
		ptr = ptr->next;
	}
	ft_printf("\nSorted!\n\n");
	return(1);
}

int main_sort(t_data *data)
{
	int res = 0;

	while(!res)
	{
		init_push(data);
		if(data->a->order < data->next)
			check_bottom(data);
		// ft_printf("\nstack a:\n\n");
		// print_list(data->a);
		// ft_printf("\nstack b:\n\n");
		// print_list(data->b);
		// ft_printf("\nnext %d\n", data->next);
		res = sort_cycle(data);
	}
	return(0);
}