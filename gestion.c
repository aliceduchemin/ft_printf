/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:45:44 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/15 15:02:45 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

int		ft_gestion(const char *s, int dol)
{
	int		i;
	int		nb;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	while (s[i])
	{
		if (s[i] == '*')
		{
			i++;
			if (ft_isdigit(s[i]) && s[i] != '0')
			{
				nb = ft_atoi(ft_substr(s, i, ft_strlen(s)));
				if (dol == 0)
					return (1);
				else if (dol == 1 && s[i + ft_len_int(nb)] != '$')
					return (1);
			}
			else if (s[i] == '0' || s[i] == '$')
				return (1);
			else if (ft_isdigit(s[i]) == 0 && dol == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
