/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:02:47 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/15 18:02:19 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print(char c, t_var *var, va_list aq, int nb)
{
	va_list			aq2;
	int				ret;

	va_copy(aq2, aq);
	ret = 0;
	if (c == 's')
	{
		if (ft_str_vide(aq2, var->prec, 1) != -1)
			return (0);
		else if (ft_print_char(aq2, var, &ret) == -1)
			return (-1);
	}
	else if (c == 'c')
		ft_putchar(va_arg(aq2, int));
	else
		ret = ft_suite_print(c, var, aq, nb);
	return (ret);
}

int		ft_suite_print(char c, t_var *var, va_list aq, int nb)
{
	va_list	aq2;
	int		ret;

	va_copy(aq2, aq);
	ret = 0;
	if (c == 'i' || c == 'd')
	{
		if (nb == 0 && var->prec != -2)
			ft_putchar('0');
		else if (nb == 0 && var->prec == -2)
			ft_putchar(' ');
		else
			ft_print_nb(va_arg(aq2, int));
	}
	else if (c == '%')
		ft_putchar('%');
	else
		ft_suite2_print(c, var, aq, &ret);
	return (ret);
}

void	ft_suite2_print(char c, t_var *var, va_list aq, int *ret)
{
	va_list	aq2;
	va_list	aq3;
	int		*in;

	va_copy(aq2, aq);
	va_copy(aq3, aq);
	in = 0;
	if (c == 'u')
	{
		if (va_arg(aq2, unsigned int) == 0)
		{
			if (var->prec != -2)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		else
			ft_loop_u(va_arg(aq3, unsigned int), -1, in);
	}
	else
		*ret = ft_print_hexa(c, var, aq, in);
}

int		ft_print_hexa(char c, t_var *var, va_list aq, int *in)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (c == 'p')
	{
		ft_putstr("0x");
		ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", -1, in);
		return (2);
	}
	else if (va_arg(aq2, unsigned long) == 0)
	{
		if (var->prec != -2)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	else
		ft_suite_hexa(c, aq, in);
	return (0);
}

void	ft_suite_hexa(char c, va_list aq, int *in)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (c == 'x')
		ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789abcdef", -1, in);
	else if (c == 'X')
		ft_loop_hexa(va_arg(aq2, unsigned long), "0123456789ABCDEF", -1, in);
}
