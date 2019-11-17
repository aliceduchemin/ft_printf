/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:59:21 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/17 18:09:56 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

typedef struct	s_var
{
	int			percent;
	char		type;
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

// format
int				ft_dollar(const char *s);
void			ft_arg(const char *s, int *i, t_var *var);
void			ft_attributs(const char *s, int *i, t_var *var);

// flags_m
void			ft_flags(const char *s, int *i, int *flag, va_list ap);
void			ft_dol_nb(t_var *var, va_list ap);
void			ft_get_arg_dol(int nb, int *flag, va_list ap);

// flags_etoile
void			ft_compte(const char *s, t_var *var, int *i, int *arg);
void			ft_etoile(int *arg, t_var *var, va_list ap);

// conversion
void			ft_conversion(const char *s, int *i, t_var *var, va_list aq);
void			ft_conv_nb(const char *s, t_var *var, va_list aq, int *i);

#endif
