/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakama <nakama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:06:30 by csteudin          #+#    #+#             */
/*   Updated: 2026/08/18 12:09:28 by nakama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void        ft_free_2d(char **arr)
{
    int i;

    i = 0;
    if (arr == NULL)
        return ;
    while(arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
