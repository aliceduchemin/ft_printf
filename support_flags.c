/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:13:28 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/09 17:12:37 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_compte(const char *s, t_var *var, int *i)
{
	int		j;

	j = var->deb;
//	printf("\nj=%d arg=%d i=%d deb=%d\n", j, var->n_arg, *i, var->deb);
	while (j <= *i)
	{
		if (s[j] == '%' && s[j + 1] == '%')
			j++;
		else if (s[j] == '%' || s[j] == '*')
			var->n_arg++;
		j++;
	}
}

void	ft_etoile(t_var *var, va_list ap)
{
	va_list	aq;
	int		n;
	int		tmp;

	tmp = 0;
	va_copy(aq, ap);
	n = 1;
	if (var->larg == -1 && var->prec == -1)
	{
		while (n < (var->n_arg - 2))
		{
			va_arg(aq, int);
			n++;
		}
		var->larg = va_arg(aq, int);
		if (var->larg < 0)
		{
			var->larg *= -1;
			var->att = -1;
		}
		var->prec = va_arg(aq, int);
	}
	else if ((var->larg == -1 && var->prec != -1) || (var->larg != -1 && var->prec == -1))
	{
		while (n < (var->n_arg - 1))
		{
			va_arg(aq, int);
			n++;
		}
		var->larg == -1 ? (tmp = va_arg(aq, int)) : (var->prec = va_arg(aq, int));
		if (tmp < 0)
		{
			var->larg = tmp * -1;
			var->att = -1;
		}
		else
			var->larg = tmp;
	}
}
/*
void	ft_get_arg_dol(int nb, int *flag, va_list ap)
{
	va_list	aq;
	int		i;

	va_copy(aq, ap);
	i = 0;
	while (i < nb - 1)
	{
		va_arg(aq, int);
		i++;
	}
	*flag = va_arg(aq, int);
}

void	ft_flag_etoile(const char *s, int *i, int *flag, va_list ap)
{
	int		nb;

	nb = 0;
	*i = *i + 1;
	if (ft_dollar(s) == 0)
		*flag = -1;
	else if (ft_dollar(s) == 1)
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		ft_get_arg_dol(nb, flag, ap);
		*i = *i + ft_len_int(nb) + 1;
	}
}*/
