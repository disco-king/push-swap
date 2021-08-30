#include "sort_stack.h"

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

int *get_arr(t_list *list)
{
	int i = 0;
	int count = lst_len(list);
	int *arr = malloc(sizeof(int) * count);

	while(i < count)
	{
		arr[i] = list->num;
		i++;
		list = list->next;
	}
	return(arr);
}

int check_false(char *str)
{
	int i = 0;

	while(str[i])
	{
		if((str[i] >= 48 && str[i] <= 57)
			|| str[i] == '-' || str[i] == '+')
			i++;
		else
			return(1);
	}
	return(0);
}

t_list *clear_exit(t_list*list)
{
	while(list->next)
	{
		list = list->next;
		free(list->prev);
		list->prev = NULL;
	}
	free(list);
	list = NULL;
	return(list);
}

int check_dups(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < len)
	{
		while(j < i)
		{
			if(arr[j] == arr[i])
				return(1);
			j++;
		}
		j = 0;
		i++;
	}
	return(0);
}

t_list *check_args(t_list *list, int *arr, int len)
{
	int i;

	i = 0;
	if (check_dups(arr, len))
		return(clear_exit(list));
	while(i < len)
	{
		if (arr[i] > arr[i + 1])
			return(list);
		i++;
	}
	return(clear_exit(list));
}

t_list *parce(char **nums, int **arr)
{
	int buff;
	int i;
	// int count;
	t_list *start;

	i = 1;
	start = NULL;
	// count = 0;
	while(nums[i])
	{
		if(check_false(nums[i]))
			return (clear_exit(start));
		buff = ft_atoi(nums[i]);
		if (!start)
			start = ft_lstnew(buff);
		else
			ft_lstadd_back(start, ft_lstnew(buff));
		i++;
		// count++;
	}
	*arr = get_arr(start);
	return(check_args(start, arr, i));
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

void assign_index(t_list *list, int *arr)
{
	int i = 0;
	int len = lst_len(list);

	while(list)
	{
		while (i < len)
		{
			if (arr[i] == list->num)
			{
				list->order = i+1;
				list->turn = 0;
				i = 0;
				break ;
			}
			i++;
		}
		list = list->next;
	}
}

void init_data(t_data *data, t_list *st_a, int *arr)
{
	data->up = 0;
	data->a = st_a;
	data->b = NULL;
	data->len = lst_len(st_a);
	data->max = data->len;
	data->min = 1;
}

void error_exit(int code)
{
	if (code)
	{
		ft_printf("giv args pls\n");
		exit(0);
	}
	ft_printf("wrong input\n");
	exit(0);
}

int main (int argc, char **argv)
{
	t_list *st_a;
	t_data data;
	int *arr;

	if (argc > 2)
		st_a = parce(argv, &arr);
	else
		error_exit(1);
	if (!st_a)
		error_exit(0);
	int count = lst_len(st_a);
	sort_arr(arr, count);
	init_data(&data, st_a, arr);
	if(data.len < 6)
	{
		minimal(&data);
		print_list(data.a);
		exit(0);
	}
	if(sorted(&data))
	{
		ft_printf("ALREADY SORTED\n");
		exit(0);
	}
	assign_index(data.a, arr);
	main_sort(&data);
	// ft_printf("\nstack a:\n\n");
	// print_list(data.a);
	// ft_printf("\nstack b:\n\n");
	// print_list(data.b);
	return(0);
}
