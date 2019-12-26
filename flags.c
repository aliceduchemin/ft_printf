/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:08:46 by aduchemi          #+#    #+#             */
/*   Updated: 2019/12/26 12:33:11 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_attributs(const char *s, int *i, t_var *var)
{
	while ((s[*i] == '-' || s[*i] == '0') && s[*i])
	{
		if (s[*i] == '0' && var->att != -1)
			var->att = 0;
		if (s[*i] == '-')
			var->att = -1;
		*i = *i + 1;
	}
}

void	ft_flag_larg(const char *s, int *i, t_var *var)
{
	while (ft_isdigit(s[*i]))
	{
		var->larg = var->larg * 10 + s[*i] - 48;
		*i = *i + 1;
	}
	if (s[*i] == '*')
	{
		var->larg = -1;
		*i = *i + 1;
	}
}

void	ft_flag_prec_2(const char *s, int *i, t_var *var, int *ret_prec)
{
	var->prec = 0;
	if (s[*i - 1] == '-')
	{
		while (ft_isdigit(s[*i]))
		{
			*ret_prec = *ret_prec * 10 + s[*i] - 48;
			*i = *i + 1;
		}
	}
	else
	{
		while (ft_isdigit(s[*i]))
		{
			var->prec = var->prec * 10 + s[*i] - 48;
			*i = *i + 1;
		}
	}
}

void	ft_flag_prec(const char *s, int *i, t_var *var, int *ret_prec)
{
	*i = *i + 1;
	while (s[*i] == '0')
		*i = *i + 1;
	if (s[*i] == '-')
		*i = *i + 1;
	if (ft_isdigit(s[*i]))
		ft_flag_prec_2(s, i, var, ret_prec);
	else if (s[*i] == '*')
	{
		var->prec = -1;
		*i = *i + 1;
	}
	else
		var->prec = 0;
}

int		ft_print_char(va_list aq, t_var *var, int *ret)
{
	va_list aq2;
	char	*str;
	int		j;

	va_copy(aq2, aq);
	j = 0;
	if (var->prec != -1)
	{
		str = va_arg(aq2, char *);
		if (var->prec != 0)
		{
			while (j < var->prec)
				ft_putchar(str[j++]);
		}
		else
		{
			while (str[j])
				ft_putchar(str[j++]);
		}
	}
	*ret = j;
	return (0);
}
