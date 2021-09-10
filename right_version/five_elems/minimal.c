/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:11:08 by fmalphit          #+#    #+#             */
/*   Updated: 2021/08/30 20:32:41 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_val(t_list *stack, t_data *data)
{
	int	i;
	int	max;
	int	min;

	data->max = 0;
	data->min = 0;
	max = stack->num;
	min = max;
	i = 1;
	stack = stack->next;
	while (stack)
	{
		if (max < stack->num)
		{
			max = stack->num;
			data->max = i;
		}
		if (min > stack->num)
		{
			min = stack->num;
			data->min = i;
		}
		i++;
		stack = stack->next;
	}
}

void	sort_three(t_list **stack, t_data *data, char c)
{
	get_val(*stack, data);
	if (data->min == 0 && data->max == 1)
	{
		sx(stack, c);
		rx(stack, c);
	}
	else if (data->max == 0)
	{
		if (data->min == 2)
		{
			rx(stack, c);
			sx(stack, c);
		}
		else
			rx(stack, c);
	}
	else if (data->min != 0)
	{
		if (data->max == 2)
			sx(stack, c);
		else
			rrx(stack, c);
	}
}

void	sort_five(t_data *data)
{
	while (data->min && data->min != 4)
	{
		rx(&(data->a), 'a');
		get_val(data->a, data);
	}
	if (data->min)
		rrx(&(data->a), 'a');
	px(&(data->a), &(data->b), 'b');
	minimal(data);
	px(&(data->b), &(data->a), 'a');
}

void	minimal(t_data *data)
{
	get_val(data->a, data);
	if (lst_len(data->a) == 2 && data->max == 0)
		sx(&(data->a), 'a');
	else if (lst_len(data->a) == 3)
		sort_three(&(data->a), data, 'a');
	else if (lst_len(data->a) == 4)
	{
		while (data->min && data->min != 3)
		{
			rx(&(data->a), 'a');
			get_val(data->a, data);
		}
		if (data->min)
			rrx(&(data->a), 'a');
		px(&(data->a), &(data->b), 'b');
		sort_three(&(data->a), data, 'a');
		px(&(data->b), &(data->a), 'a');
	}
	else if (lst_len(data->a) == 5)
		sort_five(data);
}
