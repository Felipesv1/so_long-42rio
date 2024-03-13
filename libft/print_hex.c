/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:59:22 by felperei          #+#    #+#             */
/*   Updated: 2023/11/14 12:46:26 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	to_char(unsigned long num, int arg, int *count)
{
	const char	*hex_digits_upper = "0123456789ABCDEF";
	const char	*hex_digits_lower = "0123456789abcdef";
	char		hex;

	if (arg == 'X')
		hex = hex_digits_upper[num % 16];
	else if (arg == 'x')
		hex = hex_digits_lower[num % 16];
	else if (arg == 'p')
		hex = hex_digits_lower[num % 16];
	write(1, &hex, 1);
	(*count)++;
}

static	int	if_argument_pointer(unsigned long value)
{
	if (value == 0)
	{
		print_string("(nil)");
		return (3);
	}
	else
		return (0);
}

int	print_hex(unsigned long value, int asc)
{
	char	hex_str[16];
	int		i;
	int		count;

	count = 0;
	if (value == 0)
	{
		if (asc == 'p')
			return (if_argument_pointer(value));
		to_char(value, asc, &count);
	}
	if (asc == 'p' && value != 0)
		print_string("0x");
	i = 0;
	while (value > 0)
	{
		hex_str[i++] = value % 16;
		value /= 16;
	}
	while (--i >= 0)
		to_char(hex_str[i], asc, &count);
	return (count);
}
