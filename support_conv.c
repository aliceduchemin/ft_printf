/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:07 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/20 18:24:54 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_print_flag(int nb, char c)
{
	int		j;

	j = 0;
	while (j++ < nb)
		ft_putchar(c);
}

int		ft_str_vide(va_list aq)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (va_arg(aq2, char *) == 0)
	{
		ft_putstr("(null)");
		return (0);
	}
	return (1);
}

int		ft_set_char(va_list aq, char **str, t_var *var, int *borne)
{
	va_list	aq2;

	va_copy(aq2, aq);
	*borne = ft_strlen(va_arg(aq2, char *));
	if (!(*str = malloc(sizeof(char) * (*borne + 1))))
		return (0);
	(*str)[*borne] = '\0';
	*str = va_arg(aq, char *);
	if (var->prec < 0)
		var->prec = 0;
	else if (var->prec > (int)ft_strlen(*str))
		var->prec = ft_strlen(*str);
	var->prec > 0 ? (*borne = var->prec) : (*borne = ft_strlen(*str));
	return (1);
}
