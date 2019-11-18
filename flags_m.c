/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:38:49 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/18 20:44:20 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_flags(const char *s, int *i, int *flag, va_list ap)
{
	int		nb;

	if (s[*i] == '.')
		*i = *i + 1;
	if (s[*i] == '0')
	{
		*flag = 0;
		*i = *i + 1;
	}
	else if (ft_isdigit(s[*i]))
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		*flag = nb;
		*i = *i + ft_len_int(nb);
	}
	else if (s[*i] == '*')
	{
		*i = *i + 1;
		if (ft_dollar(s) == 0)
			*flag = -1;
		else if (ft_dollar(s) == 1)
		{
			nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
			ft_get_arg_dol(nb, flag, ap);
			*i = *i + ft_len_int(nb) + 1;
		}
	}
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

void	ft_dol_nb(t_var *var, va_list ap)
{
	int		i;
	va_list	aq;

	va_copy(aq, ap);
	i = 0;
	while (i < var->arg - 1)
	{
		va_arg(aq, int);
		i++;
	}
	var->arg = va_arg(aq, int);
}
