/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:00 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 17:06:16 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	t_uint8	*temp;

	temp = (t_uint8 *)malloc(size);
	if (temp == NULL)
		return (NULL);
	while (size)
	{
		temp[size - 1] = 0;
		size--;
	}
	return ((void *)temp);
}
