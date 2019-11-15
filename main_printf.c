/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/15 20:36:46 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

int		ft_len_int(int n)
{
	int		i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_indice(t_var *var, int nb, int indice)
{
	if (indice == 1)
		var->larg = nb;
	else
		var->prec = nb;
}

void	ft_flags(const char *s, int *i, int indice, t_var *var)
{
	int		nb;
	int		dol;

	dol = ft_dollar(s);
	if (ft_isdigit(s[*i]) && s[*i] != '0')
	{
		nb = ft_format_dol(s, i);
		ft_indice(var, nb, indice);
	}
	else if (s[*i] == '*')
	{
		*i = *i + 1;
		if (dol == 0)
			ft_indice(var, -1, indice);
		else if (dol == 1)
		{
			nb = ft_format_dol(s, i);
			ft_indice(var, nb, indice);
		}
	}
	if (s[*i] == '.')
	{
		*i = *i + 1;
		ft_flags(s, i, 2, var);
	}
}

int		ft_format_dol(const char *s, int *i)
{
	int		nb;

	nb = 0;
	if (ft_isdigit(s[*i]) && s[*i] != '0')
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		if (s[*i + ft_len_int(nb)] == '$')
			*i = *i + ft_len_int(nb) + 1;
		else
			*i = *i + ft_len_int(nb);
		return (nb);
	}
	return (0);
}

int		ft_dollar(const char *s)
{
	int		i;
	int		nb;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	if (s[i] == '%')
	{
		i++;
		if (ft_isdigit(s[i]) && s[i] != '0')
		{
			nb = ft_atoi(ft_substr(s, i, ft_strlen(s)));
			if (s[i + ft_len_int(nb)] == '$')
				return (1);
		}
	}
	return (0);
}

void	ft_arg(const char *s, int *i, t_var *var)
{
	int		nb;
	int		dol;

	dol = ft_dollar(s);
	nb = 0;
	if (dol == 1)
	{
		if (ft_isdigit(s[*i]) && s[*i] != 0)
		{
			nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
			*i = *i + ft_len_int(nb) + 1;
			var->arg = nb;
		}
	}
}

void	ft_attributs(const char *s, int *i, t_var *var)
{
	int		att;

	att = 0;
	while ((s[*i] == '-' || s[*i] == '0') && s[*i])
	{
		if (s[*i] == '0' && att != -1)
			att = 0;
		if (s[*i] == '-')
			att = -1;
		*i = *i + 1;
	}
	var->att = att;
}

void	ft_etoile_nb(const char *s, t_var *var, va_list aq)
{
	int		arg;
	int		j;
	int	 	nb;
	int		n;
	int		borne;
	int		p;

//	nb = va_arg(aq, int);
//	printf("%d\n", nb);
	printf("perct = %d\n", var->percent);
	borne = 0;
	p = 0;
	while (s[borne] && p < var->percent)
	{
		if (s[borne] == '%')
			p++;
		if (s[borne] = '*')

		if (p < var->percent)
			borne++;
	}
	printf("borne = %d et p = %d\n", borne, p);
	arg = 0;
	j = 0;
	while (s[j] && j < borne)
	{
		if (s[j] == '*')
		{
			arg++;
			printf("j = %d et arg = %d\n", j, arg);
		}
		else if (s[j] == 'd' || s[j] == 's')
		{
			arg++;
			printf("j = %d et arg = %d\n", j, arg);
		}
		j++;
	}
	n = 0;
	while (n < arg)
	{
		n++;
		nb = va_arg(aq, int);
	}
	nb = va_arg(aq, int);
	var->larg = nb;
	printf("nb = %d\n", nb);
}

void	ft_traitement(const char *s, int *i, t_var *var, va_list ap)
{
	*i = *i + 1;
	var->att = 0;
	var->larg = 0;
	var->prec = 0;
	ft_arg(s, i, var);
	ft_attributs(s, i, var);
	ft_flags(s, i, 1, var);
	ft_conversion(s, i, var, ap);
}

void	ft_printf(const char *s, ...)
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
				ft_traitement(s, &i, &var, ap);
			}
			i++;
		}
		va_end(ap);
	}
}

int		main(void)
{
	ft_printf("hello %-0*.5d Llop\n", 5, 10);
	return (0);
}
