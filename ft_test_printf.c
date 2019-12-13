/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:38:39 by hbaudet           #+#    #+#             */
/*   Updated: 2019/12/13 17:37:35 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#ifndef STRING
# define STRING "this is a string"
#endif

int	main(int ac, char *av[])
{
	int				i;
	int				c[2][350];
	unsigned int	u = 4147483647;
	char			str[] = STRING;
	unsigned char	ch;
	unsigned long	tmp;

	tmp = 140732898131832;
	i = 1;
	(void)ac;
	(void)av;
	ch = 0;
/*	while (ch < 255)
	{
		if (ch != 10 && ch != 13)
		{
			printf("%d\t%%c\t\t\t: |%c|\n", i, ch);
			ft_printf("%d\t%%c\t\t\t: |%c|", i, ch);
			i++;
			printf("\n");
		}
		ch++;
//	}
///	else
//	{
*/		printf("CHARARCTERS : \n");
		c[0][i] = printf("%d: |%c|\n", i, 'g');
		c[1][i] = ft_printf("%d: |%c|\n", i, 'g');
		i++;
		c[0][i] = printf("%d\t%%-8c\t\t: |%-8c|\n", i, 'g');
		c[1][i] = ft_printf("%d\t%%-8c\t\t: |%-8c|\n", i, 'g');
		i++;
		c[0][i] = printf("%d\t%%*c\t\t\t: |%*c|\n", i, -4, 'g');
		c[1][i] = ft_printf("%d\t%%*c\t\t\t: |%*c|\n", i, -4, 'g');
		i++;
		printf("\n\nNON-NULL POINTERS : \n");
	
		c[0][i] = printf("%%-27d\t\t: |%d|\n", -158);
		c[1][i] = ft_printf("%%-27d\t\t: |%d|\n", -158);
		i++;
		c[0][i] = printf("%d\t%%-27X\t\t: |%-27X|\n", i, 49);
		c[1][i] = ft_printf("%d\t%%-27X\t\t: |%-27X|\n", i, 49);
		i++;
		c[0][i] = printf("%d\t%%-27p\t\t: |%-27p|\n", i, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%-27p\t\t: |%-27p|\n", i, (void *)tmp);
		i++;
		c[0][i] = printf("%d\t%%-*p\t\t: |%-*p|\n", i, 18, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%-*p\t\t: |%-*p|\n", i, 18, (void *)tmp);
		i++;
		c[0][i] = printf("%d\t%%-*p\t\t: |%-*p|\n", i, 18, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%-*p\t\t: |%-*p|\n", i, 18, (void *)tmp);
		i++;
		c[0][i] = printf("%d\t%%14p\t\t: |%14p|\n", i, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%14p\t\t: |%14p|\n", i, (void *)tmp);
		i++;
		//10
		c[0][i] = printf("%d\t%%2p\t\t\t: |%2p|\n", i, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%2p\t\t\t: |%2p|\n", i, (void *)tmp);
		i++;
		c[0][i] = printf("%d\t%%*p\t\t\t: |%*p|\n", i, 18, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%*p\t\t\t: |%*p|\n", i, 18, (void *)tmp);
		i++;
		c[0][i] = printf("%d\t%%p\t\t\t: |%p|\n", i, (void *)tmp);
		c[1][i] = ft_printf("%d\t%%p\t\t\t: |%p|\n", i, (void *)tmp);
		i++;
		printf("\n\nNULL POINTERS : \n");
		c[0][i] = printf("%d\t%%-27p\t\t: |%-27p|\n", i, NULL);
		c[1][i] = ft_printf("%d\t%%-27p\t\t: |%-27p|\n", i, NULL);
		i++;
		c[0][i] = printf("%d\t%%-*p\t\t: |%-*p|\n", i, 18, NULL);
		c[1][i] = ft_printf("%d\t%%-*p\t\t: |%-*p|\n", i, 18, NULL);
		i++;
		c[0][i] = printf("%d\t%%14p\t\t: |%14p|\n", i, NULL);
		c[1][i] = ft_printf("%d\t%%14p\t\t: |%14p|\n", i, NULL);
		i++;
		c[0][i] = printf("%d\t%%2p\t\t\t: |%2p|\n", i, NULL);
		c[1][i] = ft_printf("%d\t%%2p\t\t\t: |%2p|\n", i, NULL);
		i++;
		c[0][i] = printf("%d\t%%*p\t\t\t: |%*p|\n", i, 18, NULL);
		c[1][i] = ft_printf("%d\t%%*p\t\t\t: |%*p|\n", i, 18, NULL);
		i++;
		printf("\n\nINTEGERS : \n\n");
		c[0][i] = printf("\t%%0.0d\t\t: |%0.0d|\n", 0);
		c[1][i] = ft_printf("\t%%0.0d\t\t: |%0.0d|\n", 0);
		i++;
		c[0][i] = printf("\t%%0.5d\t\t: |%0.5d|\n", 0);
		c[1][i] = ft_printf("\t%%0.5d\t\t: |%0.5d|\n", 0);
		i++;
		//20
		c[0][i] = printf("\t%%.0d\t\t: |%.0d|\n", 0);
		c[1][i] = ft_printf("\t%%.0d\t\t: |%.0d|\n", 0);
		i++;
		c[0][i] = printf("\t%%d\t\t: |%d|\n", 0);
		c[1][i] = ft_printf("\t%%d\t\t: |%d|\n", 0);
		i++;
		c[0][i] = printf("\t%%0d\t\t: |%0d|\n", 0);
		c[1][i] = ft_printf("\t%%0d\t\t: |%0d|\n", 0);
		i++;
		c[0][i] = printf("\t%%.0d\t\t: |%.0d|\n", 0);
		c[1][i] = ft_printf("\t%%.0d\t\t: |%.0d|\n", 0);
		i++;
		c[0][i] = printf("%d\t%%.0d\t\t: |%15.0d|\n", i, 0);
		c[1][i] = ft_printf("%d\t%%.0d\t\t: |%15.0d|\n", i, 0);
		i++;
		c[0][i] = printf("%d\t%%08.3d\t\t: |%08.3d|\n", i, 45);
		c[1][i] = ft_printf("%d\t%%08.3d\t\t: |%08.3d|\n", i, 45);
		i++;
		c[0][i] = printf("%d\t%%.*d\t\t: |%.*d|\n", i, 4, 23);
		c[1][i] = ft_printf("%d\t%%.*d\t\t: |%.*d|\n", i, 4, 23);
		i++;
		c[0][i] = printf("%d\t%%.1d\t\t: |%.1d|\n", i, 17);
		c[1][i] = ft_printf("%d\t%%.1d\t\t: |%.1d|\n", i, 17);
		i++;
		c[0][i] = printf("%d\t%%8.3d\t\t: |%8.3d|\n", i, 45);
		c[1][i] = ft_printf("%d\t%%8.3d\t\t: |%8.3d|\n", i, 45);
		i++;
		c[0][i] = printf("%d\t%%.*d\t\t: |%.*d|\n", i, 4, 789);
		c[1][i] = ft_printf("%d\t%%.*d\t\t: |%.*d|\n", i, 4, 789);
		i++;
		c[0][i] = printf("%d\t%%05d\t\t: |%05d|\n", i, 2);
		c[1][i] = ft_printf("%d\t%%05d\t\t: |%05d|\n", i, 2);
		i++;
		///30
		c[0][i] = printf("%d\t%%00d\t\t: |%00d|\n", i, 78);
		c[1][i] = ft_printf("%d\t%%00d\t\t: |%00d|\n", i, 78);
		i++;
		c[0][i] = printf("%d\t%%0.0d\t\t: |%0.0d|\n", i, 123);
		c[1][i] = ft_printf("%d\t%%0.0d\t\t: |%0.0d|\n", i, 123);
		i++;
		printf("\n\nUNSIGNED INTS : \n");
		c[0][i] = printf("%d\t%%03.0u\t\t: |%03.0u|\n", i, 0);
		c[1][i] = ft_printf("%d\t%%03.0u\t\t: |%03.0u|\n", i, 0);
		i++;
		c[0][i] = printf("%d\t%%.2u\t\t: |%.2u|\n", i, u);
		c[1][i] = ft_printf("%d\t%%.2u\t\t: |%.2u|\n", i, u);
		i++;
		c[0][i] = printf("%d\t%%010.10u\t: |%010.10u|\n", i, u);
		c[1][i] = ft_printf("%d\t%%010.10u\t: |%010.10u|\n", i, u);
		i++;
		c[0][i] = printf("%d\t%%-10.10u\t: |%-10.10u|\n", i, u);
		c[1][i] = ft_printf("%d\t%%-10.10u\t: |%-10.10u|\n", i, u);
		i++;
		c[0][i] = printf("%d\t%%*.6u\t\t: |%*.6u|\n", i, 4, u);
		c[1][i] = ft_printf("%d\t%%*.6u\t\t: |%*.6u|\n", i, 4, u);
		i++;
		c[0][i] = printf("%d\t%%0*.2u\t\t: |%0*.2u|\n", i, 2, u);
		c[1][i] = ft_printf("%d\t%%0*.2u\t\t: |%0*.2u|\n", i, 2, u);
		i++;
		c[0][i] = printf("HELLO %d\t%%.0u\t\t: |%.0u|\n", i, 15);
		c[1][i] = ft_printf("HELLO %d\t%%.0u\t\t: |%.0u|\n", i, 15);
		i++;
		printf("\n\nHEXA : \n");
		c[0][i] = printf("\"%5.x\"\n", 0);
		c[1][i] = ft_printf("\"%5.x\"\n", 0);
		i++;
		c[0][i] = printf("\"%5.d\"\n", 0);
		c[1][i] = ft_printf("\"%5.d\"\n", 0);
		i++;
//		c[0][i] = printf("%.d %.0d\"\n", 0, 0);
		c[0][i] = printf("%%.d:%.d\"\n", 0);
		c[1][i] = ft_printf("%%.d:%.d\"\n", 0);
		i++;
		c[0][i] = printf("%%.0d:%.0d\"\n", 0);
		c[1][i] = ft_printf("%%.0d:%.0d\"\n", 0);
		i++;
		c[0][i] = printf("%%d:%d\"\n", 0);
		c[1][i] = ft_printf("%%d:%d\"\n", 0);
		i++;
		c[0][i] = printf("%%5.x:%5.x\"\n", 0);
		c[1][i] = ft_printf("%%5.x:%5.x\"\n", 0);
		i++;
		c[0][i] = printf("%%5.d:%5.d\"\n", 0);
		c[1][i] = ft_printf("%%5.d:%5.d\"\n", 0);
		i++;
		c[0][i] = printf("%%5.x:%5.x\"\n", 42);
		c[1][i] = ft_printf("%%5.x:%5.x\"\n", 42);
		i++;
//		c[1][i] = ft_printf("%.d %.0d\"\n", 0, 0);
		c[0][i] = printf("%d\t%%10x\t\t:	|%10x|\n", i, -20);
		c[1][i] = ft_printf("%d\t%%10x\t\t:	|%10x|\n", i, -20);
		i++;
		//40
		c[0][i] = printf("%d\t%%10.25x\t\t:	|%10.25x|\n", i, -20);
		c[1][i] = ft_printf("%d\t%%10.25x\t\t:	|%10.25x|\n", i, -20);
		i++;
		c[0][i] = printf("%d\t%%10.25d\t\t:	|%10.25d|\n", i, -20);
		c[1][i] = ft_printf("%d\t%%10.25d\t\t:	|%10.25d|\n", i, -20);
		i++;
		c[0][i] = printf("%d\t%%10.25x\t\t:	|%10.25x|\n", i, 20);
		c[1][i] = ft_printf("%d\t%%10.25x\t\t:	|%10.25x|\n", i, 20);
		i++;
		c[0][i] = printf("%d\t%%*.*x\t\t:	|%*.*x|\n", i, 50, 10, 2);
		c[1][i] = ft_printf("%d\t%%*.*x\t\t:	|%*.*x|\n", i, 50, 10, 2);
		i++;
		c[0][i] = printf("%d\t%%8.4x\t\t:	|%8.4x|\n", i, 0);
		c[1][i] = ft_printf("%d\t%%8.4x\t\t:	|%8.4x|\n", i, 0);
		i++;
		c[0][i] = printf("%d\t%%8.4d\t\t:	|%8.4d|\n", i, 0);
		c[1][i] = ft_printf("%d\t%%8.4d\t\t:	|%8.4d|\n", i, 0);
		i++;
		c[0][i] = printf("%d\t%%8.4u\t\t:	|%8.4u|\n", i, 0);
		c[1][i] = ft_printf("%d\t%%8.4u\t\t:	|%8.4u|\n", i, 0);
		i++;
/*		printf("%d d |%d|\n", i, 0);
		printf("%d x |%x|\n", i, 0);
		printf("%d u |%u|\n", i, 0);
		printf("%d .0d |%.0d|\n", i, 0);
		printf("%d .0x |%.0x|\n", i, 0);
		printf("%d .0u |%.0u|\n", i, 0);
		printf("%d 0.0d |%0.0d|\n", i, 0);
		printf("%d 0.0x |%0.0x|\n", i, 0);
		printf("%d 0.0u |%0.0u|\n", i, 0);
		printf("%d 0d |%0d|\n", i, 0);
		printf("%d 0x |%0x|\n", i, 0);
		printf("%d 0u |%0u|\n", i, 0);
		printf("%d .10d |%.10d|\n", i, 0);
		printf("%d .10x |%.10x|\n", i, 0);
		printf("%d .10u |%.10u|\n", i, 0);
		printf("%d -.10d |%-.10d|\n", i, 0);
		printf("%d -.10x |%-.10x|\n", i, 0);
		printf("%d -.10u |%-.10u|\n", i, 0);
		printf("%d 10d |%10d|\n", i, 0);
		printf("%d 10x |%10x|\n", i, 0);
		printf("%d 10u |%10u|\n", i, 0);
		printf("%d 010d |%010d|\n", i, 0);
		printf("%d 010x |%010x|\n", i, 0);
		printf("%d 010u |%010u|\n\n\n", i, 0);

		ft_printf("d |%d|\n", 0);
		ft_printf("x |%x|\n", 0);
		ft_printf("u |%u|\n", 0);
		ft_printf(".0d |%.0d|\n", 0);
		ft_printf(".0x |%.0x|\n", 0);
		ft_printf(".0u |%.0u|\n", 0);
		ft_printf("0.0d |%0.0d|\n", 0);
		ft_printf("0.0x |%0.0x|\n", 0);
		ft_printf("0.0u |%0.0u|\n", 0);
		ft_printf("0d |%0d|\n", 0);
		ft_printf("0x |%0x|\n", 0);
		ft_printf("0u |%0u|\n", 0);
		ft_printf(".10d |%.10d|\n", 0);
		ft_printf(".10x |%.10x|\n", 0);
		ft_printf(".10u |%.10u|\n", 0);
		ft_printf("-.10d |%-.10d|\n", 0);
		ft_printf("-.10x |%-.10x|\n", 0);
		ft_printf("-.10u |%-.10u|\n", 0);
		ft_printf("10d |%10d|\n", 0);
		ft_printf("10x |%10x|\n", 0);
		ft_printf("10u |%10u|\n", 0);
		ft_printf("010d |%010d|\n", 0);
		ft_printf("010x |%010x|\n", 0);
		ft_printf("010u |%010u|\n\n\n", 0);
*/
		c[0][i] = printf("%d	%x\n", i, 2147483647);
		c[1][i]=ft_printf("%d	%x\n", i, 2147483647);
		i++;
		c[0][i]=printf("%d	%X\n", i, 2147483647);
		c[1][i]=ft_printf("%d	%X\n", i, 2147483647);
		i++;
		c[0][i]=printf("ici %d	%x\n", i, 0);
		c[1][i]=ft_printf("ici %d	%x\n", i, 0);
		i++;
		c[0][i]=printf("%010x\n", 0);
		c[1][i]=ft_printf("%010x\n", 0);
		i++;
		//50
		c[0][i]=printf("%010x\n", 20);
		c[1][i]=ft_printf("%010x\n", 20);
		i++;
		c[0][i]=printf("%010x\n", -20);
		c[1][i]=ft_printf("%010x\n", -20);
		i++;
		c[0][i]=printf("%d\thexa \t\t: |%.0x|\n", i, 0);
		c[1][i]=ft_printf("%d\thexa \t\t: |%.0x|\n", i, 0);
		i++;
		c[0][i]=printf("%d\t%%.2x\t\t: |%.0x|\n", i, 0);
		c[1][i]=ft_printf("%d\t%%.2x\t\t: |%.0x|\n", i, 0);
		i++;
		c[0][i]=printf("hexa \t\t: |%.0x|\n", 0);
		c[1][i]=ft_printf("hexa \t\t: |%.0x|\n", 0);
		i++;
		c[0][i]=printf("%dHERE hexa \t\t: |%.15x|\t\t%% |%10X|\n", i, u, u);
		c[1][i]=ft_printf("%dHERE hexa \t\t: |%.15x|\t\t%% |%10X|\n", i, u, u);
	//	c[1][i]=ft_printf("HERE hexa %%.15x\t%%10X: |%.15x|\t|%10X|\n", u, u);
		i++;
		c[0][i]=printf("HERE hexa %%-10x\t%%20.15X: |%-10x|\t|%20.15X|\n", u, u);
		c[1][i]=ft_printf("HERE hexa %%-10x\t%%20.15X: |%-10x|\t|%20.15X|\n", u, u);
		i++;
		c[0][i]=printf("%%2.0x\t\t: |%2.0x|\n",100);
		c[1][i]=ft_printf("%%2.0x\t\t: |%2.0x|\n", 100);
		i++;
		c[0][i]=printf("et la %d\t%%2.0x\t\t: |%2.0x|\n", i, 0);
		c[1][i]=ft_printf("et la %d\t%%2.0x\t\t: |%2.0x|\n", i, 0);
		i++;
		c[0][i]=printf("test int %d\t%%2.0d\t\t: |%2.0d|\n", i, 0);
		c[1][i]=ft_printf("test int %d\t%%2.0d\t\t: |%2.0d|\n", i, 0);
		i++;
		c[0][i]=printf("test u %d\t%%2.0u\t\t: |%2.0u|\n", i, 0);
		c[1][i]=ft_printf("test u %d\t%%2.0u\t\t: |%2.0u|\n", i, 0);
		i++;
		printf("\n\nSTRINGS : \n");
		c[0][i]=printf("%d\t%%.4s\t\t: |%4c|\n", i, 'c');
		c[1][i]=ft_printf("%d\t%%.4s\t\t: |%4c|\n", i, 'c');
		i++;
		//60
		c[0][i]=printf("%d\t%%.4s\t\t: |%.4s|\n", i, NULL);
		c[1][i]=ft_printf("%d\t%%.4s\t\t: |%.4s|\n", i, NULL);
		i++;
		c[0][i]=printf("%d\t%%.*s\t\t: |%.*s|\n", i, 8, str);
		c[1][i]=ft_printf("%d\t%%.*s\t\t: |%.*s|\n", i, 8, str);
		i++;
		c[0][i]=printf("%d%%.*s\t\t: |%.*s|\n", i, 8, str);
		c[1][i]=ft_printf("%d%%.*s\t\t: |%.*s|\n", i, 8, str);
		i++;
		c[0][i]=printf("%d\t%%25s\t\t: |%25s|\n", i, str);
		c[1][i]=ft_printf("%d\t%%25s\t\t: |%25s|\n", i, str);
		i++;
		c[0][i]=printf("%d\t%%-24.4s\t\t: |%-25.4s|\n", i, str);
		c[1][i]= ft_printf("%d\t%%-24.4s\t\t: |%-25.4s|\n", i, str);
		i++;
		c[0][i]=printf("%d\t%%-24s\t\t: |%-25s|\n", i, str);
		c[1][i]=ft_printf("%d\t%%-24s\t\t: |%-25s|\n", i, str);
		i++;
		c[0][i]=printf("%d\t%%25.0s\t\t: |%25.0s|\n", i, str);
		c[1][i]=ft_printf("%d\t%%25.0s\t\t: |%25.0s|\n", i, str);
		i++;
		c[0][i]=printf("%d\t%%.0s\t\t: |%.0s|\n", i, str);
		c[1][i]=ft_printf("%d\t%%.0s\t\t: |%.0s|\n", i, str);
		i++;
		c[0][i]=printf("%d\t%%*s\t\t\t: |%*s|\n", i, 0, str);
		c[1][i]=ft_printf("%d\t%%*s\t\t\t: |%*s|\n", i, 0, str);
		i++;
		c[0][i]=printf("%d\t%%s\t\t: |%s|\n", i, str);
		c[1][i]=ft_printf("%d\t%%s\t\t: |%s|\n", i, str);
		i++;
		c[0][i]=printf("%d\t%%s\t\t\t: Hello 42 school! |%s|\n", i, NULL);
		c[1][i]=ft_printf("%d\t%%s\t\t\t: Hello 42 school! |%s|\n", i, NULL);
		i++;
		printf("\n\n%% : \n");
		c[0][i]=printf("%d\t%%5%%\t\t\t: |%5%|\n", i);
		c[1][i]=ft_printf("%d\t%%5%%\t\t\t: |%5%|\n", i);
		i++;
		c[0][i]=printf("%d\t%%-5%%\t\t: |%-5%|\n", i);
		c[1][i]=ft_printf("%d\t%%-5%%\t\t: |%-5%|\n", i);
		i++;
		c[0][i]=printf("%d\t%%05%%\t\t: |%05%|\n", i);
		c[1][i]=ft_printf("%d\t%%05%%\t\t: |%05%|\n", i);
		i++;
		printf("\nTESTS 2\n");
	//	c[0][i]=printf("**************%*s%*d**************%*u*************\n", 10, "coucou", 10, 0, -50, 20);
		c[0][i]=printf("%*d %*u\n", 5, 10, 5, 20);
		c[1][i]=ft_printf("%*d %*u\n", 5, 10, 5, 20);
		i++;
		c[0][i]=printf("**************%*d %*u***************************\n", 5, 10, 5, 20);
		c[1][i]=ft_printf("**************%*d %*u***************************\n", 5, 10, 5, 20);
		i++;
		c[0][i]=printf("**************%*u***************************\n", 5, 10);
		c[1][i]=ft_printf("**************%*u***************************\n", 5, 10);
		i++;
		c[0][i]=printf("**************%*d***************************\n", 5, 20);
		c[1][i]=ft_printf("**************%*d***************************\n", 5, 20);
		i++;
		c[0][i]=printf("%50.2s\n", NULL);
		c[1][i]=ft_printf("%50.2s\n", NULL);
		i++;
		c[0][i]=printf("%50.2s\n", "lol");
		c[1][i]=ft_printf("%50.2s\n", "lol");
		i++;
		//MYSTERE
	/*	c[0][i]=printf("%%*.*x %%*.*X  %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
		c[1][i]=ft_printf("%%*.*x %%*.*X  %*.*x %*.*X\n\n", 1, 50, 5000, 1, 0, 10);
		i++;
		c[0][i]=printf("%%.*x %%*.*X  %.*x %*.*X\n", 50, 5000, 1, 0, 10);
		c[1][i]=ft_printf("%%.*x %%*.*X  %.*x %*.*X\n\n", 50, 5000, 1, 0, 10);
		i++;
*/
	printf("\n\nRETURN VALUES :\n");
	for (int p = 1; p < i ; p++)
	{
		printf("%d\t: %d\n", p, c[0][p]);
		printf("%d\t: %d\n", p, c[1][p]);
	}
	return (0);
}
/*
__attribute__((destructor)) void loop()
{
	while(1);
}*/
