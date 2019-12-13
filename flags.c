/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:08:46 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/13 16:59:31 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_flag_larg(const char *s, int *i, t_var *var)
{
	if (ft_isdigit(s[*i]))
	{
		var->larg = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		*i = *i + ft_len_int(var->larg);
	}
	else if (s[*i] == '*')
	{
		var->larg = -1;
		*i = *i + 1;
	}
}

void	ft_flag_prec(const char *s, int *i, t_var *var)
{
	*i = *i + 1;
	if (ft_isdigit(s[*i]))
	{
		var->prec = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		*i = *i + ft_len_int(var->prec);
	}
	else if (s[*i] == '*')
	{
		var->prec = -1;
		*i = *i + 1;
	}
	else
		var->prec = 0;
}
