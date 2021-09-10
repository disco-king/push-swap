/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:47:22 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/03 15:19:12 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse(char **nums)
{
	t_list	*start;
	long	buff;
	int		i;

	i = 1;
	start = NULL;
	while (nums[i])
	{
		if (check_false(nums[i]))
			clear_exit(start, 0);
		buff = ft_atoi(nums[i]);
		if (buff > MAX || buff < MIN)
			clear_exit(start, 0);
		if (!start)
			start = ft_lstnew(buff);
		else
			ft_lstadd_back(start, ft_lstnew(buff));
		check_list(start);
		i++;
	}
	start = check_args(start, &i);
	if (i)
		error_exit(i, NULL);
	return (start);
}

void	get_nums(char *nums, t_list **start)
{
	int		i;
	long	buff;

	i = 0;
	while (nums[i])
	{
		if (str_check_false(&nums[i]))
			clear_exit(*start, 0);
		if ((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
		{
			buff = ft_atoi(&(nums[i]));
			if (buff > MAX || buff < MIN)
				clear_exit(*start, 0);
			if (!(*start))
				*start = ft_lstnew(buff);
			else
				ft_lstadd_back(*start, ft_lstnew(buff));
			check_list(*start);
			while ((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
				i++;
			continue ;
		}
		i++;
	}
}

t_list	*str_parse(char *nums)
{
	t_list	*start;
	int		i;

	start = NULL;
	get_nums(nums, &start);
	start = check_args(start, &i);
	if (i)
		error_exit(i, NULL);
	return (start);
}

int smallest_num(t_list *list)
{
	int ret;

	ret = list->num;
	list = list->next;
	while(list)
	{
		if (list->num < ret)
			ret = list->num;
		list = list->next;
	}
	return (ret);
}
