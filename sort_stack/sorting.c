#include "sort_stack.h"

int check_reverse(t_data *data)
{
	t_list *ptr;

	ptr = data->a;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr->order == data->a->order - 1)
	{
		data->next++;
		rx(&(data->a), 'a');
		return(1);
	}
	return(0);
}

int init_push(t_data *data)
{
	int i = 0;
	
	if(data->turn != 0)
		data->mid = data->max / 2 + data->next;
	else
		data->mid = (data->max - data->next) / 2 + data->next;
	data->len = lst_len(data->a);
	while(i++ < data->len && data->a->turn == 0)
	{
		if (data->turn != 0 && data->a->order == data->next)
			if(check_reverse(data))
				continue;
		if(data->a->order <= data->mid)
			px(&(data->a), &(data->b), 'b');
		else
			rx(&(data->a), 'a');
	}
	return(i - 1);
}

int divide_b(t_data *data)
{
	int i = 0;

	data->len = lst_len(data->b);
	data->turn++;
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
	return(lim);
}

int sort_cycle(t_data *data)
{
	divide_b(data);
	while(data->a->turn != 0 || data->b)
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
		res = sort_cycle(data);
	}
	return(0);
}