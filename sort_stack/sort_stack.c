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

void get_val(t_list *stack, int *max, int *min)
{
	int i;
	int b;
	int s;

	*max = 0;
	*min = *max;
	b = stack->num;
	s = b;
	i = 1;
	stack = stack->next;
	while(stack)
	{
		if(b < stack->num)
		{
			b = stack->num;
			*max = i;
		}
		if(s > stack->num)
		{
			s = stack->num;
			*min = i;
		}
		i++;
		stack = stack->next;
	}
}

void sort_three(t_list **stack)
{
	int max;
	int min;

	get_val(*stack, &max, &min);
	ft_printf("min %d\tmax %d\n", min, max);
	if (min == 0)
	{
		if (max == 1)
		{
			sx(stack);
			rx(stack);
		}
	}
	else if (max == 0)
	{
		if (min == 2)
		{
			rx(stack);
			sx(stack);
		}
		else
			rx(stack);
	}
	else
	{
		if (max == 2)
			sx(stack);
		else
			rrx(stack);
	}
}

int main (int argc, char **argv)
{
	t_list *st_a;
	int *arr;
	if (argc >= 2)
	{
		st_a = parce(argv[1], &arr);
	}
	else
	{
		printf("giv args pls\n");
		exit(0);
	}
	print_list(st_a);
	int count = lst_len(st_a);
	ft_printf("lst len %d\n", count);
	if (count == 3)
		sort_three(&st_a);
	print_list(st_a);
	while(1);
	return(0);
}