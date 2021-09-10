/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:26:15 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/02 17:41:55 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *num)
{
	long	res;
	int		buff;
	int		sign;

	res = 0;
	sign = 0;
	if (*num == '+')
		num++;
	else if (*num == '-')
	{
		sign = 1;
		num++;
	}
	while (*num)
	{
		if (*num > 57 || *num < 48)
			break ;
		buff = *num - '0';
		res = res * 10 + buff;
		num++;
	}
	if (sign)
		return (-res);
	return (res);
}

int	check_dups(t_list *list)
{
	t_list *ptr;

	list = list->next;
	while (list)
	{
		ptr = list->prev;
		while (ptr)
		{
			if (ptr->num == list->num)
				return (1);
			ptr = ptr->prev;
		}
		list = list->next;
	}
	return (0);
}

void    check_list(t_list *list)
{
    if (list)
        return ;
    error_exit(0, NULL);
}

void	init_data(t_data *data, t_list *st_a)
{
	data->up = 0;
	data->a = st_a;
	data->b = NULL;
	data->len = lst_len(st_a);
	data->min = smallest_num(st_a);
}

void print_list(t_list *list, char c)
{
	ft_printf("PRINTING %c\n", c);
	while(list)
	{
		ft_printf("num %d\n", list->num);
		list = list->next;
	}
	ft_printf("\n");
}
