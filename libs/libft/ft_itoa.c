/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:16:14 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:50:16 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	numlen(int num, size_t *len)
{
	if (num / 10)
		numlen(num / 10, len);
	(*len)++;
	return (*len);
}

static size_t	ft_numlen(int num)
{
	size_t	len;

	len = 0;
	numlen(num, &len);
	if (num < 0)
		len++;
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*result;
	size_t	len;
	int		flag;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(nb);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	flag = 1;
	result[len] = '\0';
	if (nb < 0)
		flag = -1;
	nb = nb * flag;
	while (len)
	{
		result[len - 1] = (char)(nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	if (flag == -1)
		result[0] = '-';
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	int nb = -2147483648;
// 	printf("%s\n", ft_itoa(nb));
// 	printf("%zu\n", ft_numlen(nb));

// 	return (0);
// }