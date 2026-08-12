/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:12:45 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/05 11:29:43 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	t_uint8	*mem;
	size_t	i;

	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)(mem));
}
