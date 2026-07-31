/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:12:38 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/05 11:12:58 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	x;

	i = 0;
	while (dest[i])
		i++;
	x = 0;
	while (src[x])
		dest[i++] = src[x++];
	dest[i] = 0;
	return (dest);
}
