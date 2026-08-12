/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:58:49 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 12:33:31 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int		i;
	t_uint8	*cptr;

	cptr = (t_uint8 *)ptr;
	i = 0;
	while (i < ((int)num))
	{
		cptr[i] = value;
		i++;
	}
	return (cptr);
}
