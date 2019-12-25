/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:02:47 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/25 19:08:26 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
	va_list aq;
	int		j;
	int		len;
	int		nb;
	int		ret;

	va_copy(aq, ap);
	j = 0;
	len = 0;
	nb = 0;
	ret = 0;
	while (j++ < var->n_arg - 1)
		va_arg(aq, int);
	if ((ret = ft_cas_particuliers(s[*i], var, aq, &nb)) != 1)
		return (ret);
	ret = ft_precision(s[*i], var, aq, &len);
	if (s[*i] == '%' && var->att == 0)
		ret += ft_print_flag(var->prec, '0');
	else if (s[*i] == '%' && var->att == 1)
		ret += ft_print_flag(var->prec, ' ');
	ret += ft_print_att(var, &nb, s[*i], &len);
	ret += ft_suite_conv(s[*i], var, aq, nb);
	if (var->att == -1)
		ret += ft_print_flag(var->larg - var->prec - len, ' ');
	return (ret);
}

int		ft_suite_conv(char c, t_var *var, va_list aq, int nb)
{
	va_list	aq2;
	int		ret;
	int		ret2;

	va_copy(aq2, aq);
	ret = 0;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'u')
	{
		if (nb < 0 && var->att != 0)
		{
			ft_putchar('-');
			ret++;
		}
		if (c == '%' && var->att != 0)
			ret += ft_print_flag(var->prec, ' ');
		else
			ret += ft_print_flag(var->prec, '0');
	}
	if ((ret2 = ft_print(c, var, aq, nb)) == -1)
		return (-1);
	if (c == '%' && var->att == -1)
		ret += ft_print_flag(var->prec, ' ');
	ret += ret2;
	return (ret);
}

int		ft_cas_particuliers(char c, t_var *var, va_list aq, int *nb)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (c == 'd' || c == 'i')
	{
		*nb = va_arg(aq2, int);
		if (*nb < 0)
			var->larg--;
		else if (*nb == 0 && var->prec == 0 && var->larg == 0)
			return (0);
	}
	else
	{
		if (ft_cas_part2(c, var, aq) == 0)
			return (0);
	}
	return (1);
}

int		ft_cas_part2(char c, t_var *var, va_list aq)
{
	va_list	aq2;

	va_copy(aq2, aq);
	if (c == 'u' || c == 'x' || c == 'X')
	{
		if (va_arg(aq2, unsigned int) == 0 && var->prec == 0 && var->larg == 0)
			return (0);
	}
	else if (c == 'p')
	{
		if (var->prec == 0 && var->larg > 0
				&& (unsigned long)(va_arg(aq2, void *)) == 0)
			var->larg -= 1;
		else
			var->larg -= 2;
	}
	return (1);
}

int		ft_print_att(t_var *var, int *nb, char c, int *len)
{
	int		ret;

	ret = 0;
	if (var->att == 0)
	{
		if ((c == 'd' || c == 'i') && *nb < 0)
		{
			ft_putchar('-');
			ret++;
		}
		ret += ft_print_flag(var->larg - var->prec - *len, '0');
	}
	else if (var->att == 1)
		ret += ft_print_flag(var->larg - var->prec - *len, ' ');
	return (ret);
}
