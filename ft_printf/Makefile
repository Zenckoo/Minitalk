SRC		= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr_u.c ft_putnbr_p.c ft_putnbr_x.c ft_putnbr_xx.c ft_putnbr_di.c


OBJS	= ${SRC:.c=.o}


CC		= gcc


CFLAGS	= -Wall -Werror -Wextra


SRC_H	= ft_printf.h


NAME	= libftprintf.a


all	:	${NAME}


${NAME} : ${OBJS}
		  ar rc ${NAME} ${OBJS}
		  ranlib ${NAME}

		  
clean	:
			rm -f ${OBJS}


fclean	: clean
	 	  rm -f ${NAME}


re	: fclean all


.PHONY	: all clean fclean re