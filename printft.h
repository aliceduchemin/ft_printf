/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:59:21 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/15 20:22:47 by aduchemi         ###   ########.fr       */
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

void			ft_arg(const char *s, int *i, t_var *var);
int				ft_dollar(const char *s);
void			ft_conversion(const char *s, int *i, t_var *var, va_list aq);
void			ft_flags(const char *s, int *i, int indice, t_var *var);
int				ft_len_int(int n);
int				ft_gestion(const char *s);
int				ft_format_dol(const char *s, int *i);
void			ft_attributs(const char *s, int *i, t_var *var);
void			ft_indice(t_var *var, int nb, int indice);
void			ft_traitement(const char *s, int *i, t_var *var, va_list ap);
void			ft_conv_nb(const char *s, t_var *var, va_list aq);
void			ft_etoile_nb(const char *s, t_var *var, va_list aq);

#endif
