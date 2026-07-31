/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:27:09 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/09 18:28:40 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	if (!n)
		return (0);
	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	while (n > 1)
	{
		if (*cstr1 != *cstr2)
			return (*cstr1 - *cstr2);
		cstr1++;
		cstr2++;
		n--;
	}
	return (*cstr1 - *cstr2);
}
