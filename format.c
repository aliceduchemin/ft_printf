/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:38:57 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/17 01:11:06 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_type_conv(const char *s, int i, t_var *var)
{
	int		j;
	
	j = 0;
	while (j < i)
		j++;
	while (s[j] != 'c' && s[j] != 's' && s[j] != 'i' && s[j] != 'd' && s[j] != 'u' && s[j] != 'x' && s[j] != 'X' && s[j] != 'p' && s[j] != '%' && s[j])
		j++;
	var->type = s[j];
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
//	int		j;
//	va_list	aq;
// ft_dol_nb ici?
	nb = 0;
	if (ft_dollar(s) == 1)
	{
		if (ft_isdigit(s[*i]) && s[*i] != 0)
		{
			nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
			*i = *i + ft_len_int(nb) + 1;
			var->arg = nb;
		}
/*		va_copy(aq, ap);
		j = 0;
		while (j < nb - 1)
		{
			va_arg(aq, int);
			j++;
		}
		var->arg = va_arg(aq, int);
		printf("nb = %d\n", va->arg);*/
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
