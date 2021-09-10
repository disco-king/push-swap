#include "ft_printf.h"

void	out_ptr(unsigned long long number, int length, t_conv *conv)
{
	int	count;

	count = 0;
	if (conv -> minus)
	{
		conv -> printed += ft_putstr("0x");
		if (!(!number && conv -> dot))
			xd_putnbr(number, conv);
	}
	while (count++ < conv -> width - length)
		conv -> printed += ft_putchar(' ');
	if (!conv -> minus)
	{
		conv -> printed += ft_putstr("0x");
		if (!(!number && conv -> dot))
			xd_putnbr(number, conv);
	}
}

void	pr_pointer(t_conv *conv)
{
	unsigned long long	number;
	int					length;

	get_asters(conv);
	if (conv -> zero || conv -> precision != -1)
		return ;
	number = va_arg(conv -> vars, unsigned long long);
	length = xd_length(number) + 2;
	if (!number && conv -> dot)
		length--;
	out_ptr(number, length, conv);
}
