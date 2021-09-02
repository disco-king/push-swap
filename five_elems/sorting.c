/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:18:32 by marvin            #+#    #+#             */
/*   Updated: 2021/09/02 17:37:56 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push(t_data *data)
{
	while (lst_len(data->a) > 5)
	{
		if (data->a->order == data->min
			|| data->a->order == data->max)
			rx(&(data->a), 'a');
		else
			px(&(data->a), &(data->b), 'b');
	}
	minimal(data);
}

void	move_item(t_data *data, int a_order)
{
	modif_a(&(data->a), a_order);
	if (data->up)
		while (data->b->order != data->to_move)
			rx(&(data->b), 'b');
	else
		while (data->b->order != data->to_move)
			rrx(&(data->b), 'b');
	px(&(data->b), &(data->a), 'a');
}

void	push_next(t_data *data)
{
	int		dep;
	int		a_order;
	int		min;
	t_list	*ptr;

	ptr = data->b;
	min = BIG_NUM;
	dep = 1;
	while (ptr)
	{
		data->moves = b_moves(lst_len(data->b), dep)
			+ a_moves(data, data->a, ptr->order);
		if (data->moves < min)
		{
			data->to_move = ptr->order;
			a_order = data->a_order;
			min = data->moves;
			data->up = 0;
			if (dep <= lst_len(data->b) / 2 + 1)
				data->up = 1;
		}
		dep++;
		ptr = ptr->next;
	}
	move_item(data, a_order);
}

void	main_sort(t_data *data, int *arr)
{
	assign_index(data->a, arr);
	init_push(data);
	while (data->b)
	{
		push_next(data);
	}
	scroll(&(data->a));
}
