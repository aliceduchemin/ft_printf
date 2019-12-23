/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_conv_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:54:48 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/22 19:10:36 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_loop(unsigned long nb, char *base, int ind, int *len)
{
	if (nb > (ft_strlen(base) - 1))
	{
		ft_loop(nb / ft_strlen(base), base, ind, len);
		nb = nb % ft_strlen(base);
	}
	if (ind == -1)
		ft_putchar(base[nb]);
	else
		*len = *len + 1;
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
