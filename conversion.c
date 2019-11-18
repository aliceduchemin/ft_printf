/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:58:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/18 18:30:01 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
//	printf("arg=%d, att=%d, larg=%d, prec=%d\n", var->arg, var->att, var->larg, var->prec);
	if (s[*i] == 'c' || s[*i] == 's')
		printf("char\n");
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'u')
		ft_conv_nb(var, ap);
	else if (s[*i] == 'x' || s[*i] == 'X')
		printf("hexa\n");
	else if (s[*i] == 'p')
		printf("pointeur\n");
}

void	ft_conv_nb(t_var *var, va_list ap)
{
	int		j;
	int		len;

	ft_dol_nb(var, ap);
	len = ft_len_int(var->arg);
//	printf("larg = %d,", var->larg);
//	printf("prec = %d, att = %d\n", var->prec, var->att);

	if (!(var->prec == 0 && var->arg == 0))
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
	//	printf("larg = %d,", var->larg);
	//	printf("prec = %d, att = %d\n", var->prec, var->att);
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
	}
}
