/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:14:07 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/20 19:34:13 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

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
	else if (c == 'x' || c == 'p')
		ft_hexa(nb, "0123456789abcdef");
	else if (c == 'X')
		ft_hexa(nb, "0123456789ABCDEF");
}

int		ft_len_hexa(int nb)
{
	int		i;

	i = 0;
	while (nb)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void	ft_hexa(int nb, char *base)
{
	if (nb > 15)
	{
		ft_hexa(nb / 16, base);
		nb = nb % 16;
	}
	ft_putchar(base[nb]);
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
