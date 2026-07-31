/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:28:12 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/09 19:23:08 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t n)
{
	size_t	i;
	size_t	x;

	if (!ned[0])
		return ((char *)hay);
	if (!n)
		return (NULL);
	i = 0;
	while (hay[i] && i < n)
	{
		x = 0;
		while ((hay[i + x] == ned[x]) && hay[i + x] && (i + x) < n)
		{
			if (!ned[x + 1])
				return ((char *)&hay[i]);
			x++;
		}
		i++;
	}
	return (NULL);
}
