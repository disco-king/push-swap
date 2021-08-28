#include "sort_stack.h"

void init_push(t_data *data)
{
	while(lst_len(data->a) > 5)
	{
		if (data->a->order == data->min ||
			data->a->order == data->max)
			rx(&(data->a), 'a');
		else
			px(&(data->a), &(data->b), 'b');
	}
	minimal(data);
}

int b_moves(int len, int dep)
{
	int b_move = len/2 + 1;

	if (dep <= b_move)
		b_move = dep - 1;
	else
		b_move = len - dep + 1;
	return(b_move);
}

int a_moves(t_data *data, t_list *list, int order)
{
	int dep = 0;
	int prox = data->len;
	int len = lst_len(list);
	int i = 0;

	while(list)
	{
		if (order - list->order > 0 &&
			order - list->order < prox)
		{
			prox = order - list->order;
			dep = i;
			data->a_order = list->order;
		}
		i++;
		list = list->next;
	}
	return(b_moves(len, dep + 2));
}

int last_order(t_list *list)
{
	while(list->next)
		list = list->next;
	return(list->order);
}

void modif_a(t_list **list, int order)
{
	t_list *ptr = *list;
	int dep = 1;

	while(ptr->order != order)
	{
		ptr = ptr->next;
		dep++;
	}
	if (dep >= lst_len(*list)/2 + 1)
		while(last_order(*list) != order)
			rrx(list, 'a');
	else
		while(last_order(*list) != order)
			rx(list, 'a');
}

int sorted(t_data *data)
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

int push_next(t_data *data)
{
	int moves;
	int dep = 1;
	int a_order;
	int min = 999999;
	t_list *ptr = data->b;
	char c;

	data->to_move = data->len;
	while(ptr)
	{
		moves = b_moves(lst_len(data->b), dep);
		moves += a_moves(data, data->a, ptr->order);
		if(moves < min)
		{
			data->to_move = ptr->order;
			a_order = data->a_order;
			min = moves;
			data->up = 0;
			if(dep <= lst_len(data->b)/2 + 1)
				data->up = 1;
		}
		dep++;
		ptr = ptr->next;
	}
	modif_a(&(data->a), a_order);
	if(data->up)
		while(data->b->order != data->to_move)
			rx(&(data->b), 'b');
	else
		while(data->b->order != data->to_move)
			rrx(&(data->b), 'b');
	px(&(data->b), &(data->a), 'a');
	// ft_printf("\nPUSHED\n");
	// ft_printf("\nstack a:\n\n");
	// print_list(data->a);
	// ft_printf("\nstack b:\n\n");
	// print_list(data->b);
	return(0);
}

void scroll(t_list **list)
{
	t_list *ptr = *list;
	int i = 1;
	
	while(ptr->order != 1)
	{
		i++;
		ptr = ptr->next;
	}
	if(i <= lst_len(*list)/2 + 1)
		while((*list)->order != 1)
			rx(list, 'a');
	else
		while((*list)->order != 1)
			rrx(list, 'a');
}

int main_sort(t_data *data)
{
	init_push(data);
	// ft_printf("\nINITIAL\n");
	// ft_printf("\nstack a:\n\n");
	// print_list(data->a);
	// ft_printf("\nstack b:\n\n");
	// print_list(data->b);
	while(data->b)
	{
		push_next(data);
	}
	scroll(&(data->a));
	
	// if(sorted(data))
	// 	ft_printf("SORTED\n");
	// else
	// 	ft_printf("NOT SORTED\n");
	return(0);
}