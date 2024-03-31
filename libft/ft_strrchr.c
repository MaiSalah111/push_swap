/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:39:07 by maiahmed          #+#    #+#             */
/*   Updated: 2023/11/20 15:21:47 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (int)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return (str + i);
		}
		i--;
	}
	return (NULL);
}
