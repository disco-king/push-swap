#include "ft_printf.h"

int	num_length(long long i)
{
	int	ret;

	ret = 0;
	if (!i)
		return (1);
	if (i < 0)
		ret++;
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

void	get_asters(t_conv *convers)
{
	if (convers -> aster_w)
	{
		convers -> width = va_arg(convers -> vars, int);
		if (convers -> width < 0)
		{
			convers -> width *= -1;
			convers -> minus = 1;
		}
	}
	if (convers -> aster_p)
	{
		convers -> precision = va_arg(convers -> vars, int);
		if (convers -> precision < 0)
			convers -> precision = -1;
	}
}

void	set_dimensions(long long number, int length, t_conv *conv)
{
	if (number < 0 && conv -> precision > (length - 1)
		&& conv -> type != 'x' && conv -> type != 'X')
	{
		conv -> width--;
		length--;
	}
	if (conv -> precision > length)
	{
		conv -> num_to_pad = (conv -> precision) - length;
		length = conv -> precision;
	}
	conv -> width = conv -> width - length;
}
