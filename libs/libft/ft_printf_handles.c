/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:07:32 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 16:48:22 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function need a cast because va_list stores chars's as integers
int	handle_char(va_list args)
{
	int		res;
	char	c;

	c = (char)va_arg(args, int);
	res = write(1, &c, 1);
	return (res);
}

// This function puts the string and handles the char *NULL error edgecase
// ?? why is it only working with (null) ??
int	handle_string(va_list args)
{
	int		res;
	char	*str;
	char	*null;

	null = "(null)";
	str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, null, 6));
	res = write(1, str, ft_strlen(str));
	return (res);
}

// This function handles negative values and goes to putnbr with normal values
int	handle_base_nb(va_list args, char *base)
{
	int		res;
	int		num;
	char	sign;

	res = 0;
	num = va_arg(args, int);
	if (num == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	sign = '-';
	if (num < 0)
	{
		res = write(1, &sign, 1);
		num = num * -1;
	}
	if (res == -1)
		return (res);
	res = ft_putnbr_base_len(num, base, &res);
	return (res);
}

// This function handles unsigned numbers and lets them overflow for hexadecimal
int	handle_un_base_nb(va_list args, char *base)
{
	int	res;
	int	num;

	res = 0;
	num = va_arg(args, int);
	res = ft_putnbr_base_len(num, base, &res);
	return (res);
}

// This function just handles hexadecimal and writes 0x before
int	handle_adress(va_list args)
{
	int				res;
	void			*val;
	unsigned long	num;
	int				temp;

	res = 0;
	val = va_arg(args, void *);
	num = (unsigned long)val;
	res = write(1, "0x", 2);
	if (res == -1)
		return (res);
	temp = ft_putadress(num);
	if (temp == -1)
		return (temp);
	res += temp;
	return (res);
}
