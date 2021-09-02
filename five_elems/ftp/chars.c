#include "ft_printf.h"

void	pr_char(t_conv *conv)
{
	int		count;
	char	c;

	count = 0;
	if (conv -> zero || conv -> precision > 0 || conv -> aster_p)
		return ;
	get_asters(conv);
	c = va_arg(conv -> vars, int);
	if (conv -> minus)
		conv -> printed += ft_putchar(c);
	while (count++ < conv -> width - 1)
		conv -> printed += ft_putchar(' ');
	if (!conv -> minus)
		conv -> printed += ft_putchar(c);
}

void	out_str(int length, t_conv *conv, char *str)
{
	int	count;

	count = 0;
	if (conv -> minus && str)
		while (count++ < length)
			conv -> printed += ft_putchar(*str++);
	count = 0;
	while (count++ < conv -> width)
		conv -> printed += ft_putchar(' ');
	count = 0;
	if (!conv -> minus && str)
		while (count++ < length)
			conv -> printed += ft_putchar(*str++);
}

void	pr_string(t_conv *conv)
{
	char	*str;
	int		length;

	if (conv -> zero)
		return ;
	get_asters(conv);
	str = va_arg(conv -> vars, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen_c(str, '\0');
	if (conv -> precision < length && conv -> precision >= 0)
		length = conv -> precision;
	conv -> width = conv -> width - length;
	out_str(length, conv, str);
}

void	pr_percent(t_conv *conv)
{
	int	count;

	count = 0;
	get_asters(conv);
	if (conv -> zero && !conv -> minus)
	{
		while (count++ < conv -> width - 1)
			conv -> printed += ft_putchar('0');
		conv -> printed += ft_putchar('%');
		return ;
	}
	if (conv -> minus)
		conv -> printed += ft_putchar('%');
	while (count++ < conv -> width - 1)
		conv -> printed += ft_putchar(' ');
	if (!conv -> minus)
		conv -> printed += ft_putchar('%');
}
