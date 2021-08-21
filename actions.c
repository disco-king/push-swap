#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int ft_printf(const char *, ...);

typedef struct	s_list
{
	int num;
	struct s_list *next;
	
}	t_list;

int	ft_atoi(const char *num)
{
	int		res;
	int		buff;
	int		sign;

	res = 0;
	sign = 0;
	if (*num == '-')
	{
		sign = 1;
		num++;
	}
	while (*num)
	{
		if (*num > 57 || *num < 48)
			break ;
		buff = *num - '0';
		res = res * 10 + buff;
		num++;
	}
	if (sign)
		return (-res);
	return (res);
}

int get_next_line(int fd, char **line)
{
	int i;
	int l;
	int r;
	char c;
	char *tmp;
	l = 1;
	if (!(*line = malloc(l)))
		return (-1);
	*line[0] = 0;
	while((r = read(fd, &c, 1)) && l++ && c != '\n')
	{
		if(!(tmp = malloc(l)))
		{
			free (*line);
			return (-1);
		}
		i = -1;
		while(++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free (*line);
		*line = tmp;
	}
	return(r);
}

t_list	*ft_lstnew(int content)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new -> num = content;
	new -> next = NULL;
	return(new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *ptr = *lst;
	
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*buff;

	if (lst == NULL)
		return (0);
	buff = lst;
	res = 1;
	while (buff -> next)
	{
		buff = buff -> next;
		res++;
	}
	return (res);
}

t_list *parce(char *nums)
{
	int buff;
	int i;
	int count;
	t_list *start;

	i = 0;
	start = malloc(sizeof(t_list *));
	start->next = NULL;
	count = 0;
	while(nums[i])
	{
		if ((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
		{
			buff = ft_atoi(&(nums[i]));
			if (!start->next)
				start->next = ft_lstnew(buff);
			else
				ft_lstadd_back(&start, ft_lstnew(buff));
			while((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
				i++;
			count++;
			continue;
		}
		i++;
	}
	return(start);
}

int print_list(t_list *start)
{
	t_list *ptr = start->next;
	int i = 0;
	while(ptr->next)
	{
		ft_printf("lst[%d] = %d; ", i, ptr->num);
		i++;
		ptr = ptr->next;
	}
	ft_printf("lst[%d] = %d;\n", i, ptr->num);
	return(++i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	while (!res)
	{
		if(!s1[count] && !s2[count])
			return(res);
		res = s1[count] - s2[count];
		count++;
	}
	return (res);
}

int ft_sx(t_list **start)
{
	t_list *ptr;
	ptr = (*start)->next;
	if (!ptr->next)
	{
		ft_printf("sx fail\nlist too short\n");
		return (0);
	}
	(*start)->next = ptr->next;
	ptr->next = (*start)->next->next;
	(*start)->next->next = ptr;
	return (1);
}

int ft_rx(t_list **start)
{
	t_list *ptr;
	ptr = (*start)->next;
	if (!ptr->next)
	{
		ft_printf("rx fail\nlist too short\n");
		return (0);
	}
	while(ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = (*start)->next;
	(*start)->next = ptr->next;
	ptr->next = NULL;
	return (1);
}

void do_command(char *command, t_list **start)
{
	if (!(ft_strcmp(command, "sx")))
	{
		ft_printf("getting there\n");
		ft_sx(start);
	}
	if (!(ft_strcmp(command, "rx")))
	{
		ft_printf("getting there\n");
		ft_rx(start);
	}
}

int main (int argc, char **argv)
{
	t_list *start;
	char *command;
	if (argc >= 2)
	{
		start = parce(argv[1]);
	}
	else
	{
		printf("giv args pls\n");
		exit(0);
	}
	print_list(start);
	int r = 0;
	while ((r = get_next_line(0, &command)) > 0)
    {
		ft_printf("%s\n", command);
		do_command(command, &start);
		print_list(start);
		free(command);
		command = NULL;
	}
	ft_printf("%s", command);
	free(command);
    command = NULL;
	return(0);
}
