/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:58:53 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/15 20:14:19 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

void	ft_conversion(const char *s, int *i, t_var *var, va_list ap)
{
	if (s[*i] == 'c' || s[*i] == 's')
		printf("char\n");
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'u')
		ft_conv_nb(s, var, ap);
	else if (s[*i] == 'x' || s[*i] == 'X')
		printf("hexa\n");
	else if (s[*i] == 'p')
		printf("pointeur\n");
	else if (s[*i] == '%')
		printf("double prct\n");
}

void	ft_conv_nb(const char *s, t_var *var, va_list ap)
{
	va_list	aq;

	va_copy(aq, ap);
	ft_etoile_nb(s, var, aq);
}
