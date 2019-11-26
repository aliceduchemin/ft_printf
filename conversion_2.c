/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:18:18 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/26 17:52:17 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
	va_list aq;
	int		j;
	int		len;

	len = 0;
	j = 0;
	while (j < var->arg - 1)
		va_arg(ap, int);
	va_copy(aq, ap);
	if (!(var->prec == 0 && var->arg == 0))
	{
		ft_precision(s[*i], var, aq, &len);
		printf("var->prec = %d\n", var->prec);
	}
	return (0);
}

void	ft_precision(char c, t_var *var, va_list aq, int *len)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (c == 's')
		*len = ft_strlen(va_arg(aq, char *));
	else if (c == 'c')
		*len = 1;
	else if (c == 'i' || c == 'd')
		*len = ft_len_int(va_arg(aq, int));
	else if (c == 'u')
		ft_loop_u(va_arg(aq, unsigned int), 0, len);
	else if (c == 'p' || c == 'x' || c== 'X')
		ft_loop_hexa(va_arg(aq, unsigned long), "0123456789abcdef", 0, len);
	if (var->att == 0 && var->prec >= 0)
		var->att = 1;
	if (var->prec == -2)
		var->prec = *len;
	else if (var->prec > 0 && var->prec < *len && c != 's' && c != 'c')
		var->prec = *len;
}

