/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:13:00 by maiahmed          #+#    #+#             */
/*   Updated: 2023/12/05 11:07:23 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ch(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_str(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*len) = (*len) + 6;
		return ;
	}
	while (s[i] != '\0')
	{
		ft_ch(s[i], len);
		i++;
	}
}
