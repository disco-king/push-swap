NAME	=	push_swap
LIB		=	./ftp/libftprintf.a
SRCS	=	push_swap.c push_swap_utils.c main.c\
			sorting.c sorting_utils.c minimal.c\
			lst_funcs.c p-s_funcs.c check_exit.c
SRCS_P	=	ftp/ft_printf.c ftp/numbers.c ftp/output.c \
			ftp/ft_strchr.c ftp/chars.c ftp/pointer.c \
			ftp/num_utils.c ftp/hexadec.c ftp/modifications.c \
			ftp/ft_atoi.c ftp/ft_strlen.c
OBJS	=	$(SRCS:.c=.o)
OBJS_P	=	$(SRCS_P:.c=.o)
DIR		=	./ftp
HEADER	=	push_swap.h
AR		=	ar rcs
CC		=	gcc
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_P)
		$(MAKE) -C $(DIR)
		$(CC) $(OBJS) -o $@ -L ./ftp/ -lftprintf

%.o :		%.c $(HEADER)
		$(CC) -c $(FLAGS) $< -o $@

clean:
		$(RM) $(OBJS) $(OBJS_P)

fclean:		clean
		$(RM) $(NAME) $(LIB)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
