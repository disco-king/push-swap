#include <stdlib.h>
#include <stdio.h>

int ft_printf(const char *, ...);

typedef struct	s_list
{
	int num;
	int uninit;
	struct s_list *next;
	struct s_list *prev;
}	t_list;

t_list	*ft_lstnew(int content)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new->num = content;
	new->uninit = 0;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

int lst_len(t_list *ptr)
{
	int i;

	if (!ptr)
		return(0);
	if (ptr->prev)
	{
		printf("len not the first list item\n");
		return(-1);
	}
	i = 0;
	while(ptr && !ptr->uninit)
	{
		i++;
		ptr = ptr->next;
	}
	return(i);
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
	if(!ptr)
		ft_printf("list empty\n");
	else if(!ptr->prev)
	{
		while(ptr->next)
		{
			ft_printf("way down %d\n", ptr->num);
			ptr = ptr->next;
		}
		ft_printf("last one %d\n\n", ptr->num);
	}
	else if(!ptr->next)
	{
		while(ptr->prev)
		{
			ft_printf("way up   %d\n", ptr->num);
			ptr = ptr->prev;
		}
		ft_printf("last one %d\n\n", ptr->num);
	}
	return(ptr);
}

void sx(t_list **list)
{
	t_list *ptr;

	if(!(*list)->next || (*list)->prev)
	{
		ft_printf("not the first list item\n");
		return ;
	}
	ptr = (*list)->next;
	(*list)->next = ptr->next;
	(*list)->next->prev = *list;
	(*list)->prev = ptr;
	ptr->prev = NULL;
	ptr->next = *list;
	*list = ptr;
}

void rx(t_list **list)
{
	t_list *ptr;

	ptr = *list;
	if(!(*list)->prev)
		while(ptr->next)
			ptr = ptr->next;
	else
	{
		ft_printf("not the first list item\n");
		return ;
	}
	ptr->next = *list;
	(*list)->prev = ptr;
	ptr = (*list)->next;
	(*list)->next->prev = NULL;
	(*list)->next = NULL;
	*list = ptr;
}

void rrx(t_list **list)
{
	t_list *ptr;

	ptr = *list;
	if(!(*list)->prev)
		while(ptr->next)
			ptr = ptr->next;
	else
	{
		ft_printf("not the first list item\n");
		return ;
	}
	(*list)->prev = ptr;
	ptr->next = (*list);
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	*list = ptr;
}

void px(t_list **list, t_list **dest)
{
	t_list *ptr;

	ptr = *list;

	if(ptr->prev)
	{
		ft_printf("not the first list item\n");
		return ;
	}

	*list = (*list)->next;
	if(*list)
		(*list)->prev = NULL;
	
	if(!(*dest))
	{
		*dest = ptr;
		(*dest)->next = NULL;
		(*dest)->prev = NULL;
		return ;
	}
	(*dest)->prev = ptr;
	(*dest)->prev->next = *dest;
	*dest = (*dest)->prev;
	(*dest)->prev = NULL;
}


int main()
{
	t_list *ptr_a;
	t_list *ptr_b;
	int i = 1;

	ptr_a = ft_lstnew(i);
	// ptr_a = NULL;
	ptr_b = NULL;
	while (i < 5)
	{
		i++;
		ft_lstadd_back(ptr_a, ft_lstnew(i));
	}

	while(lst_len(ptr_a))
	{
		px(&ptr_a, &ptr_b);
	}
	printf("|b check|\nlen %d\n\n", lst_len(ptr_b));
	ptr_b = print_list(ptr_b);
	ptr_b = print_list(ptr_b);
	while(1);
	return(0);
}