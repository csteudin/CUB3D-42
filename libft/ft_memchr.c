/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:25:28 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 12:33:11 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	size_t			i;

	i = 0;
	if (!n)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char *)(str + i) == (unsigned char)ch)
			return ((void *)(str + i));
		i++;
	}
	if ((*(unsigned char *)(str + i - 1) == (unsigned char)ch) && !ch)
		return ((void *)(str + i - 1));
	return (NULL);
}
