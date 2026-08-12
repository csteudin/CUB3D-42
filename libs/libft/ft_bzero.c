/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:08:47 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/05 10:12:18 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t nb)
{
	int		i;
	t_uint8	*vptr;

	i = 0;
	vptr = (t_uint8 *)ptr;
	while (i < (int)nb)
	{
		vptr[i] = 0;
		i++;
	}
}
