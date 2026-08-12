/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:19:49 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/07 14:30:54 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*cstr;
	int		i;

	i = 0;
	cstr = malloc(ft_strlen(str) + 1);
	if (!cstr)
		return (NULL);
	while (str[i])
	{
		cstr[i] = str[i];
		i++;
	}
	cstr[i] = '\0';
	return (cstr);
}
