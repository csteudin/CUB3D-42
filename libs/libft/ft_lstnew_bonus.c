/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:40:52 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:54:53 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lsnew;

	lsnew = (t_list *)malloc(sizeof(t_list));
	if (!lsnew)
		return (NULL);
	lsnew->content = content;
	lsnew->next = NULL;
	return (lsnew);
}
