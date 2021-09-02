/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p-s_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:55:00 by fmalphit          #+#    #+#             */
/*   Updated: 2021/08/30 20:31:18 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_list **list, char c)
{
	t_list	*ptr;

	ptr = (*list)->next;
	(*list)->next = ptr->next;
	if ((*list)->next)
		(*list)->next->prev = *list;
	(*list)->prev = ptr;
	ptr->prev = NULL;
	ptr->next = *list;
	*list = ptr;
	ft_printf("s%c\n", c);
}

void	rx(t_list **list, char c)
{
	t_list	*ptr;

	ptr = *list;
	if (!(*list)->prev)
		while (ptr->next)
			ptr = ptr->next;
	ptr->next = *list;
	(*list)->prev = ptr;
	ptr = (*list)->next;
	(*list)->next->prev = NULL;
	(*list)->next = NULL;
	*list = ptr;
	ft_printf("r%c\n", c);
}

void	rrx(t_list **list, char c)
{
	t_list	*ptr;

	ptr = *list;
	if (!(*list)->prev)
		while (ptr->next)
			ptr = ptr->next;
	(*list)->prev = ptr;
	ptr->next = (*list);
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	*list = ptr;
	ft_printf("rr%c\n", c);
}

void	px(t_list **list, t_list **dest, char c)
{
	t_list	*ptr;

	ptr = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	if (!(*dest))
	{
		*dest = ptr;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
		ft_printf("p%c\n", c);
		return ;
	}
	(*dest)->prev = ptr;
	(*dest)->prev->next = *dest;
	*dest = (*dest)->prev;
	(*dest)->prev = NULL;
	ft_printf("p%c\n", c);
}
