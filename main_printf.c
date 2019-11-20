/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/20 23:50:05 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

int		ft_len_int(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		i++;
		n = 147483648;
	}
	if (n < 0)
		n *= -1;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

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
	if (var->arg == 0 || var->larg == -1 || var->prec == -1)
	{
		ft_compte(s, var, i, &arg);
		var->arg == 0 ? (var->arg = arg + 1) : (var->arg = var->arg);
		ft_etoile(&arg, var, ap);
	}
//	printf("%d : arg=%d, att=%d, larg=%d, prec=%d\n", var->percent, var->arg, var->att, var->larg, var->prec);
	if (ft_conversion(s, i, var, ap) == 1)
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
			else
			{
				pourcent++;
				var.percent = pourcent;
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

int		main(void)
{
	int		i;
	i = -15;
/*	ft_printf("larg = 4 prec = 15 : %0*.*i\n", 4, 15, i);
	ft_printf("larg = 15 prec = 4 : %0*.*i\n", 15, 4, i);
	ft_printf("larg = 15 : %0*i\n", 15, i);
	ft_printf("prec = 15 : %0.*i\n\n", 15, i);

	ft_printf("larg = 4 prec = 15 : %-*.*i\n", 4, 15, i);
	ft_printf("larg = 15 prec = 4 : %-*.*i\n", 15, 4, i);
	ft_printf("larg = 15 : %-*i\n", 15, i);
	ft_printf("prec = 15 : %-.*i\n\n", 15, i);

	ft_printf("larg = 4 prec = 15 : %*.*i\n", 4, 15, i);
	ft_printf("larg = 15 prec = 4 : %*.*i\n", 15, 4, i);
	ft_printf("larg = 15 : %*i\n", 15, i);
	ft_printf("prec = 15 : %.*i\n", 15, i);

	ft_printf("%1$-10d\n", i);
	ft_printf("%1$*1$d\n", i);
	ft_printf("%1$d\n", i);
	ft_printf("%1$05.6d\n", i);
	ft_printf("%1$0*2$.6d\n", i, 5);
	ft_printf("%1$0*2$.*3$d\n", i, 5, 6);
	ft_printf("test %3$0*2$.*1$d\n", i, 5, 6);
	ft_printf("test %2$0*1$.0d\n", 5, 6);
	ft_printf("%0*.*d\n", 5, 6, i);
	ft_printf("%0*.6d\n", 5, i);
	ft_printf("%05.6d\n\n", i);
	
	ft_printf("%010d\n", i);
	ft_printf("%10d\n", i);
	
	ft_printf("%*d\n", 10, i);
	ft_printf("%.6d\n", i);
*///	ft_printf("%x\n", 10);
	ft_printf("ici %%lol \n");

/*	ft_printf("%2$*1$c\n", -5, 'a');
	char *s = 0;
	ft_printf("ici %*.*s\n", 5, 10, s);
	ft_printf("ici %*.*s, %0.5d\n", 5, 10, "lol", 28);
	ft_printf("%2$*1$s\n", 5, "lol");
	ft_printf("%d\n", i);
	ft_printf("%c\n", 'c');
	ft_printf("%1$s, %2$0*3$.6d\n", "lol", i, 5);
*/	return (0);
}
