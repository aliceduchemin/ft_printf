/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:02:47 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/28 15:53:58 by aduchemi         ###   ########.fr       */
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

void	ft_print(char c, t_var *var, va_list aq, int nb)
{
	int		*in;
	va_list	aq2;
	va_list	aq3;

	va_copy(aq2, aq);
	va_copy(aq3, aq);
	in = 0;
	if (c == 's')
		ft_print_char(aq2, var);
	else if (c == 'c')
		ft_putchar(va_arg(aq2, int));
	else if (c == 'i' || c == 'd') 
	{
		if (!(nb == 0 && var->prec == 0))
			ft_print_nb(va_arg(aq2, int));
	}
	else if (c == 'u')
	{
		if (va_arg(aq3, unsigned int) == 0)
			ft_putchar('0');
		else
			ft_loop_u(va_arg(aq2, unsigned int), -1, in);
	}
	else if (c == '%')
		ft_putchar('%');
	else
		ft_print_hexa(c, var, aq, in);
}

void	ft_print_hexa(char c, t_var *var, va_list aq, int *in)
{
	va_list	aq3;
	va_list	aq2;
	(void)var;

	va_copy(aq2, aq);
	va_copy(aq3, aq);
	if (c == 'p')
	{
		ft_putstr("0x");
		ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", -1, in);
	}
	else if (va_arg(aq3, unsigned long) == 0)
		ft_putchar('0');
	else
	{
		if (c == 'x')
			ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", -1, in);
		else if (c == 'X')
			ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789ABCDEF", -1, in);
	}
}

int		ft_print_char(va_list aq, t_var *var)
{
	va_list	aq2;
	va_list	aq3;
	char	*str;
	int		j;
	int		borne;

	va_copy(aq2, aq);
	va_copy(aq3, aq);
	if (var->prec != -1)
	{
		borne = ft_strlen(va_arg(aq3, char *));
		if (!(str = malloc(sizeof(char) * (borne + 1))))
			return (0);
		str[borne] = '\0';
		str = va_arg(aq2, char *);
	}
	j = 0;
	if (var->prec != -1 && var->prec != 0)
	{
		while (j < var->prec)
			ft_putchar(str[j++]);
	}
	else if (var->prec == 0)
		ft_putstr(str);
	return (1);
}
