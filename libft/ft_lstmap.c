/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiahmed <maiahmed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:55:46 by maiahmed          #+#    #+#             */
/*   Updated: 2023/11/18 15:03:59 by maiahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean_up(t_list **new_list, void *content, void (*del)(void *))
{
	if (content)
		del(content);
	ft_lstclear(new_list, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
	{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			clean_up(&new_list, NULL, del);
			return (NULL);
		}
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			clean_up(&new_list, content, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
