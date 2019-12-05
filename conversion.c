/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:02:47 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/05 14:34:52 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
	va_list aq;
	int		j;
	int		len;
	int		nb;
	int		ret;
	int		ret2;
	
	ret = 0;
	ret2= 0;
	len = 0;
	nb = 0;
	j = 0;
	va_copy(aq, ap);
	while (j++ < var->arg - 1)
		va_arg(aq, int);
	if ((ret = ft_cas_particuliers(s[*i], var, aq, &nb)) != 1)
		return (ret);
	ret = ft_precision(s[*i], var, aq, &len);
	if (var->att == 0)
	{
		if ((s[*i] == 'd' || s[*i] == 'i') && nb < 0)
		{
			ft_putchar('-');
			ret++;
		}
		ret += ft_print_flag(var->larg - var->prec - len, '0');
	}
	else if (var->att == 1)
		ret += ft_print_flag(var->larg - var->prec - len, ' ');
	if (s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'u') 
	{
		if (nb < 0 && var->att != 0)
		{
			ft_putchar('-');
			ret++;
		}
		ret += ft_print_flag(var->prec, '0');
	}
	if ((ret2 = ft_print(s[*i], var, aq, nb)) == -1)
		return (-1);
	ret += ret2;
	if (var->att == -1)
		ret += ft_print_flag(var->larg - var->prec - len, ' ');
	return (ret);
}

int		ft_cas_particuliers(char c, t_var *var, va_list aq, int *nb)
{
	va_list	aq2;
	int		ret;

	va_copy(aq2, aq);
	if (c == 'd' || c == 'i')
	{
		*nb = va_arg(aq2, int);
		if (*nb < 0)
			var->larg--;
		else if (*nb == 0)
		{
			if (var->prec == 0 && var->larg == 0)
				return (0);
		}
	}
	else if (c == 'u')
	{
		if (va_arg(aq2, unsigned int) == 0)
		{
			if (var->prec == 0 && var->larg == 0)
				return (0);
		}
	}
	else if (c == 'x' || c == 'X')
	{
		if (va_arg(aq2, unsigned long) == 0)
		{
			if (var->prec == 0 && var->larg == 0)
				return (0);
		}
	}
	if (c == 'p')
		var->larg -= 2;
	else if (c == 's')
	{
		if ((ret = ft_str_vide(aq2, var->prec)) != 0)
			return (ret);
	}
	return (1);
}
