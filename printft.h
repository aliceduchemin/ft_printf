/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:59:21 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/20 18:47:07 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

typedef struct	s_var
{
	int			percent;
	int			arg;
	int			att;
	int			larg;
	int			prec;
}				t_var;

// main_printf
int				ft_gestion(const char *s);
int				ft_len_int(int n);
void			ft_printf(const char *s, ...);
void			ft_traitement(const char *s, int *i, t_var *var, va_list ap);

// flags
int				ft_dollar(const char *s);
void			ft_arg(const char *s, int *i, t_var *var);
void			ft_attributs(const char *s, int *i, t_var *var);
void			ft_flag_larg(const char *s, int *i, t_var *var, va_list ap);
void			ft_flag_prec(const char *s, int *i, t_var *var, va_list ap);

// support_flags
void			ft_compte(const char *s, t_var *var, int *i, int *arg);
void			ft_etoile(int *arg, t_var *var, va_list ap);
void			ft_dol_nb(t_var *var, va_list ap);
void			ft_get_arg_dol(int nb, int *flag, va_list ap);
void			ft_flag_etoile(const char *s, int *i, int *flag, va_list ap);

// conversion
void			ft_conversion(const char *s, int *i, t_var *var, va_list ap);
void			ft_conv_char(t_var *var, va_list ap);
int				ft_conv_char_etoile(t_var *var, va_list ap);
void			ft_conv_nb(t_var *var, va_list aq, char c);

// support_conv
int				ft_set_char(va_list aq, char **str, t_var *var, int *borne);
int				ft_str_vide(va_list aq);
void			ft_print_flag(int nb, char c);

// support_conv_nb
void			ft_print_nb(int nb, char c);
void			ft_set_nb(t_var *var, int len);
int				ft_len_hexa(int nb);
void			ft_hexa(int nb, char *base);

#endif
