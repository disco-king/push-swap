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
	// ft_printf("PUSHING\n");
	while (lst_len(data->a) > 5)
	{
		if (data->a->num == data->min)
			rx(&(data->a), 'a');
		else
			px(&(data->a), &(data->b), 'b');
	}
	minimal(data);
	// print_list(data->a, 'A');
	// print_list(data->b, 'B');
	// ft_printf("\nPUSHED\n\n");
	data->min = smallest_num(data->a);
}

void	move_item(t_data *data, int a_order)
{
	modif_a(&(data->a), a_order);
	if (data->up)
		while (data->b->num != data->to_move)
			rx(&(data->b), 'b');
	else
		while (data->b->num != data->to_move)
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
			+ a_moves(data, data->a, ptr->num);
		if (data->moves < min)
		{
			// ft_printf("num %d moves %d\n", ptr->num, data->moves);
			data->to_move = ptr->num;
			a_order = data->a_order;
			min = data->moves;
			data->up = 0;
			if (dep <= lst_len(data->b) / 2 + 1)
				data->up = 1;
		}
		dep++;
		ptr = ptr->next;
	}
	// ft_printf("MOVING\n");
	move_item(data, a_order);
	// print_list(data->a, 'A');
	// print_list(data->b, 'B');
	// ft_printf("\nMOVED\n\n");
}

int sorted(t_data *data)
{
	if (data->b)
	{
		ft_printf("B not empty!\n");
		return(0);
	}
	t_list *ptr = data->a;
	while(ptr->next)
	{
		if(ptr->num > ptr->next->num)
		{	
			ft_printf("A not sorted!\n");
			return(0);
		}
		ptr = ptr->next;
	}
	return (1);
}

void	main_sort(t_data *data)
{
	// ft_printf("INITIAL\n");
	// print_list(data->a, 'A');
	// print_list(data->b, 'B');
	// ft_printf("\n\n");
	init_push(data);
	while (data->b)
	{
		push_next(data);
	}
	scroll(&(data->a), data);
	// if(sorted(data))
	// 	ft_printf("SORTED\n");
    clear_exit(data->a, 1);
}
