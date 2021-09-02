/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:43:31 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/02 18:08:33 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*st_a;
	t_data	data;
	int		*arr;

	if (argc <= 2)
	{
		if (argc == 1)
			error_exit(1, NULL);
		error_exit(1, argv[1]);
		st_a = str_parse(argv[1], &arr);
	}
	else
		st_a = parse(argv, &arr);
	if (!st_a)
		error_exit(0, NULL);
	init_data(&data, st_a);
	sort_arr(arr, data.len);
	if (data.len < 6)
	{
		minimal(&data);
		exit(0);
	}
	main_sort(&data, arr);
	return (0);
}
