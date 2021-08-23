#include "sort_stack.h"

void get_val(t_list *stack, int *max, int *min)
{
	int i;
	int b;
	int s;

	*max = 0;
	*min = *max;
	b = stack->num;
	s = b;
	i = 1;
	stack = stack->next;
	while(stack)
	{
		if(b < stack->num)
		{
			b = stack->num;
			*max = i;
		}
		if(s > stack->num)
		{
			s = stack->num;
			*min = i;
		}
		i++;
		stack = stack->next;
	}
}

void sort_three(t_list **stack)
{
	int max;
	int min;

	get_val(*stack, &max, &min);
	// ft_printf("min %d\tmax %d\n", min, max);
	if (min == 0 && max == 1)
	{
		sx(stack);
		rx(stack);
	}
	else if (max == 0)
	{
		if (min == 2)
		{
			rx(stack);
			sx(stack);
		}
		else
			rx(stack);
	}
	else if (max == 2 && min != 0)
	{
		if (max == 2)
			sx(stack);
		else
			rrx(stack);
	}
}

void minimal(t_list **st_a, t_list **st_b, t_data *data)
{
	int max, min;

	get_val(*st_a, &max, &min);
	if(lst_len(*st_a) == 2 && max == 0)
		sx(st_a);
	else if(lst_len(*st_a) == 3)
		sort_three(st_a);
	else if(lst_len(*st_a) == 4)
	{
		while(min && min != 3)
		{
			rx(st_a);
			get_val(*st_a, &max, &min);
		}
		if(min)
			rrx(st_a);
		ft_printf("pb ");
		px(st_a, st_b);
		sort_three(st_a);
		ft_printf("pa ");
		px(st_b, st_a);
	}
	else if (lst_len(*st_a) == 5)
	{
		while(min && min != 4)
		{
			rx(st_a);
			get_val(*st_a, &max, &min);
		}
		if(min)
			rrx(st_a);
		ft_printf("pb ");
		px(st_a, st_b);
		minimal(st_a, st_b, data);
		ft_printf("pa ");
		px(st_b, st_a);
	}
}