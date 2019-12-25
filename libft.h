/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:21:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/25 16:21:37 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_var
{
	int			n_arg;
	int			deb;
	int			att;
	int			larg;
	int			prec;
}				t_var;

int				ft_printf(const char *s, ...);
int				ft_boucle(const char *s, t_var *var, va_list ap, int *ret_fin);
int				ft_gestion(const char *s, int *i);
void			ft_print_invar(char c, int *ret_fin, int *i);
int				ft_traitement(const char *s, int *i, t_var *var, va_list ap);
void			ft_attributs(const char *s, int *i, t_var *var);
void			ft_flag_larg(const char *s, int *i, t_var *var);
void			ft_flag_prec(const char *s, int *i, t_var *var, int *ret_prec);
void			ft_flag_prec_2(const char *s, int *i, t_var *var,
				int *ret_prec);
int				ft_print_char(va_list aq, t_var *var, int *ret);
void			ft_compte(const char *s, t_var *var, int *i);
void			ft_etoile(t_var *var, va_list ap);
void			ft_suite_etoile(t_var *var, va_list ap);
int				ft_print_flag(int nb, char c);
int				ft_conversion(const char *s, int *i, t_var *var, va_list ap);
int				ft_suite_conv(char c, t_var *var, va_list aq, int nb);
int				ft_cas_particuliers(char c, t_var *var, va_list aq, int *nb);
int				ft_cas_part2(char c, t_var *var, va_list aq);
int				ft_print_att(t_var *var, int *nb, char c, int *len);
int				ft_precision(char c, t_var *var, va_list aq, int *len);
int				ft_suite_precision(char c, va_list aq, int *len);
void			ft_conditions(t_var *var, int *len, char c, int *ret);
void			ft_suite_cond(t_var *var, int *len, char c, int *ret);
int				ft_str_vide(va_list aq, int flag, int indice);
void			ft_print_nb(int nb);
int				ft_len_int(int n);
void			ft_loop(unsigned long nb, char *base, int ind, int *len);
void			ft_loop_u(unsigned int nb, int ind, int *len);
int				ft_print(char c, t_var *var, va_list aq, int nb);
int				ft_suite_print(char c, t_var *var, va_list aq, int nb);
void			ft_suite2_print(char c, t_var *var, va_list aq, int *ret);
int				ft_print_hexa(char c, t_var *var, va_list aq, int *in);
void			ft_suite_hexa(char c, va_list aq, int *in);
int				ft_isdigit(int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char *s);

#endif
