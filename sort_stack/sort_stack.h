#ifndef SORT_STACK_H
# define SORT_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_list
{
	int num;
	int order;
	int turn;
	struct s_list *next;
	struct s_list *prev;
}	t_list;

typedef struct	s_data
{
	int turn;
	int next;
	int len;
	int max;
	int mid;
	int curr_st;
	int *arr;
	t_list *a;
	t_list *b;
}	t_data;

int ft_printf(const char *, ...);
int	ft_atoi(const char *);
t_list *parce(char **, int **);

int *get_arr(t_list*);
void sort_arr(int *, int );
void print_arr(int *, int);
void assign_index(t_list *, int *);

t_list	*ft_lstnew(int);
void	ft_lstadd_back(t_list *, t_list *);
int		lst_len(t_list *);
t_list *print_list(t_list *);

void sx(t_list **, char c);
void rx(t_list **, char c);
void rrx(t_list **, char c);
void px(t_list **, t_list **, char c);

void sort_three(t_list **, t_data *data, char c);
void get_val(t_list *, t_data *);
void minimal(t_data *);

int init_push(t_data *);
int main_sort(t_data *);
int sort_cycle(t_data *);
int divide_b(t_data *);
int re_turn(t_data *);
int list_sorted(t_data *);

#endif
