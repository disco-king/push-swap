#include "sort_stack.h"

int init_push(t_data *data)
{
	int i = 0;
	
	data->mid = data->max / 2 + data->next;
	data->len = lst_len(data->a);
	while(i++ < data->len && !data->a->turn)
	{
		if(data->a->order <= data->mid)
		{
			ft_printf("pushing %d order %d\n", data->a->num, data->a->order);
			px(&(data->a), &(data->b));
		}
		else
		{
			ft_printf("reverse %d order %d\n", data->a->num, data->a->order);
			rx(&(data->a));
		}
	}
	return(i - 1);
}

int divide_b(t_data *data)
{
	int i = 0;
	
	data->len = lst_len(data->b);
	data->max = data->mid;
	data->mid = (data->max - data->next) / 2 + data->next;
	data->turn++;
	while(i++ < data->len)
	{
		if(data->b->order >= data->mid)
		{
			ft_printf("pushing %d order %d\n", data->b->num, data->b->order);
			data->b->turn = data->turn;
			ft_printf("pa ");
			px(&(data->b), &(data->a));
			if(data->a->order == data->next)
			{
				rx(&(data->a));
				data->next++;
			}
		}
		else
		{
			ft_printf("reverse %d order %d\n", data->b->num, data->b->order);
			rx(&(data->b));
		}
	}
	return(i - 1);
}

int re_turn(t_data *data)
{
	int lim;

	lim = data->a->turn;
	while(data->a->turn == lim)
	{
		if(data->a->order == data->next)
		{
			data->next++;
			rx(&(data->a));
		}
		else
		{
			ft_printf("pb ");
			px(&(data->a), &(data->b));
		}
	}
	return(lim);
}

int sort_cycle(t_data *data)
{
	divide_b(data);
	divide_b(data);
	// while(data->a->turn)//won't come in at first; gotta work around that
	// {
	// 	while(data->b)
	// 		divide_b(data);
	// 	re_turn(data);
	// }
}

int main_sort(t_data *data)
{
	init_push(data);
	sort_cycle(data);
}