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
	// ft_printf("b_moves %d\n", b_move);
	return (b_move);
}

int	a_moves(t_data *data, t_list *list, int num)
{
	long long	prox;
	int			i;
	int			dep;
	t_list		*ptr;

	dep = 0;
	i = 0;
	prox = VERY_BIG_NUM;
	ptr = list;
	while (list)
	{
		if (num - list->num > 0
			&& num - list->num < prox)
		{
			prox = num - list->num;
			dep = i;
			data->a_order = list->num;
		}
		i++;
		list = list->next;
	}
	// ft_printf("a moves len %d dep %d ", lst_len(ptr), dep);
	return (b_moves(lst_len(ptr), dep + 2));
}

void	scroll(t_list **list, t_data *data)
{
	t_list	*ptr;
	int		i;

	ptr = *list;
	i = 1;
	while (ptr->num != data->min)
	{
		i++;
		ptr = ptr->next;
	}
	if (i <= lst_len(*list) / 2 + 1)
		while ((*list)->num != data->min)
			rx(list, 'a');
	else
		while ((*list)->num != data->min)
			rrx(list, 'a');
}

void	modif_a(t_list **list, int num)
{
	t_list	*ptr;
	int		dep;

	ptr = *list;
	dep = 1;
	while (ptr->num != num)
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
