#include "ft_printf.h"

void	ft_putnbr(long long n, t_conv *convers)
{
	char	buff;

	if (n < 0)
	{
		convers -> printed += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		buff = n % 10 + 48;
		ft_putnbr(n / 10, convers);
		convers -> printed += ft_putchar(buff);
	}
	else if (n < 10)
	{
		buff = n + 48;
		convers -> printed += ft_putchar(buff);
	}
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	ret;

	ret = 0;
	if (s == NULL)
		return (0);
	while (s[ret])
		ft_putchar(s[ret++]);
	return (ret);
}

char	get_hex(int i, char type)
{
	if (type == 'X')
		return (B_ROW[i]);
	else
		return (S_ROW[i]);
}

void	xd_putnbr(unsigned long long n, t_conv *convers)
{
	char	buff;

	if (n >= 16)
	{
		buff = get_hex(n % 16, convers -> type);
		xd_putnbr(n / 16, convers);
		convers -> printed += ft_putchar(buff);
	}
	else if (n < 16)
	{
		buff = get_hex(n, convers -> type);
		convers -> printed += ft_putchar(buff);
	}
}
