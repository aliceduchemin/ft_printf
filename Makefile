SRCS_LIB		= include/ft_isalnum.c include/ft_isdigit.c include/ft_strlen.c include/ft_tolower.c include/ft_isalpha.c include/ft_strchr.c include/ft_strlcpy.c include/ft_strncmp.c include/ft_strrchr.c include/ft_toupper.c include/ft_strlcat.c include/ft_atoi.c include/ft_isascii.c include/ft_memset.c include/ft_isprint.c include/ft_strnstr.c include/ft_bzero.c include/ft_memcpy.c include/ft_memccpy.c include/ft_memchr.c include/ft_memcmp.c include/ft_strdup.c include/ft_calloc.c include/ft_substr.c include/ft_strjoin.c include/ft_split.c include/ft_itoa.c include/ft_putchar_fd.c include/ft_putnbr_fd.c include/ft_putstr_fd.c include/ft_putendl_fd.c include/ft_strmapi.c include/ft_strtrim.c include/ft_memmove.c include/ft_putchar.c include/ft_putstr.c include/ft_putnbr.c

SRCS			= main_printf.c conversion.c support_conv.c support_conv_nb.c flags.c support_flags.c

OBJS_LIB		= ${SRCS_LIB:.c=.o}

OBJS			= ${SRCS:.c=.o}

LIBFT_H		= include/libft.h

LIB			= include/libft.a

NAME		= ft_printf

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I ${LIBFT_H} -o ${NAME}

all:		${LIB} ${NAME}

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:		${OBJS_LIB}
			ar rc ${LIB} ${OBJS_LIB}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${LIB}

clean:
			${RM} ${OBJS} ${OBJS_LIB}

fclean:		clean
			${RM} ${NAME} ${LIB}

re:			fclean all

.PHONY:		all clean fclean re
