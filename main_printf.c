/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:04:58 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/15 15:14:00 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/libft.h"
#include "printft.h"

int		ft_len_int(int n)
{
	int		i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_flag(const char *s, int *i, int dol, int indice)
{	
	int		nb;

	if (ft_isdigit(s[*i]) && s[*i] != '0')
	{
		nb = ft_format_dol(s, i);
		indice == 1 ? printf("largeur %d\n", nb) : printf("precision %d\n", nb);
	}
	else if (s[*i] == '*')
	{
		*i = *i + 1;
		if (dol == 0)
			indice == 1 ? printf("largeur *\n") : printf("precision *\n");
		else if (dol == 1)
		{
			nb = ft_format_dol(s, i);
			indice == 1 ? printf("largeur *m$\n") : printf("precision *m$\n");
		}
	}
}

void	ft_conversion(const char *s, int *i)
{
	if (s[*i] == 'c' || s[*i] == 's')
		printf("gestion char\n");
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'u')
		printf("gestion nb\n");
	else if (s[*i] == 'x' || s[*i] == 'X')
		printf("gestion hexadecimal\n");
	else if (s[*i] == 'p')
		printf("gestion pointeur\n");
	else if (s[*i] == '%')
		printf("double prct\n");
}

int		ft_format_dol(const char *s, int *i)
{
	int		nb;

	nb = 0;
	if (ft_isdigit(s[*i]) && s[*i] != '0')
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		if (s[*i + ft_len_int(nb)] == '$')
			*i = *i + ft_len_int(nb) + 1;
		else
			*i = *i + ft_len_int(nb);
		return (nb);
	}
	return (0);
}

int		ft_dollar(const char *s)
{
	int		i;
	int		nb;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	if (s[i] == '%')
	{
		i++;
		if (ft_isdigit(s[i]) && s[i] != '0')
		{
			nb = ft_atoi(ft_substr(s, i, ft_strlen(s)));
			if (s[i + ft_len_int(nb)] == '$')
				return (1);
		}
	}
	return (0);
}

void	ft_arg(const char *s, int *i)
{
	int		nb;

	if (ft_isdigit(s[*i]) && s[*i] != 0)
	{
		nb = ft_atoi(ft_substr(s, *i, ft_strlen(s)));
		printf("arg =  %d\n", nb);
		*i = *i + ft_len_int(nb) + 1;
	}
}

void	ft_printf(const char *s, ...)
{
//	char		*str;
	va_list 	ap;
	int			i;
//	int			nb;
	int			dol;

	//dollar?
	dol = ft_dollar(s);
	//gestion erreurs
	if (ft_gestion(s, dol) == 0)
	{
		va_start(ap, s);
		i = 0;
		while (s[i])
		{
			if (s[i] != '%')
				ft_putchar(s[i]);
			else
			{
				i++;
				ft_putchar('\n');
				if (dol == 1)
					ft_arg(s, &i);
			//attributs
				if (s[i] == '-' || s[i] == '0')
				{
					printf("attributs\n");
					i++;
				}
			//largeur
				ft_flag(s, &i, dol, 1);
			//precision
				if (s[i] == '.')
				{
					i++;
					ft_flag(s, &i, dol, 2);
				}
				ft_conversion(s, &i);
			}
			i++;
		}
		va_end(ap);
	}
	else
		printf("erreur\n");
}
/*
int		ft_dynamique()
{
	str = ft_substr(s, i, ft_strlen(s));
	nb = ft_atoi(str);
	count = 0;
	while (count != nb)
	{
		str = va_arg(ap, char *);
		count++;
	}
}
*/
int		main()
{
	ft_printf("hello %1$05.*5$s Llop\n", "lol");

	return (0);
}
