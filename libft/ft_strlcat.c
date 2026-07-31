/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:58 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/12 15:51:48 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	total_len;
	size_t	i;
	char	*s;

	if ((!dst || !src) && !size)
		return (0);
	s = (char *)src;
	dst_len = 0;
	while (*(dst + dst_len) && dst_len < size)
		dst_len++;
	i = 0;
	if (dst_len < size)
		total_len = dst_len + ft_strlen(s);
	else
		return (size + ft_strlen(s));
	while (src[i] && dst_len < (size - 1))
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (total_len);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t dst_len;
// 	size_t total_len;
// 	size_t i;
// 	char *s;
// 	if((!dst || !src) && !size)
// 		return (0);
// 	s = (char *)src;
// 	dst_len = 0;
// 	while (*(dst + dst_len) && dst_len < size)
// 		dst_len++;
// 	i = 0;
// 	if(dst_len < size)
// 		total_len = dst_len + ft_strlen(s);
// 	else 
// 		return (size + ft_strlen(s));
// 	while(src[i] && dst_len < (size - 1))
// 	{
// 		dst[dst_len] = src[i];
// 		dst_len++;
// 		i++;
// 	}
// 	dst[dst_len] = '\0';
// 	return (total_len);
// }
