/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:58:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/17 18:09:52 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
//	printf("arg=%d, att=%d, larg=%d, prec=%d\n", var->arg, var->att, var->larg, var->prec);
//	printf("i = %c\n", s[*i]);
	if (s[*i] == 'c' || s[*i] == 's')
		printf("char\n");
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'u')
		ft_conv_nb(s, var, ap, i);
	else if (s[*i] == 'x' || s[*i] == 'X')
		printf("hexa\n");
	else if (s[*i] == 'p')
		printf("pointeur\n");
}

void	ft_conv_nb(const char *s, t_var *var, va_list ap, int *i)
{
	int		j;
	(void)s;
	(void)i;

	ft_dol_nb(var, ap);
	var->larg == 0 ? (var->larg = ft_len_int(var->arg)) : (var->larg = var->larg);
	if (var->arg != 0)
	{
		if (var->prec == 0 || var->prec == 1)
			var->prec = ft_len_int(var->arg);
	}
//	printf("arg conv fin=%d, att=%d, larg=%d, prec=%d\n", var->arg, var->att, var->larg, var->prec);

//	if (var->arg < 0)
//		ft_putc GERER NEG
	if (!(var->prec == 0 && var->arg == 0))
	{
		j = 0;
		while (j < (var->larg - var->prec))
		{
			if (var->att == 0 || var->att == 1)
			{
				if (var->prec == ft_len_int(var->arg) && var->att == 0)
					ft_putchar('0');
				else
					ft_putchar(' ');
			}
			j++;
		}
		j = 0;
		while (j < (var->prec - ft_len_int(var->arg)))
		{
			ft_putchar('0');
			j++;
		}
		ft_putnbr(var->arg);
	}
}
