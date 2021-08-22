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

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list *ptr = lst;
	
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

int *get_arr(char *nums, int count)
{
	int i = 0;
	int *arr = malloc(sizeof(int) * count);

	while(i < count)
	{
		if ((*nums <= 57 && *nums >= 48) || *nums == '-')
		{
			arr[i] = ft_atoi(nums);
			while((*nums <= 57 && *nums >= 48) || *nums == '-')
				nums++;
			i++;
			continue;
		}
		nums++;
	}
	return(arr);
}

t_list *parce(char *nums, int **arr)
{
	int buff;
	int i;
	int count;
	t_list *start;

	i = 0;
	start = NULL;
	count = 0;
	while(nums[i])
	{
		if ((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
		{
			buff = ft_atoi(&(nums[i]));
			if (!start)
				start = ft_lstnew(buff);
			else
				ft_lstadd_back(start, ft_lstnew(buff));
			while((nums[i] <= 57 && nums[i] >= 48) || nums[i] == '-')
				i++;
			count++;
			continue;
		}
		i++;
	}
	*arr = get_arr(nums, count);
	return(start);
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

void sort_arr(int *arr, int len)
{
	int i;
	int buff;
	int alrm = 1;

	while(alrm)
	{
		alrm = 0;
		i = 0;
		while(i < len-1)
		{
			if(arr[i] > arr[i + 1])
			{
				alrm = 1;
				buff = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = buff;
			}
			i++;
		}
	}
}

void print_arr(int *arr, int count)
{
	int i = -1;
	ft_printf("| ");
	while(++i < count)
		ft_printf("arr item %d is %d | ", i, arr[i]);
	ft_printf("\n");
}

int main (int argc, char **argv)
{
	t_list *start;
	int *arr;
	if (argc >= 2)
	{
		start = parce(argv[1], &arr);
	}
	else
	{
		printf("giv args pls\n");
		exit(0);
	}
	print_list(start);
	int count = lst_len(start);
	ft_printf("%d\n", count);
	print_arr(arr, count);
	sort_arr(arr, count);
	print_arr(arr, count);
	while(1);
	return(0);
}