/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:00:01 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/11 16:11:43 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nb)
{
	size_t	i;
	t_uint8	*cdest;
	t_uint8	*csrc;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	if (nb == 0)
		return (dest);
	cdest = (t_uint8 *)dest;
	csrc = (t_uint8 *)src;
	while ((i < nb))
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
