/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:54:48 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/10 18:29:35 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_print_nb(int nb)
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

int		ft_len_int(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		i++;
		n = 147483648;
	}
	if (n < 0)
		n *= -1;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_loop_u(unsigned int nb, int ind, int *len)
{
	if (nb > 9)
	{
		ft_loop_u(nb / 10, ind, len);
		nb = nb % 10;
	}
	if (ind == -1)
		ft_putchar(nb + 48);
	else
		*len = *len + 1;
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
