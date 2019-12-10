/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:08:46 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/10 18:54:09 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_attributs(const char *s, int *i, t_var *var)
{
	while ((s[*i] == '-' || s[*i] == '0') && s[*i])
	{
		if (s[*i] == '0' && var->att != -1)
			var->att = 0;
		if (s[*i] == '-')
			var->att = -1;
		*i = *i + 1;
	}
}

void	ft_flag_larg(const char *s, int *i, t_var *var, va_list ap)
{
	int		nb;

	(void)ap;
	nb = 0;
	if (ft_isdigit(s[*i]))
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		*i = *i + ft_len_int(nb);
		var->larg = nb;
	}
	else if (s[*i] == '*')
	{
		var->larg = -1;
		*i = *i + 1;
	}
}

void	ft_flag_prec(const char *s, int *i, t_var *var)
{
	int		nb;

	*i = *i + 1;
	if (s[*i] == '0')
	{
		var->prec = 0;
		*i = *i + 1;
	}
	else if (ft_isdigit(s[*i]))
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		var->prec = nb;
		*i = *i + ft_len_int(nb);
	}
	else if (s[*i] == '*')
	{
		var->prec = -1;
		*i = *i + 1;
	}
	else
		var->prec = 0;
}
