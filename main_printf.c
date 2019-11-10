/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/10 17:21:43 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/libft.h"

void	ft_printf(const char *s, ...)
{
	char	*str;
	va_list 	ap;
	int			i;

	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
		{
			write(1, "\n", 1);
			str = va_arg(ap, char *);
			printf("%s\n", str);
		}
		i++;
	}
	va_end(ap);
}

int		main()
{
	ft_printf("he % % % %  Llop", "l", "lo", "lol", "loli");
	return (0);
}
