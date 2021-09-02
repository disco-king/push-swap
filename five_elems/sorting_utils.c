/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:48:41 by fmalphit          #+#    #+#             */
/*   Updated: 2021/08/30 20:31:36 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_moves(int len, int dep)
{
	int	b_move;

	b_move = len / 2 + 1;
	if (dep <= b_move)
		b_move = dep - 1;
	else
		b_move = len - dep + 1;
	return (b_move);
}

int	a_moves(t_data *data, t_list *list, int order)
{
	int	prox;
	int	len;
	int	i;
	int	dep;

	dep = 0;
	prox = data->len;
	len = lst_len(list);
	i = 0;
	while (list)
	{
		if (order - list->order > 0
			&& order - list->order < prox)
		{
			prox = order - list->order;
			dep = i;
			data->a_order = list->order;
		}
		i++;
		list = list->next;
	}
	return (b_moves(len, dep + 2));
}

void	scroll(t_list **list)
{
	t_list	*ptr;
	int		i;

	ptr = *list;
	i = 1;
	while (ptr->order != 1)
	{
		i++;
		ptr = ptr->next;
	}
	if (i <= lst_len(*list) / 2 + 1)
		while ((*list)->order != 1)
			rx(list, 'a');
	else
		while ((*list)->order != 1)
			rrx(list, 'a');
}

void	modif_a(t_list **list, int order)
{
	t_list	*ptr;
	int		dep;

	ptr = *list;
	dep = 1;
	while (ptr->order != order)
	{
		ptr = ptr->next;
		dep++;
	}
	if (dep >= lst_len(*list) / 2 + 1)
		while (ptr->next)
			rrx(list, 'a');
	else
		while (ptr->next)
			rx(list, 'a');
}
