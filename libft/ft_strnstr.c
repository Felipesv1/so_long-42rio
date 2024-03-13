/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:56:47 by felperei          #+#    #+#             */
/*   Updated: 2023/10/30 11:18:21 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	char	*ptr;

	ptr = (char *)big;
	l_len = ft_strlen(little);
	if (l_len == 0)
		return (ptr);
	if (len == 0)
		return (0);
	while (*ptr && len >= l_len)
	{
		if ((*ptr == *little) && (ft_strncmp(ptr, little, l_len) == 0))
		{
			return (ptr);
		}
		ptr++;
		len--;
	}
	return (NULL);
}
