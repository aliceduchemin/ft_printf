/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:07 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/21 18:30:05 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_print_nb(int nb, char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
	{
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = 147483648;
		}
		if (nb < 0)
			nb *= -1;
		ft_putnbr(nb);
	}
}

int		ft_hexa(t_var *var, va_list aq, char c, int ind)
{
	unsigned long	nb;
	int				i;
	int				len;
	va_list			aq2;
	
	va_copy(aq2, aq);
	len = 0;
	i = 0;
	while (i < var->arg - 1)
	{
		va_arg(aq2, int);
		i++;
	}
	nb = va_arg(aq2, unsigned long);
	if (c == 'x')
		ft_loop_hexa(nb, "0123456789abcdef", ind, &len);
	else if (c == 'p')
	{
		if (ind == -1)
			ft_putstr("0x");
		ft_loop_hexa(nb, "0123456789abcdef", ind, &len);
	}
	else if (c == 'X')
		ft_loop_hexa(nb, "0123456789ABCDEF", ind, &len);
	return (len);
}

void	ft_loop_hexa(unsigned long nb, char *base, int ind, int *len)
{
	if (nb > 15)
	{
		ft_loop_hexa(nb / 16, base, ind, len);
		nb = nb % 16;
	}
	if (ind == -1)
		ft_putchar(base[nb]);
	else
		*len = *len + 1;
}

void	ft_set_nb(t_var *var, int len)
{
	if (var->prec >= 0 && var->att == 0)
		var->att = 1;
	if (var->prec == -2)
		var->prec = 0;
	var->prec = var->prec - len;
	if (var->prec > 0)
		var->larg = var->larg - var->prec - len;
	else
		var->larg = var->larg - len;
	if (var->arg < 0)
		var->larg--;
}
