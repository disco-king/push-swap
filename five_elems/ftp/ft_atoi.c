#include "ft_printf.h"

int	ft_atoi(const char *num)
{
	int		res;
	int		buff;
	int		sign;

	res = 0;
	sign = 0;
	if (*num == '-')
	{
		sign = 1;
		num++;
	}
	while (*num)
	{
		if (*num > 57 || *num < 48)
			break ;
		buff = *num - '0';
		res = res * 10 + buff;
		num++;
	}
	if (sign)
		return (-res);
	return (res);
}
