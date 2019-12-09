/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/09 18:09:10 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_traitement(const char *s, int *i, t_var *var, va_list ap)
{
	int		ret;

	ret = 0;
	*i = *i + 1;
	var->arg = 0;
	var->att = 1;
	var->larg = 0;
	var->prec = -2;
//	if (ft_dollar(s) == 1)
//		ft_arg(s, i, var);
	ft_attributs(s, i, var);
	if (s[*i] != '.')
		ft_flag_larg(s, i, var, ap);
	if (s[*i] == '.')
		ft_flag_prec(s, i, var, ap);
//	printf("\nlarg=%d prec=%d\n", var->larg, var->prec);
	if (var->arg == 0 || var->larg == -1 || var->prec == -1)
	{
		ft_compte(s, var, i);
//		printf("pre arg=%d n_arg=%d larg=%d prec=%d deb=%d\n", var->arg, var->n_arg, var->larg, var->prec, var->deb);
		if (var->arg == 0)
			var->arg = var->n_arg;
		ft_etoile(var, ap);
	//	printf("\narg=%d larg=%d prec=%d\n", var->n_arg, var->larg, var->prec);
//		printf("post arg=%d n_arg=%d larg=%d prec=%d deb=%d\n", var->arg, var->n_arg, var->larg, var->prec, var->deb);
	}
	if ((ret = ft_conversion(s, i, var, ap)) == -1)
		return (-1);
	return (ret);
}

int		ft_gestion(const char *s)
{
	int		i;
//	int		nb;
//	int		dol;

//	dol = ft_dollar(s);
	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	while (s[i])
	{
		if (s[i] == '*')
		{
			i++;
			if (ft_isdigit(s[i]))
			{
				return (1);
			//	nb = ft_atoi(ft_substr(s, i, ft_strlen(s)));
			//	if (dol == 0)
			//		return (1);
			//	else if (dol == 1 && s[i + ft_len_int(nb)] != '$')
			//		return (1);
			}
		//	else if (s[i] == '0')
		//		return (1);
		//	else if (ft_isdigit(s[i]) == 0 && dol == 1)
		//		return (1);
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
	int		ret_fin;
	int		ret;

	ret_fin = 0;
	pourcent = 0;
	var.n_arg = 0;
	if (ft_gestion(s) != 0)
		return (-1);
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			ret_fin++;
		}
		else if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar('%');
			ret_fin++;
			i++;
		}
		else
		{
			var.deb = i;
			pourcent++;
			var.percent = pourcent;
			if ((ret = ft_traitement(s, &i, &var, ap)) == -1)
				return (-1);
			ret_fin += ret;
		}
		i++;
	}
	va_end(ap);
	return (ret_fin);
}
