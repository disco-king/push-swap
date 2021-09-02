#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

# define CONVS "cspdiuxX%"
# define MODS "-0.*123456789"
# define S_ROW "0123456789abcdef"
# define B_ROW "0123456789ABCDEF"

typedef struct s_conv
{
	va_list	vars;

	int		type;
	int		printed;

	int		end;

	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		aster_w;
	int		aster_p;
	int		num_to_pad;
}	t_conv;

int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_putnbr(long long n, t_conv *convers);
int		num_length(long long i);
void	get_asters(t_conv *convers);
void	set_dimensions(long long number, int length, t_conv *conv);
void	pr_ecision(long long number, t_conv *conv);
void	out_num(long long number, t_conv *conv);
void	pr_number(t_conv *conv);
int		ft_printf(const char*format, ...);
int		parse_format(const char *str, t_conv *convers);
int		check_percent(const char *str, int pos, t_conv *convers);
int		ft_convs(const char *str, int pos, t_conv *convers);
int		ft_mods(const char *str, int pos, t_conv *con);
int		mod_aster(t_conv *con, int pos);
int		mod_number(const char *str, t_conv *con, int num);
void	clear_struct(t_conv *convers);
void	pr_char(t_conv *conv);
void	pr_string(t_conv *conv);
void	pr_unsign(t_conv *conv);
void	xd_putnbr(unsigned long long n, t_conv *convers);
char	get_hex(int i, char type);
int		xd_length(unsigned long long n);
void	pr_hexadec(t_conv *conv);
void	pr_percent(t_conv *conv);
void	pr_pointer(t_conv *conv);
void	ft_dispatch(long long number, t_conv *conv);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_c(const char *s, int c);
int		ft_atoi(const char *num);

#endif