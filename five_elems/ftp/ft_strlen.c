#include "ft_printf.h"

size_t	ft_strlen_c(const char *s, int c)
{
	size_t	res;

	res = 0;
	while (s[res] != c)
		res++;
	return (res);
}
