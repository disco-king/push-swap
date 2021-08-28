//option 1

void sub_sort(t_data *data)
{
	if(data->len == 2)
	{
		if(data->b->num > data->b->next->num)
			sx(&(data->b), 'b');
	}
	else
		sort_three(&(data->b), data);
	while(data->b)
	{
		px(&(data->b), &(data->a), 'b');
		if(data->a->order == data->next)
		{
			rx(&(data->a), 'a');
			data->next++;
		}
	}
}

int divide_b(t_data *data)
{
	int i = 0;

	data->len = lst_len(data->b);
	data->turn++;
	if(data->len == 2 || data->len == 3)
	{
		sub_sort(data);
		return (0);
	}
	data->max = data->mid;
	data->mid = (data->max - data->next) / 2 + data->next;
	while(i++ < data->len)
	{
		if(data->b->order == data->next)
		{
			data->b->turn = data->turn;
			px(&(data->b), &(data->a), 'a');
			rx(&(data->a), 'a');
			data->next++;
		}
		else if(data->b->order >= data->mid)
		{
			data->b->turn = data->turn;
			px(&(data->b), &(data->a), 'a');
		}
		else
			rx(&(data->b), 'b');
	}
	return(i - 1);
}

//option 2, fastest

int divide_b(t_data *data)
{
	int i = 0;

	data->len = lst_len(data->b);
	data->turn++;
	data->max = data->mid;
	data->mid = (data->max - data->next) / 2 + data->next;
	while(i++ < data->len)
	{
		if(data->b->order == data->next)
		{
			data->b->turn = data->turn;
			px(&(data->b), &(data->a), 'a');
			rx(&(data->a), 'a');
			data->next++;
		}
		else if(data->b->order >= data->mid)
		{
			data->b->turn = data->turn;
			px(&(data->b), &(data->a), 'a');
		}
		else
			rx(&(data->b), 'b');
	}
	return(i - 1);
}

