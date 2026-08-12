/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:04:56 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/13 16:07:54 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	if (!s || s[0] == '\0')
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (*(s + i) != c)
		{
			count++;
			while ((*(s + i)) && (*(s + i) != c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	get_word(const char *s, char c)
{
	int	i;

	i = 0;
	while ((*(s + i)) && (*(s + i) != c))
		i++;
	return (i);
}

static void	free_mem(int words, char **arr)
{
	while (words >= 0)
	{
		free(arr[words]);
		words--;
	}
	free(arr);
}

static char	**up_split(const char *s, char c, char **arr, int words)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[x] && i < words)
	{
		while (s[x] == c)
			x++;
		arr[i] = ft_substr(s, x, get_word(&*(s + x), c));
		if (arr[i] == NULL)
		{
			free_mem(i, arr);
			return (NULL);
		}
		while (s[x] && s[x] != c)
			x++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (up_split(s, c, arr, words));
}

// #include <stdio.h>
// int main(void)
// {
// 	// char *s = "\0aa\0bbb!";
// 	char **w;
// 	w = ft_split("hello!", ' ');
// 	// printf("=> %d\n", count_words(s, ' '));
// 	// char *arr = "\0aa\0bbb!";
// 	// char c = '\0';
// 	// int i;
// 	// i = 0;
// 	// char **res = ft_split(arr, c);
// 	// while(res[i])
// 	// {
// 	// 	printf("%s\n", res[i]);
// 	// 	i++;
// 	// }
// 	return (0);
// }
