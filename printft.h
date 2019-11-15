/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:59:21 by aduchemi          #+#    #+#             */
/*   Updated: 2019/11/15 12:58:33 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

void	ft_arg(const char *s, int *i);
int		ft_dollar(const char *s);
void	ft_conversion(const char *s, int *i);
void	ft_flag(const char *s, int *i, int dol, int indice);
int		ft_len_int(int n);
int		ft_gestion(const char *s, int dol);
int		ft_format_dol(const char *s, int *i);

#endif
