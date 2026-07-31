/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:16:27 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:54:59 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	idx;

	idx = 0;
	if (lst)
	{
		idx = 1;
		while (lst->next != NULL)
		{
			lst = lst->next;
			idx++;
		}
	}
	return (idx);
}
