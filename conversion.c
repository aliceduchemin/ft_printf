/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:58:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/20 23:50:28 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

int		ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
	va_list	aq;
	int	nb;
	nb = 0;
	va_copy(aq, ap);
//	printf("arg=%d, att=%d, larg=%d, prec=%d\n", var->arg, var->att, var->larg, var->prec);
	if (s[*i] == 'c')
	   ft_conv_char(var, aq);
	else if	(s[*i] == 's')
	{
		if (ft_conv_char_etoile(var, aq) == 0)
			return (1);
	}
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'u' || s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'p')
		ft_conv_nb(var, aq, s[*i]);
	else if (s[*i] == '%')
		ft_putchar('%');
	return (0);
}

void	ft_conv_char(t_var *var, va_list aq)
{
	int		j;

	if (var->larg > 1 && var->att == 1)
		ft_print_flag(var->larg - 1, ' ');
	j = 0;
	while (j++ < var->arg - 1)
		va_arg(aq, int);
	ft_putchar(va_arg(aq, int));
	if (var->larg > 1 && var->att == -1)
		ft_print_flag(var->larg - 1, ' ');
}

int		ft_conv_char_etoile(t_var *var, va_list aq)
{
	int		j;
	char	*str;
	int		borne;

	j = 0;
	while (j++ < var->arg - 1)
		va_arg(aq, int);
	if (ft_str_vide(aq) == 0)
		return (0);
	if (ft_set_char(aq, &str, var, &borne) == 0)
		return (0);
	if (var->larg > 0 && var->att == 1)
		ft_print_flag(var->larg - borne, ' ');
	j = 0;
	while (j < borne)
		ft_putchar(str[j++]);
//	free(str);
	if (var->larg > 0 && var->att == -1)
		ft_print_flag(var->larg - borne, ' ');
	return (1);
}

void	ft_conv_nb(t_var *var, va_list aq, char c)
{
	int		len;

	ft_dol_nb(var, aq);
	if (c == 'x' || c == 'X' || c == 'p')
		len = ft_len_hexa(var->arg);
	else
		len = ft_len_int(var->arg);
//	printf("len = %d\n", len);
	if (!(var->prec == 0 && var->arg == 0))
	{
		ft_set_nb(var, len);
//		printf("arg = %d, larg = %d, prec = %d, att = %d\n", var->arg, var->larg, var->prec, var->att);
		if (var->arg < 0 && var->att == 0)
			ft_putchar('-');
		if (var->att == 0)
			ft_print_flag(var->larg, '0');
		else if (var->att == 1)
			ft_print_flag(var->larg, ' ');
		if (var->arg < 0 && var->att != 0)
			ft_putchar('-');
		ft_print_flag(var->prec, '0');
		ft_print_nb(var->arg, c);
		if (var->att == -1 && var->larg > 0)
			ft_print_flag(var->larg, ' ');
	}
}
