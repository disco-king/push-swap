#include "sort_stack.h"

void get_val(t_list *stack, t_data *data)
{
	int i;
	int b;
	int s;

	data->max = 0;
	data->mid = 0;
	b = stack->num;
	s = b;
	i = 1;
	stack = stack->next;
	while(stack)
	{
		if(b < stack->num)
		{
			b = stack->num;
			data->max = i;
		}
		if(s > stack->num)
		{
			s = stack->num;
			data->mid = i;
		}
		i++;
		stack = stack->next;
	}
}

void sort_three(t_list **stack, t_data *data)
{
	get_val(*stack, data);
	if (data->mid == 0 && data->max == 1)
	{
		sx(stack);
		rx(stack);
	}
	else if (data->max == 0)
	{
		if (data->mid == 2)
		{
			rx(stack);
			sx(stack);
		}
		else
			rx(stack);
	}
	else if (data->max == 2 && data->mid != 0)
	{
		if (data->max == 2)
			sx(stack);
		else
			rrx(stack);
	}
}

void minimal(t_list **st_a, t_list **st_b, t_data *data)
{
	get_val(*st_a, data);
	if(lst_len(*st_a) == 2 && data->max == 0)
		sx(st_a);
	else if(lst_len(*st_a) == 3)
		sort_three(st_a, data);
	else if(lst_len(*st_a) == 4)
	{
		while(data->mid && data->mid != 3)
		{
			rx(st_a);
			get_val(*st_a, data);
		}
		if(data->mid)
			rrx(st_a);
		ft_printf("pb ");
		px(st_a, st_b);
		sort_three(st_a, data);
		ft_printf("pa ");
		px(st_b, st_a);
	}
	else if (lst_len(*st_a) == 5)
	{
		while(data->mid && data->mid != 4)
		{
			rx(st_a);
			get_val(*st_a, data);
		}
		if(data->mid)
			rrx(st_a);
		ft_printf("pb ");
		px(st_a, st_b);
		minimal(st_a, st_b, data);
		ft_printf("pa ");
		px(st_b, st_a);
	}
}