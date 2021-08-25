#include "sort_stack.h"

void get_val(t_list *stack, t_data *data)
{
	int i;
	int max;
	int min;

	data->max = 0;
	data->mid = 0;
	max = stack->num;
	min = max;
	i = 1;
	stack = stack->next;
	while(stack)
	{
		if(max < stack->num)
		{
			max = stack->num;
			data->max = i;
		}
		if(min > stack->num)
		{
			min = stack->num;
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
	else if (data->mid != 0)
	{
		if (data->max == 2)
			sx(stack);
		else
			rrx(stack);
	}
}

void minimal(t_data *data)
{
	get_val(data->a, data);
	if(lst_len(data->a) == 2 && data->max == 0)
		sx(&(data->a));
	else if(lst_len(data->a) == 3)
		sort_three(&(data->a), data);
	else if(lst_len(data->a) == 4)
	{
		while(data->mid && data->mid != 3)
		{
			rx(&(data->a));
			get_val(data->a, data);
		}
		if(data->mid)
			rrx(&(data->a));
		ft_printf("pb ");
		px(&(data->a), &(data->b));
		sort_three(&(data->a), data);
		ft_printf("pa ");
		px(&(data->b), &(data->a));
	}
	else if (lst_len(data->a) == 5)
	{
		while(data->mid && data->mid != 4)
		{
			rx(&(data->a));
			get_val(data->a, data);
		}
		if(data->mid)
			rrx(&(data->a));
		ft_printf("pb ");
		px(&(data->a), &(data->b));
		minimal(data);
		ft_printf("pa ");
		px(&(data->b), &(data->a));
	}
}