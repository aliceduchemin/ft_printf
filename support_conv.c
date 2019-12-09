/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:07 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/09 17:12:35 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_precision(char c, t_var *var, va_list aq, int *len)
{
	va_list aq2;
	int		ret;

	ret = 0;
	va_copy(aq2, aq);
	if (c == 's')
	{
		if ((ret = ft_str_vide(aq2, var->prec, 0)) != 0)
		{
			var->prec = ret;
			*len = 0;
			//printf("prec=%d len=%d ret=%d\n", var->prec, *len, ret);
			return (ret);
		}
		else
			*len = ft_strlen(va_arg(aq2, char *));
	}
	else
	{
		if (c == 'c')
			*len = 1;
		else if (c == 'i' || c == 'd')
			*len = ft_len_int(va_arg(aq2, int));
		else if (c == 'u')
			ft_loop_u(va_arg(aq2, unsigned int), 0, len);
		else if (c == 'p' || c == 'x' || c == 'X')
			ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", 0, len);
		else if (c == '%')
			*len = 1;
		ret = *len;
	}
	ft_conditions(var, len, c, &ret);
	return (ret);
}

void	ft_conditions(t_var *var, int *len, char c, int *ret)
{
	if (var->att == 0 && var->prec >= 0)
		var->att = 1;
	if (var->prec == 0 && c == 's')
	{
		var->prec = -1;
		*len = 1;
		*ret = 0;
	}
	else if (c != 's' && c != 'c' && var->prec == 0)
	{
		var->prec = -2;
		*len = *len + 2;
	}
	else if (var->prec == -2)
		var->prec = 0;
	else if (var->prec > 0 && var->prec >= *len && c != 's' && c != 'c')
		var->prec -= *len;
	else if (var->prec > 0 && var->prec < *len && c != 's' && c != 'c')
		var->prec = 0;
	else if (var->prec > *len && c == 's')
		var->prec = 0;
	else if (var->prec < *len && c == 's')
	{
		*len = 0;
	//	*ret = var->prec;
	}
}

int		ft_print_flag(int nb, char c)
{
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	while (j++ < nb)
	{
		ft_putchar(c);
		ret++;
	}
	return (ret);
}

int		ft_str_vide(va_list aq, int flag, int indice)
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
			if (indice != 0)
				ft_putchar(s[i]);
			i++;
		}
		return (i);
	}
	return (0);
}
