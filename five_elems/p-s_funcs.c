#include "sort_stack.h"

void sx(t_list **list, char c)
{
	t_list *ptr;

	if(!(*list)->next || (*list)->prev)
	{
		ft_printf("not the first list item\n");
		return ;
	}
	ptr = (*list)->next;
	(*list)->next = ptr->next;
	if((*list)->next)
		(*list)->next->prev = *list;
	(*list)->prev = ptr;
	ptr->prev = NULL;
	ptr->next = *list;
	*list = ptr;
	ft_printf("s%c\n", c);
}

void rx(t_list **list, char c)
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
	ft_printf("r%c\n", c);
}

void rrx(t_list **list, char c)
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
	ft_printf("rr%c\n", c);
}

void px(t_list **list, t_list **dest, char c)
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
		ft_printf("p%c\n", c);
		return ;
	}
	(*dest)->prev = ptr;
	(*dest)->prev->next = *dest;
	*dest = (*dest)->prev;
	(*dest)->prev = NULL;
	ft_printf("p%c\n", c);
}