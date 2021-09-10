#include "ft_printf.h"

int	mod_number(const char *str, t_conv *con, int num)
{
	int	pos;

	pos = 0;
	if ((!con -> dot && con -> aster_w)
		|| (!con -> dot && con -> width)
		|| (con -> dot && con -> aster_p)
		|| (con -> dot && con -> precision != -1))
		return (-num * 2);
	if ((str[pos] <= 57 && str[pos] >= 48) && !(con -> dot))
	{
		con -> width = ft_atoi(&str[pos]);
		while (str[pos] <= 57 && str[pos] >= 48)
			pos++;
	}
	else if ((str[pos] <= 57 && str[pos] >= 48) && (con -> dot))
	{
		con -> precision = ft_atoi(&str[pos]);
		while (str[pos] <= 57 && str[pos] >= 48)
			pos++;
	}
	return (pos);
}

int	mod_aster(t_conv *con, int pos)
{
	if ((!con -> dot && con -> aster_w)
		|| (!con -> dot && con -> width)
		|| (con -> dot && con -> aster_p)
		|| (con -> dot && con -> precision != -1))
		return (-pos * 2);
	if (!(con -> dot))
		con -> aster_w = 1;
	else
		con -> aster_p = 1;
	return (0);
}

int	ft_mods(const char *str, int pos, t_conv *con)
{
	while (str[pos] != con -> type)
	{
		if (str[pos] == '-' && (!con -> width) && !(con -> dot))
			con -> minus = 1;
		else if (str[pos] == '0' && !(con -> width) && !con -> dot)
			con -> zero = 1;
		else if (str[pos] == '.' && !(con -> dot))
			con -> dot = 1;
		else if ((str[pos] <= 57 && str[pos] >= 48))
			pos += mod_number(&(str[pos]), con, pos) - 1;
		else if (str[pos] == '*')
			pos += mod_aster(con, pos);
		else
			return (-pos);
		if (pos < 0)
			return (pos);
		pos++;
	}
	if (con -> dot && con -> precision == -1 && !con -> aster_p
		&& con -> type != 'p')
		con -> precision = 0;
	return (pos);
}
