SRCS		= ft_strlen.c ft_strlcpy.c ft_atoi.c ft_isdigit.c ft_putchar.c ft_putstr.c ft_putnbr.c main_printf.c support_conv.c support_conv_nb.c flags.c support_flags.c conversion.c affichage.c

OBJS		= ${SRCS:.c=.o}

FICHIER_H	= libft.h

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I ${FICHIER_H}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
