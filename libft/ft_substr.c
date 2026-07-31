/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:32:17 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:53:02 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned long long	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len--)
	{
		str[i++] = s[start++];
	}
	str[i] = 0;
	return (str);
}

// int main(void)
// {
// 	ft_substr("hola", 4294967295, 18446744073709551615);
// }
