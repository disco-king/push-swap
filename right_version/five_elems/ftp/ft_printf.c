#include "ft_printf.h"

void	clear_struct(t_conv *convers)
{
	convers -> type = 0;
	convers -> end = 0;
	convers -> minus = 0;
	convers -> zero = 0;
	convers -> width = 0;
	convers -> dot = 0;
	convers -> precision = -1;
	convers -> aster_w = 0;
	convers -> aster_p = 0;
	convers -> num_to_pad = 0;
}

int	ft_convs(const char *str, int pos, t_conv *convers)
{
	if (str[pos] == 'i' || str[pos] == 'd')
		pr_number(convers);
	if (str[pos] == 'c')
		pr_char(convers);
	if (str[pos] == 's')
		pr_string(convers);
	if (str[pos] == 'p')
		pr_pointer(convers);
	if (str[pos] == '%')
		pr_percent(convers);
	if (str[pos] == 'x' || str[pos] == 'X')
		pr_hexadec(convers);
	if (str[pos] == 'u')
		pr_unsign(convers);
	return (0);
}

int	check_percent(const char *str, int pos, t_conv *convers)
{
	char	*ptr;
	int		iter;

	convers -> end = pos;
	while (str[convers -> end])
	{
		ptr = ft_strchr(CONVS, str[convers -> end]);
		if (ptr)
			break ;
		convers -> end++;
	}
	if (!ptr)
		return (-(convers -> end));
	convers -> type = *ptr;
	iter = pos;
	while (iter < convers -> end)
	{
		ptr = ft_strchr(MODS, str[iter++]);
		if (!ptr)
			break ;
	}
	if (!ptr)
		return (-(convers -> end));
	return (pos);
}

int	parse_format(const char *str, t_conv *convers)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] != '%')
			convers -> printed += ft_putchar(str[count]);
		else
		{
			count = check_percent(str, count + 1, convers);
			if (count < 0)
				break ;
			count = ft_mods(str, count, convers);
			if (count < 0)
				return (-1);
			ft_convs(str, count, convers);
			clear_struct(convers);
		}
		count++;
	}
	if (count < 0)
		return (-1);
	return (0);
}

int	ft_printf(const char*format, ...)
{
	t_conv	convers;
	int		i;

	va_start (convers.vars, format);
	clear_struct(&convers);
	convers.printed = 0;
	i = parse_format (format, &convers);
	va_end (convers.vars);
	if (i < 0)
		return (ft_strlen_c(format, '\0'));
	return (convers.printed);
}
