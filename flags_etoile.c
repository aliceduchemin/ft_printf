/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_etoile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:38:38 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/17 18:10:01 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_compte(const char *s, t_var *var, int *i, int *arg)
{
	int		j;
	int		p;

	j = 0;
	p = 0;
	while (j < *i)
	{
		while (p < var->percent)
		{
			if (s[j] == '%')
			{
				if (p > 0)
					*arg = *arg + 1;
				p++;
			}
			else if (s[j] == '*')
				*arg = *arg + 1;
			j++;
		}
		if (s[j] == '*')
			*arg = *arg + 1;
		j++;
	}
	if (var->arg == 0)
		var->arg = *arg + 1;
}

void	ft_etoile(int *arg, t_var *var, va_list ap)
{
	va_list	aq;
	int		n;

	va_copy(aq, ap);
	n = 0;
	if (var->larg == -1 && var->prec == -1)
	{
		while (n < (*arg - 2))
		{
			va_arg(aq, int);
			n++;
		}
		var->larg = va_arg(aq, int);
		var->prec = va_arg(aq, int);
	}
	else if ((var->larg == -1 && var->prec != -1) || (var->larg != -1 && var->prec == -1))
	{
		while (n < (*arg - 1))
		{
			va_arg(aq, int);
			n++;
		}
		var->larg == -1 ? (var->larg = va_arg(aq, int)) : (var->prec = va_arg(aq, int));
	}
}
