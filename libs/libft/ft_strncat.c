/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:07:52 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 17:07:54 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	int	i;
	int	x;

	i = 0;
	while (dest[i])
		i++;
	x = 0;
	while (src[x] && ((unsigned int)x < n))
		dest[i++] = src[x++];
	dest[i] = 0;
	return (dest);
}
