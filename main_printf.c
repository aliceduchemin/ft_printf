/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/25 19:08:48 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_traitement(const char *s, int *i, t_var *var, va_list ap)
{
	int		ret;
	int		ret_prec;

	ret = 0;
	ret_prec = 0;
	var->att = 1;
	var->larg = 0;
	var->prec = -2;
	*i = *i + 1;
	ft_attributs(s, i, var);
	if (s[*i] != '.')
		ft_flag_larg(s, i, var);
	if (s[*i] == '.')
		ft_flag_prec(s, i, var, &ret_prec);
	ft_compte(s, var, i);
	ft_etoile(var, ap);
	if ((ret = ft_conversion(s, i, var, ap)) == -1)
		return (-1);
	return (ret + ret_prec);
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	t_var	var;
	int		ret_fin;

	ret_fin = 0;
	var.n_arg = 0;
	va_start(ap, s);
	if (ft_boucle(s, &var, ap, &ret_fin) == -1)
		return (-1);
	va_end(ap);
	return (ret_fin);
}

int		ft_gestion(const char *s, int *i)
{
	int		t;

	t = *i + 1;
	while (s[t] != 'd' && s[t] != 'i' && s[t] != 'c' && s[t] != 's'
			&& s[t] != 'x' && s[t] != 'X' && s[t] != 'p' && s[t] != 'u'
			&& s[t] != '%' && s[t])
		t++;
	if (s[t] == '\0')
	{
		*i = t - 1;
		return (-1);
	}
	return (0);
}

int		ft_boucle(const char *s, t_var *var, va_list ap, int *ret_fin)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_print_invar(s[i], ret_fin, &i);
		else if (s[i] == '%' && s[i + 1] == '%')
			ft_print_invar('%', ret_fin, &i);
		else
		{
			if (ft_gestion(s, &i) == 0)
			{
				var->deb = i;
				if ((ret = ft_traitement(s, &i, var, ap)) == -1)
					return (-1);
				*ret_fin = *ret_fin + ret;
			}
		}
		i++;
	}
	return (0);
}

void	ft_print_invar(char c, int *ret_fin, int *i)
{
	ft_putchar(c);
	*ret_fin = *ret_fin + 1;
	if (c == '%')
		*i = *i + 1;
}
