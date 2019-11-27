SRCS		= ft_isalnum.c ft_isdigit.c ft_strlen.c ft_tolower.c ft_isalpha.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c ft_strlcat.c ft_atoi.c ft_isascii.c ft_memset.c ft_isprint.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_strtrim.c ft_memmove.c ft_putchar.c ft_putstr.c ft_putnbr.c main_printf.c support_conv.c support_conv_nb.c flags.c support_flags.c conversion.c affichage.c

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
