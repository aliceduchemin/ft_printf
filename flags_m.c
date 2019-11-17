/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:38:49 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/17 01:10:58 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_indice(t_var *var, int nb, int indice)
{
	if (indice == 1)
		var->larg = nb;
	else
		var->prec = nb;
}

void	ft_flags_larg(const char *s, int *i, t_var *var, va_list ap)
{
	int		nb;

	if (ft_isdigit(s[*i]) && s[*i] != '0')
	{
		nb = ft_format_dol(s, i, ap, &var->larg);
		var->larg = nb;
	}
	else if (s[*i] == '*')
	{
		*i = *i + 1;
		if (ft_dollar(s) == 0)
			var->larg = -1;
		else if (ft_dollar(s) == 1)
		{
			nb = ft_format_dol(s, i, ap, &var->larg);
			var->larg = nb;
		}
	}
}

void	ft_flags_prec(const char *s, int *i, t_var *var, va_list ap)
{
	int		nb;

	if (s[*i] == '.')
	{
		*i = *i + 1;
		if (ft_isdigit(s[*i]) && s[*i] != '0')
		{
			nb = ft_format_dol(s, i, ap, &var->prec);
			var->prec = nb;
		}
		else if (s[*i] == '*')
		{
			*i = *i + 1;
			if (ft_dollar(s) == 0)
				var->prec = -1;
			else if (ft_dollar(s) == 1)
			{
				nb = ft_format_dol(s, i, ap, &var->prec);
				var->prec = nb;
			}
		}
	}
}

int		ft_format_dol(const char *s, int *i, va_list ap, int *flag)
{
	int		nb;

	nb = 0;
	if (ft_isdigit(s[*i]) && s[*i] != '0')
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
	//	printf("format = %d, s[i] = %c et i = %d\n", nb, s[*i], *i);
		if (s[*i + ft_len_int(nb)] == '$')
		{
			ft_get_arg_dol(nb, flag, ap);
			*i = *i + ft_len_int(nb) + 1;
		}
		else
			*i = *i + ft_len_int(nb);
		return (nb);
	}
	return (0);
}

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

void	ft_dol_nb(t_var *var, va_list aq)
{
	int		i;

	i = 0;
	while (i < var->arg - 1)
	{
		va_arg(aq, int);
		i++;
	}
	var->arg = va_arg(aq, int);
}
