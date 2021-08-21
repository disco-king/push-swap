#include <stdlib.h>
#include <stdio.h>

int ft_printf(const char *, ...);

typedef struct	s_list
{
	int num;
	struct s_list *next;
	struct s_list *prev;
}	t_list;

t_list	*ft_lstnew(int content)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new -> num = content;
	new -> next = NULL;
	new -> prev = NULL;
	return(new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list *ptr = lst;
	
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if(!(*lst))
		return ;
	new->next = *lst;
	*lst = new;
	new->next->prev = *lst;
}

t_list *print_list(t_list *ptr)
{
	if(!ptr->prev)
	{
		while(ptr->next)
		{
			ft_printf("way down %d\n", ptr->num);
			ptr = ptr->next;
		}
		ft_printf("last one %d\n", ptr->num);
	}
	else if(!ptr->next)
	{
		while(ptr->prev)
		{
			ft_printf("way up %d\n", ptr->num);
			ptr = ptr->prev;
		}
		ft_printf("last one %d\n", ptr->num);
	}
	return(ptr);
}

void sx(t_list **list)
{
	t_list *ptr;

	if(!(*list)->next || (*list)->prev)
		return ;
	ptr = (*list)->next;
	ft_printf("1. ptr num is %d\n", ptr->num);
	(*list)->next = ptr->next;
	(*list)->next->prev = *list;
	(*list)->prev = ptr;
	ft_printf("2. lstpr num is %d\n ", (*list)->prev->num);
	ft_printf("  lstcn num is %d\n ", (*list)->num);
	ft_printf("  lstnx num is %d\n", (*list)->next->num);
	ptr->prev = NULL;
	ptr->next = *list;
	*list = ptr;
}

int main()
{
	t_list *ptr;
	int i = 1;

	t_list *lst1 = ft_lstnew(i);
	while (i < 5)
	{
		i++;
		ft_lstadd_back(lst1, ft_lstnew(i));
	}
	ptr = lst1;
	print_list(ptr);
	sx(&ptr);
	print_list(ptr);
}