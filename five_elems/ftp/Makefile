NAME	=	libftprintf.a
SRCS	=	ft_printf.c numbers.c output.c \
			ft_strchr.c chars.c pointer.c \
			num_utils.c hexadec.c modifications.c \
			ft_atoi.c ft_strlen.c

OBJS	=	$(SRCS:.c=.o)
HEADER	=	ft_printf.h
CC		= 	gcc
RM		=	rm -rf
AR		=	ar rcs
RANLIB	=	ranlib
FLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o : %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re