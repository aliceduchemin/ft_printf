/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:58:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/18 20:44:25 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
//	printf("arg=%d, att=%d, larg=%d, prec=%d\n", var->arg, var->att, var->larg, var->prec);
	if (s[*i] == 'c' || s[*i] == 's')
		ft_conv_char(s, i, var, ap);
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'u')
		ft_conv_nb(var, ap);
	else if (s[*i] == 'x' || s[*i] == 'X')
		printf("hexa\n");
	else if (s[*i] == 'p')
		printf("pointeur\n");
}

void	ft_conv_char(const char *s, int *i, t_var *var, va_list ap)
{
	va_list	aq;
	int		j;
	va_copy(aq, ap);
//	ft_conv(var, var->arg);
	printf("conv char arg = %d, att = %d, larg = %d, prec = %d\n", var->arg, var->att, var->larg, var->prec);

	if (var->larg > 0 && var->att == 1)
	{
		j = 0;
		while (j < var->larg)
		{
			ft_putchar(' ');
			j++;
		}
	}
	j = 0;
	while (j < var->arg - 1)
	{
		va_arg(aq, int);
		j++;
	}
	if (s[*i] == 'c')
		ft_putchar(va_arg(aq, int));
	else if (s[*i] == 's')
		ft_putstr(va_arg(aq, char *));
	if (var->att == -1 && var->larg > 0)
	{
		j = 0;
		while (j < var->larg)
		{
			ft_putchar(' ');
			j++;
		}
	}
}

void	ft_conv(t_var *var, int len)
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
	(var->arg < 0) ? var->larg-- : (var->larg = var->larg);
}

void	ft_conv_nb(t_var *var, va_list ap)
{
	int		j;
	int		len;

	ft_dol_nb(var, ap);
	len = ft_len_int(var->arg);

	if (!(var->prec == 0 && var->arg == 0))
	{
		ft_conv(var, len);
	//	printf("arg = %d, larg = %d, prec = %d, att = %d\n", var->arg, var->larg, var->prec, var->att);
		if (var->arg < 0 && var->att == 0)
			ft_putchar('-');
		j = 0;
		while (j < var->larg)
		{
			if (var->att == 0)
				ft_putchar('0');
			else if (var->att == 1)
				ft_putchar(' ');
			j++;
		}
		if (var->arg < 0 && var->att != 0)
			ft_putchar('-');
		j = 0;
		while (j < var->prec)
		{
			ft_putchar('0');
			j++;
		}
		if (var->arg == -2147483648)
		{
			ft_putchar('2');
			var->arg = 147483648;
		}
		if (var->arg < 0)
			var->arg *= -1;
		ft_putnbr(var->arg);
		if (var->att == -1 && var->larg > 0)
		{
			j = 0;
			while (j < var->larg)
			{
				ft_putchar(' ');
				j++;
			}
		}

	}
}
