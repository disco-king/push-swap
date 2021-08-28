#include "sort_stack.h"

t_list *print_list(t_list *ptr)
{
	if(!ptr)
		ft_printf("list empty\n");
	else if(!ptr->prev)
	{
		while(ptr->next)
		{
			ft_printf("way down %d", ptr->num);
			ft_printf(" order %d", ptr->order);
			ft_printf("\n");
			ptr = ptr->next;
		}
		ft_printf("last one %d", ptr->num);
		ft_printf(" order %d", ptr->order);
		ft_printf("\n\n");
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

t_list	*ft_lstnew(int content)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new->num = content;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list *ptr = lst;
	
	if(ptr->next)
		while(ptr->next)
			ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

int lst_len(t_list *ptr)
{
	int i;

	if (!ptr)
		return(0);
	// if (ptr->prev)
	// {
	// 	ft_printf("len not the first list item\n");
	// 	return(-1);
	// }
	i = 0;
	while(ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return(i);
}
