/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:02:47 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/05 14:39:22 by aduchemi         ###   ########.fr       */
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

int		ft_print(char c, t_var *var, va_list aq, int nb)
{
	int				*in;
	va_list			aq2;
	va_list			aq3;
	int				ret;

	va_copy(aq2, aq);
	va_copy(aq3, aq);
	ret = 0;
	in = 0;
	if (c == 's')
	{
		if (ft_print_char(aq2, var) == -1)
			return (-1);
	}
	else if (c == 'c')
		ft_putchar(va_arg(aq2, int));
	else if (c == 'i' || c == 'd') 
	{
		if (nb == 0 && var->prec != -2)
			ft_putchar('0');
		else if (nb == 0 && var->prec == -2)
			ft_putchar(' ');
		else
			ft_print_nb(va_arg(aq2, int));
	}
	else if (c == 'u')
	{
		if (va_arg(aq3, unsigned int) == 0)
		{
			if (var->prec != -2)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		else
			ft_loop_u(va_arg(aq2, unsigned int), -1, in);
	}
	else if (c == '%')
		ft_putchar('%');
	else
		ret = ft_print_hexa(c, var, aq, in);
	return (ret);
}

int		ft_print_hexa(char c, t_var *var, va_list aq, int *in)
{
	va_list	aq3;
	va_list	aq2;
	int		ret;
	
	ret = 0;
	va_copy(aq2, aq);
	va_copy(aq3, aq);
	if (c == 'p')
	{
		ft_putstr("0x");
		ret = 2;
		ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", -1, in);
	}
	else if (va_arg(aq3, unsigned long) == 0)
	{
		if (var->prec != -2)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	else
	{
		if (c == 'x')
			ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", -1, in);
		else if (c == 'X')
			ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789ABCDEF", -1, in);
	}
	return (ret);
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
			return (-1);
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
	return (0);
}
