/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalphit <fmalphit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:20:23 by fmalphit          #+#    #+#             */
/*   Updated: 2021/09/02 17:37:32 by fmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define BIG_NUM 999999
# define MAX 2147483647
# define MIN -2147483648

typedef struct s_list
{
	int				num;
	int				order;
	int				turn;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	int		moves;
	int		up;
	int		to_move;
	int		a_order;
	int		len;
	int		max;
	int		min;
	int		dep;
	int		*arr;
	t_list	*a;
	t_list	*b;
}	t_data;

int		ft_printf(const char *a, ...);
long	ft_atoi(const char *a);
t_list	*parse(char **a, int **b);
t_list	*str_parse(char *a, int **b);
int		*get_arr(t_list*a);
void	sort_arr(int *a, int b);
void	assign_index(t_list *a, int *b);
t_list	*ft_lstnew(int a);
void	ft_lstadd_back(t_list *a, t_list *b);
int		lst_len(t_list *a);
void	sx(t_list **a, char b);
void	rx(t_list **a, char b);
void	rrx(t_list **a, char b);
void	px(t_list **a, t_list **b, char c);
void	sort_three(t_list **a, t_data *b, char c);
void	sort_five(t_data *a);
void	get_val(t_list *a, t_data *b);
void	minimal(t_data *a);
void	init_data(t_data *a, t_list *b);
void	init_push(t_data *a);
void	main_sort(t_data *a, int *b);
int		check_false(char *c);
int		str_check_false(char *str);
void	get_nums(char *a, t_list **b);
t_list	*clear_exit(t_list *a);
void	error_exit(int a, char *b);
t_list	*check_args(t_list *a, int *b, int c, int *d);
int		check_dups(int *a, int b);
int		b_moves(int a, int b);
int		a_moves(t_data *a, t_list *b, int c);
void	modif_a(t_list **a, int b);
void	scroll(t_list **a);
int		a_moves(t_data *a, t_list *b, int c);
int		b_moves(int a, int b);

#endif
