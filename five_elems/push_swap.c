/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:47:22 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/02 18:20:06 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse(char **nums, int **arr)
{
	t_list	*start;
	long	buff;
	int		i;

	i = 1;
	start = NULL;
	while (nums[i])
	{
		if (check_false(nums[i]))
			return (clear_exit(start));
		buff = ft_atoi(nums[i]);
		if (buff > MAX || buff < MIN)
			return (clear_exit(start));
		if (!start)
			start = ft_lstnew(buff);
		else
			ft_lstadd_back(start, ft_lstnew(buff));
        check_list(start);
		i++;
	}
	*arr = get_arr(start);
	start = check_args(start, *arr, i - 1, &i);
	if (i)
		error_exit(i, NULL);
	return (start);
}

void	get_nums(char *nums, t_list **start)
{
	int	i;
	int	buff;

	i = 0;
	while (nums[i])
	{
		if (str_check_false(&nums[i]))
		{
			clear_exit(*start);
			error_exit(0, NULL);
		}
		if ((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
		{
			buff = ft_atoi(&(nums[i]));
			if (!(*start))
				*start = ft_lstnew(buff);
			else
				ft_lstadd_back(*start, ft_lstnew(buff));
            check_list(start);
			while ((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
				i++;
			continue ;
		}
		i++;
	}
}

t_list	*str_parse(char *nums, int **arr)
{
	t_list	*start;
	int		i;

	start = NULL;
	get_nums(nums, &start);
	*arr = get_arr(start);
	i = lst_len(start);
	start = check_args(start, *arr, i, &i);
	if (i)
		error_exit(i, NULL);
	return (start);
}

void	sort_arr(int *arr, int len)
{
	int	i;
	int	buff;
	int	alrm ;

	alrm = 1;
	while (alrm)
	{
		alrm = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				alrm = 1;
				buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
			}
			i++;
		}
	}
}

void	assign_index(t_list *list, int *arr)
{
	int	i;
	int	len;

	i = 0;
	len = lst_len(list);
	while (list)
	{
		while (i < len)
		{
			if (arr[i] == list->num)
			{
				list->order = i + 1;
				list->turn = 0;
				i = 0;
				break ;
			}
			i++;
		}
		list = list->next;
	}
}
