/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:08:14 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 17:08:16 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	x;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		x = 0;
		while ((haystack[i + x] == needle[x]) && haystack[i + x])
		{
			if (!needle[x + 1])
				return ((char *)&haystack[i]);
			x++;
		}
		i++;
	}
	return (0);
}
