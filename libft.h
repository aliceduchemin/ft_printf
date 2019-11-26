/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:21:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/26 17:52:31 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_var
{
	int			percent;
	int			arg;
	int			att;
	int			larg;
	int			prec;
}				t_var;

int				ft_printf(const char *s, ...);
int				ft_gestion(const char *s);
int				ft_len_int(int n);
int				ft_traitement(const char *s, int *i, t_var *var, va_list ap);
int				ft_dollar(const char *s);
void			ft_arg(const char *s, int *i, t_var *var);
void			ft_attributs(const char *s, int *i, t_var *var);
void			ft_flag_larg(const char *s, int *i, t_var *var, va_list ap);
void			ft_flag_prec(const char *s, int *i, t_var *var, va_list ap);
void			ft_compte(const char *s, t_var *var, int *i, int *arg);
void			ft_etoile(int *arg, t_var *var, va_list ap);
void			ft_dol_nb(t_var *var, va_list ap);
void			ft_get_arg_dol(int nb, int *flag, va_list ap);
void			ft_flag_etoile(const char *s, int *i, int *flag, va_list ap);
int				ft_conversion(const char *s, int *i, t_var *var, va_list ap);
void			ft_precision(char c, t_var *var, va_list aq, int *len);
void			ft_conv_char(t_var *var, va_list ap);
int				ft_conv_char_etoile(t_var *var, va_list ap);
void			ft_conv_nb(t_var *var, va_list aq, char c);
void			ft_conv_unsigned(t_var *var, va_list aq, char c);
int				ft_u_int(t_var *vr, va_list aq, int ind);
void			ft_loop_u(unsigned int nb, int ind, int *len);
int				ft_set_char(va_list aq, char **str, t_var *var, int *borne);
int				ft_str_vide(va_list aq, int flag);
void			ft_print_flag(int nb, char c);
void			ft_print_nb(int nb, char c);
int				ft_hexa(t_var *var, va_list aq, char c, int ind);
void			ft_loop_hexa(unsigned long nb, char *base, int ind, int *len);
void			ft_set_nb(t_var *var, int len);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(char c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
int				ft_isprint(int c);
int				ft_isascii(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(const char *s1, const char *set);
void			ft_putchar(char c);
void			ft_putstr(char *s);

#endif
