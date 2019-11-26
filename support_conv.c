/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:07 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/26 17:52:28 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_print_flag(int nb, char c)
{
	int		j;

	j = 0;
	while (j++ < nb)
		ft_putchar(c);
}

int		ft_str_vide(va_list aq, int flag)
{
	va_list	aq2;
	int		i;
	char	s[6] = "(null)";

	if (flag == -2)
		flag = 6;
	va_copy(aq2, aq);
	if (va_arg(aq2, char *) == 0)
	{
		i = 0;
		while (i < flag)
		{
			ft_putchar(s[i]);
			i++;
		}
		return (0);
	}
	return (1);
}

int		ft_set_char(va_list aq, char **str, t_var *var, int *borne)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (var->prec != 0)
	{
		*borne = ft_strlen(va_arg(aq2, char *));
		if (!(*str = malloc(sizeof(char) * (*borne + 1))))
			return (0);
		(*str)[*borne] = '\0';
		*str = va_arg(aq, char *);
	}
	if (var->prec == -2 || var->prec > (int)ft_strlen(*str))
		var->prec = ft_strlen(*str);
	*borne = var->prec;
//	var->prec > 0 ? (*borne = var->prec) : (*borne = ft_strlen(*str));
	return (1);
}
