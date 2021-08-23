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
				i = 0;
				break ;
			}
			i++;
		}
		list = list->next;
	}
}

void init_data(t_data *data, t_list **st_a, int *arr)
{
	data->turn = 1;
	data->next = 1;
	data->a = *st_a;
	data->max = lst_len(*st_a);
	data->curr_st = 0;
	data->len = data->max;
}

int main (int argc, char **argv)
{
	t_list *st_a;
	t_list *st_b;
	t_data *data = (t_data*)malloc(sizeof(t_data *));
	int *arr;

	st_b = NULL;
	if (argc >= 2)
	{
		st_a = parce(argv[1], &arr);
	}
	else
	{
		ft_printf("giv args pls\n");
		exit(0);
	}
	int count = lst_len(st_a);
	sort_arr(arr, count);
	init_data(data, &st_a, arr);
	if(data->len < 6)
	{
		minimal(&st_a, &st_b, data);
		print_list(st_a);
	}
	big_sort(data, arr);
	// print_arr(arr, count);
	// assign_index(st_a, arr);
	// while (st_a)
	// {
	// 	ft_printf("list item %d\torder %d\n", st_a->num, st_a->order);
	// 	st_a = st_a->next;
	// }
	return(0);
}