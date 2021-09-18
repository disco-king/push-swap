/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:29:42 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/18 12:39:46 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_false(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57))
			i++;
		else

			return (1);
	}
	return (0);
}

int	str_check_false(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57))
			i++;
		else if (str[i] == 32)
			break ;
		else
			return (1);
	}
	return (0);
}

t_list *clear_exit(t_list *list, int flag)
{
	if(!list)
		error_exit(0, NULL);
	while (list->next)
	{
		list = list->next;
		free(list->prev);
		list->prev = NULL;
	}
	free(list);
	list = NULL;
	if (!flag)
		error_exit(0, NULL);
	return (list);
}

void	error_exit(int flag, char *val)
{
	if (flag)
	{
		if (val && check_false(val))
			return ;
		exit(0);
	}
	else
		ft_printf("Error\n");
	exit(0);
}

t_list	*check_args(t_list *list, int *flag)
{
	t_list *ptr;
	
	ptr = list;
	*flag = 0;
	if (check_dups(list))
		clear_exit(list, 0);
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (list);
		ptr = ptr->next;
	}
	*flag = 1;
	return(clear_exit(list, 1));
}
