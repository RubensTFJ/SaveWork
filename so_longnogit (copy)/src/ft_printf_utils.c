/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:16:59 by rteles-f          #+#    #+#             */
/*   Updated: 2022/12/10 22:12:40 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_case(va_list *arg_list)
{
	int	c;

	c = va_arg(*arg_list, int);
	return (write(1, &c, 1));
}

int	string_case(va_list *arg_list)
{
	char	*string;
	int		i;

	string = va_arg(*arg_list, char *);
	i = 0;
	if (!string)
		string = "(null)";
	while (string[i])
		i++;
	return (write(1, string, i));
}

int	put_base_number(t_ull n, char *base, size_t bsize)
{
	int	counter;

	counter = 0;
	if (n >= bsize)
		counter = put_base_number((n / bsize), base, bsize);
	return ((counter + write(1, &base[n % bsize], 1)));
}

int	int_case(va_list *arg_list)
{
	long long	number;
	int			counter;

	counter = 0;
	number = va_arg(*arg_list, int);
	if (number < 0)
	{
		counter += write(1, "-", 1);
		number = -number;
	}
	counter += put_base_number(number, DEX, 10);
	return (counter);
}

int	pointer_case(size_t number)
{
	if (!number)
		return (write(1, "(nil)", 5));
	return (write (1, "0x", 2) + put_base_number(number, HEX, 16));
}
