#include "ft_printf.h"

void	pr_ecision(long long number, t_conv *conv)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		number = -number;
		conv -> printed += ft_putchar('-');
	}
	if (conv -> num_to_pad)
		while (count++ < conv -> num_to_pad)
			conv -> printed += ft_putchar('0');
	if (!number && !conv -> precision)
	{
		if (conv -> width != -1)
			conv -> printed += ft_putchar(' ');
	}
	else if (conv -> type == 'x' || conv -> type == 'X')
		xd_putnbr (number, conv);
	else
		ft_putnbr(number, conv);
}

void	ft_dispatch(long long number, t_conv *conv)
{
	if (conv -> type == 'x' || conv -> type == 'X')
		xd_putnbr(number, conv);
	else
		ft_putnbr(number, conv);
}

void	out_num(long long number, t_conv *conv)
{
	int	count;

	count = 0;
	if (conv -> zero)
	{
		if (number < 0)
		{
			number = -number;
			conv -> printed += ft_putchar('-');
		}
		while (count++ < conv -> num_to_pad)
			conv -> printed += ft_putchar('0');
		ft_dispatch(number, conv);
	}
	else
	{
		if (conv -> minus)
			pr_ecision(number, conv);
		while (count++ < conv -> width)
			conv -> printed += ft_putchar(' ');
		if (!conv -> minus)
			pr_ecision(number, conv);
	}
}

void	pr_number(t_conv *conv)
{
	int	number;
	int	length;

	get_asters(conv);
	number = va_arg(conv -> vars, int);
	length = num_length(number);
	if ((conv -> minus) || conv -> precision != -1)
		conv -> zero = 0;
	else if (conv -> zero)
		conv -> num_to_pad = conv -> width - length;
	if (!conv -> zero)
		set_dimensions(number, length, conv);
	out_num(number, conv);
}

void	pr_unsign(t_conv *conv)
{
	unsigned int	number;
	int				length;

	get_asters(conv);
	number = va_arg(conv -> vars, unsigned int);
	length = num_length(number);
	if ((conv -> minus) || conv -> precision != -1)
		conv -> zero = 0;
	else if (conv -> zero)
		conv -> num_to_pad = conv -> width - length;
	if (!conv -> zero)
		set_dimensions(number, length, conv);
	out_num(number, conv);
}
