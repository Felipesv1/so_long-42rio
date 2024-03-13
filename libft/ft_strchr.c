/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:19:02 by felperei          #+#    #+#             */
/*   Updated: 2024/03/05 11:22:56 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)s;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == (unsigned char)c)
		{
			return (ptr_s);
		}
		ptr_s++;
	}
	if (c == 0)
	{
		return (ptr_s);
	}
	return (NULL);
}
