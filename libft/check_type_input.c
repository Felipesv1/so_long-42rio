/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:43:27 by felperei          #+#    #+#             */
/*   Updated: 2023/11/08 10:07:39 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_type_input(const char *input, int i, va_list args)
{
	if (input[i + 1] == 'c')
		return (print_char(va_arg(args, int)));
	else if (input[i + 1] == 's')
		return (print_string(va_arg(args, char *)));
	else if (input[i + 1] == 'd' || input[i + 1] == 'i')
		return (print_int(va_arg(args, int)));
	else if (input[i + 1] == 'u')
		return (print_unsnbr(va_arg(args, unsigned int)));
	else if (input[i + 1] == 'p')
		return (print_hex(va_arg(args, unsigned long), 'p') + 2);
	else if (input[i + 1] == 'x' || input[i + 1] == 'X')
		return (print_hex(va_arg(args, unsigned int), input[i + 1]));
	else if (input[i + 1] == '%')
		return (print_char('%'));
	return (0);
}
