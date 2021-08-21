#include <stdlib.h>
#include <stdio.h>

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
	*arr = get_arr(nums, count);
	return(start);
}

int print_list(t_list *start)
{
	t_list *ptr = start->next;
	int i = 0;
	while(ptr->next)
	{
		ft_printf("%d\n", ptr->num);
		i++;
		ptr = ptr->next;
	}
	ft_printf("%d\n", ptr->num);
	return(++i);
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
	int count = print_list(start);
	print_arr(arr, count);
	sort_arr(arr, count);
	print_arr(arr, count);
	while(1);
	return(0);
}
