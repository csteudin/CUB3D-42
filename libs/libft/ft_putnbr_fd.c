/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:24:12 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:51:06 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	sign;
	char	res;

	if (!fd)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	sign = '-';
	if (n < 0)
	{
		n = n * -1;
		write(fd, (void *)&sign, 1);
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	res = ((n % 10) + 48);
	write(fd, (void *)&res, 1);
}

// int	main(void)
// {
// 	int	num = -2147483648;
// 	ft_putnbr_fd(num, 1);
// 	return (0);
// }
