/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:54:47 by fmalphit          #+#    #+#             */
/*   Updated: 2021/08/30 20:31:10 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*ptr;

    if (!new)
		clear_exit(lst, 0);
	ptr = lst;
	if (ptr->next)
		while (ptr->next)
			ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

int	lst_len(t_list *ptr)
{
	int	i;

	if (!ptr)
		return (0);
	if (ptr->prev)
		while (ptr->prev)
			ptr = ptr->prev;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
