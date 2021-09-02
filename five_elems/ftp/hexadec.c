#include "ft_printf.h"

int	xd_length(unsigned long long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	pr_hexadec(t_conv *conv)
{
	unsigned int	number;
	int				length;

	get_asters(conv);
	number = va_arg(conv -> vars, unsigned int);
	length = xd_length(number);
	if ((conv -> minus) || conv -> precision != -1)
		conv -> zero = 0;
	else if (conv -> zero)
		conv -> num_to_pad = conv -> width - length;
	if (!conv -> zero)
		set_dimensions(number, length, conv);
	out_num(number, conv);
}
