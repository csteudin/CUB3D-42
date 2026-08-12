/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:22:18 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/09 18:07:51 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	y;

	y = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			y = i;
		i++;
	}
	if (str[i] == (char)ch)
		return ((char *)(str + i));
	if (y != -1)
		return ((char *)(str + y));
	return (NULL);
}
