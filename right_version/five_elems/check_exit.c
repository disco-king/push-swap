/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:29:42 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/02 18:20:18 by fmalphit         ###   ########.fr       */
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

t_list	*clear_exit(t_list *list)
{
	while (list->next)
	{
		list = list->next;
		free(list->prev);
		list->prev = NULL;
	}
	free(list);
	list = NULL;
	return (list);
}

void	error_exit(int flag, char *val)
{
	if (flag)
	{
		if (val && check_false(val))
			return ;
		ft_printf("\n");
	}
	else
		ft_printf("Error\n");
	exit(0);
}

t_list	*check_args(t_list *list, int *arr, int len, int *flag)
{
	int	i;

	i = 0;
	*flag = 0;
	if (!arr || check_dups(arr, len))
		return (clear_exit(list));
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (list);
		i++;
	}
	*flag = 1;
	return (clear_exit(list));
}
