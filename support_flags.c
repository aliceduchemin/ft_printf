/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:13:28 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/09 19:36:17 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_compte(const char *s, t_var *var, int *i)
{
	int		j;

	j = var->deb;
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

	va_copy(aq, ap);
	n = 1;
	if (var->larg == -1 && var->prec == -1)
	{
		while (n++ < (var->n_arg - 2))
			va_arg(aq, int);
		var->larg = va_arg(aq, int);
		if (var->larg < 0)
		{
			var->larg *= -1;
			var->att = -1;
		}
		var->prec = va_arg(aq, int);
	}
	else if ((var->larg == -1 && var->prec != -1)
			|| (var->larg != -1 && var->prec == -1))
		ft_suite_etoile(var, ap);
}

void	ft_suite_etoile(t_var *var, va_list ap)
{
	va_list	aq;
	int		n;
	int		tmp;

	va_copy(aq, ap);
	n = 1;
	tmp = 0;
	while (n++ < (var->n_arg - 1))
		va_arg(aq, int);
	if (var->larg == -1)
		tmp = va_arg(aq, int);
	else
		var->prec = va_arg(aq, int);
	if (tmp < 0)
	{
		var->larg = tmp * -1;
		var->att = -1;
	}
	else
		var->larg = tmp;
}
