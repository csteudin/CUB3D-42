/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:03:56 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:57 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	char_check(char const *s1, char const *set)
{
	int	y;

	y = 0;
	while (set[y])
	{
		if (*s1 == set[y])
			return (69);
		y++;
	}
	return (0);
}

static char	*str_new(int nb)
{
	char	*str;
	int		i;

	str = (char *)malloc((sizeof(char) * nb + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		str[i] = 'A';
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && char_check ((s1 + start), set))
		start++;
	while ((end > start) && char_check((s1 + end), set))
		end--;
	str = str_new(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end + 1)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
