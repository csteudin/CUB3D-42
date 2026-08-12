/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:36:11 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 16:48:30 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base_len(unsigned int num, char *base, int *res)
{
	int	len;
	int	temp;

	len = ft_strlen(base);
	if (num / len != 0)
		ft_putnbr_base_len(num / len, base, res);
	if (*res == -1)
		return (*res);
	temp = write(1, &base[num % len], 1);
	if (temp == -1)
	{
		*res = temp;
		return (*res);
	}
	*res += temp;
	return (*res);
}

// int ft_putadress(unsigned long num)
// {
// 	int res;

// }

int	ft_putadress(unsigned long num)
{
	int		res;
	int		i;
	char	str[16];

	i = 0;
	res = 0;
	if (!num)
		return (write(1, "0", 1));
	while (num)
	{
		if (num % 16 < 10)
			str[i] = '0' + (num % 16);
		else
			str[i] = 'a' + num % 16 - 10;
		i++;
		num /= 16;
	}
	res = i;
	while (i--)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (res);
}
