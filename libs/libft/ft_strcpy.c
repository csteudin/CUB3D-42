/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:04:52 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 17:05:05 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		idx;
	char	*csrc;

	csrc = (char *)src;
	idx = 0;
	while (csrc[idx])
	{
		dest[idx] = csrc[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}
