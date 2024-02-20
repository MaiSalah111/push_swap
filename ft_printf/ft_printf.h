/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:12:54 by maiahmed          #+#    #+#             */
/*   Updated: 2023/12/05 11:07:15 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

void	ft_ch(char c, int *len);
void	ft_str(char *s, int *len);
void	ft_putnum(int n, int *len);
void	ft_pointer(unsigned long pointer, int *length);
void	ft_hexa(unsigned int x, int *len, char x_or_X);
void	ft_unsigned_int(unsigned int u, int *len);
int		ft_printf(const char *string, ...);

#endif
