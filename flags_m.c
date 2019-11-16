/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:38:49 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/16 17:38:50 by aduchemi         ###   ########.fr       */
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
