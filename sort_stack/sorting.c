#include "sort_stack.h"

int big_sort(t_data *data, int *arr)
{
	int i = 0;
	
	data->mid = data->max / 2 + data->next;
	data->len = lst_len(data->a);
	while(i++ < data->len)
	{
		if(data->a->order <= data->mid)
			px(&(data->a), &(data->b));
		else
			rx(&(data->a));
	}
	return(i - 1);
}