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

void sort_three(t_list **stack, t_data *data, char c)
{
	get_val(*stack, data);
	if (data->mid == 0 && data->max == 1)
	{
		sx(stack, c);
		rx(stack, c);
	}
	else if (data->max == 0)
	{
		if (data->mid == 2)
		{
			rx(stack, c);
			sx(stack, c);
		}
		else
			rx(stack, c);
	}
	else if (data->mid != 0)
	{
		if (data->max == 2)
			sx(stack, c);
		else
			rrx(stack, c);
	}
}

void minimal(t_data *data)
{
	get_val(data->a, data);
	if(lst_len(data->a) == 2 && data->max == 0)
		sx(&(data->a), 'a');
	else if(lst_len(data->a) == 3)
		sort_three(&(data->a), data, 'a');
	else if(lst_len(data->a) == 4)
	{
		while(data->mid && data->mid != 3)
		{
			rx(&(data->a), 'a');
			get_val(data->a, data);
		}
		if(data->mid)
			rrx(&(data->a), 'a');
		px(&(data->a), &(data->b), 'b');
		sort_three(&(data->a), data, 'a');
		px(&(data->b), &(data->a), 'a');
	}
	else if (lst_len(data->a) == 5)
	{
		while(data->mid && data->mid != 4)
		{
			rx(&(data->a), 'a');
			get_val(data->a, data);
		}
		if(data->mid)
			rrx(&(data->a), 'a');
		px(&(data->a), &(data->b), 'b');
		minimal(data);
		px(&(data->b), &(data->a), 'a');
	}
}