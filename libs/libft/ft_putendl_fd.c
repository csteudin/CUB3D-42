/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:27:34 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/07 14:13:18 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char		end;
	const void	*en;

	if (!s || !fd)
		return ;
	end = '\n';
	en = &end;
	ft_putstr_fd(s, fd);
	write(fd, en, 1);
}
