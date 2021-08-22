#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	int num;
	int uninit;
	struct s_list *next;
	struct s_list *prev;
}	t_list;


int ft_printf(const char *, ...);
int	ft_atoi(const char *);
t_list *parce(char *, int **);

int *get_arr(char *, int );
void sort_arr(int *, int );
void print_arr(int *, int);

t_list	*ft_lstnew(int);
void	ft_lstadd_back(t_list *, t_list *);
int		lst_len(t_list *);
t_list *print_list(t_list *);

void sx(t_list **);
void rx(t_list **);
void rrx(t_list **);
void px(t_list **, t_list **);

void sort_three(t_list **);
void get_val(t_list *, int *, int *);