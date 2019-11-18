/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:38:57 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/18 20:44:17 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

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
	
	nb = 0;
	if (ft_isdigit(s[*i]) && s[*i] != 0)
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		*i = *i + ft_len_int(nb) + 1;
		var->arg = nb;
	}
}

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
