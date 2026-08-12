/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteudin <csteudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:54:45 by csteudin          #+#    #+#             */
/*   Updated: 2024/03/27 16:48:39 by csteudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_module(char c, va_list args)
{
	if (c == 'c')
		return (handle_char(args));
	else if (c == 's')
		return (handle_string(args));
	else if (c == 'p')
		return (handle_adress(args));
	else if (c == 'd')
		return (handle_base_nb(args, "0123456789"));
	else if (c == 'i')
		return (handle_base_nb(args, "0123456789"));
	else if (c == 'u')
		return (handle_un_base_nb(args, "0123456789"));
	else if (c == 'x')
		return (handle_un_base_nb(args, "0123456789abcdef"));
	else if (c == 'X')
		return (handle_un_base_nb(args, "0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	int		temp;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str && str[i] && len != -1)
	{
		if (str[i] == '%' && str[i + 1])
			temp = get_module(str[++i], args);
		else if (str[i])
			temp = write(1, &str[i], 1);
		len += temp;
		if (temp == -1)
			len = temp;
		i++;
	}
	va_end(args);
	return (len);
}

// int main(void)
// {
// 	char c;
// 	int my_len;
// 	int pf_len;
// 	char *str;

// 	c = 'A';
// 	str = (char *)NULL;

// 	my_len = ft_printf("%s\n", str);
// 	printf("%d\n", my_len);
// 	printf("***************************************************************\n");
// 	pf_len = printf("%s\n", str);
// 	printf("%d\n", pf_len);
// 	return (0);
// }