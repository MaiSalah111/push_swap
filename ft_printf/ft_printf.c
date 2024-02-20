/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:12:46 by maiahmed          #+#    #+#             */
/*   Updated: 2024/01/22 19:59:07 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier_checker(char c, va_list *args, int *len, int *i)
{
	if (c == 's')
		ft_str(va_arg(*args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnum(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_hexa(va_arg(*args, unsigned int), len, c);
	else if (c == 'p')
		ft_pointer(va_arg(*args, unsigned long), len);
	else if (c == 'c')
		ft_ch(va_arg(*args, int), len);
	else if (c == '%')
		ft_ch('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_specifier_checker(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_ch((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
