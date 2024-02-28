/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:53:31 by maiahmed          #+#    #+#             */
/*   Updated: 2023/11/15 10:53:31 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (free(ptr), NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
