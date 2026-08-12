/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:21 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 17:06:38 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_uint8		*cdest;
	t_uint8		*csrc;
	size_t		i;

	cdest = (t_uint8 *)dest;
	csrc = (t_uint8 *)src;
	i = 0;
	if ((cdest == NULL) || (csrc == NULL))
		return (NULL);
	if (n == 0)
		return (dest);
	while ((i < n))
	{
		if (csrc[i] == (t_uint8)c)
			return (dest + (i + 1));
		cdest[i] = csrc[i];
		i++;
	}
	return (NULL);
}
