/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:23:15 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 21:46:17 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*node;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	node = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (new == NULL)
		{
			ft_lstclear(&node, (*del));
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&node, new);
		lst = lst->next;
	}
	return (node);
}
