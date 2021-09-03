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

int	check_dups(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < i)
		{
			if (arr[j] == arr[i])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	*get_arr(t_list *list)
{
	int	i;
	int	count;
	int	*arr;

	i = 0;
	count = lst_len(list);
	arr = malloc(sizeof(int) * count);
    if (!arr)
        return (arr);
	while (i < count)
	{
		arr[i] = list->num;
		i++;
		list = list->next;
	}
	return (arr);
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
	data->max = data->len;
	data->min = 1;
}
