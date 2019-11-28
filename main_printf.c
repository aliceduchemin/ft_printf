/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/28 15:53:50 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_traitement(const char *s, int *i, t_var *var, va_list ap)
{
	int		arg;

	arg = 0;
	*i = *i + 1;
	var->arg = 0;
	var->att = 1;
	var->larg = 0;
	var->prec = -2;
	if (ft_dollar(s) == 1)
		ft_arg(s, i, var);
	ft_attributs(s, i, var);
	if (s[*i] != '.')
		ft_flag_larg(s, i, var, ap);
	if (s[*i] == '.')
		ft_flag_prec(s, i, var, ap);
//	printf("traitement prec %d\n", var->prec);
	if (var->arg == 0 || var->larg == -1 || var->prec == -1)
	{
		ft_compte(s, var, i, &arg);
		var->arg == 0 ? (var->arg = arg + 1) : (var->arg = var->arg);
		ft_etoile(&arg, var, ap);
	}
	if (ft_conversion(s, i, var, ap) == 0)
		return (1);
	return (0);
}

int		ft_gestion(const char *s)
{
	int		i;
	int		nb;
	int		dol;

	//ajouter : pas de conversionm double %, msg erreur, nb arg != nb%, flags avec mauvais format, num arg 0
	dol = ft_dollar(s);
	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	while (s[i])
	{
		if (s[i] == '*')
		{
			i++;
			if (ft_isdigit(s[i]) && s[i] != '0')
			{
				nb = ft_atoi(ft_substr(s, i, ft_strlen(s)));
				if (dol == 0)
					return (1);
				else if (dol == 1 && s[i + ft_len_int(nb)] != '$')
					return (1);
			}
			else if (s[i] == '0' || s[i] == '$')
				return (1);
			else if (ft_isdigit(s[i]) == 0 && dol == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	int		i;
	t_var 	var;
	int		pourcent;

	pourcent = 0;
	if (ft_gestion(s) == 0)
	{
		va_start(ap, s);
		i = 0;
		while (s[i])
		{
			if (s[i] != '%')
				ft_putchar(s[i]);
			else if (s[i] == '%' && s[i + 1] == '%')
			{
				ft_putchar('%');
				i++;
			}
			else
			{
			//	printf("MAIN i=%d et s[i]=%c%c\n", i, s[i], s[i + 1]);
				pourcent++;
				var.percent = pourcent;
		//		printf("percent main = %d\n", var.percent);
				if (ft_traitement(s, &i, &var, ap) == 1)
					return (1);
			}
			i++;
		}
		va_end(ap);
		return (0);
	}
	return (1);
}
