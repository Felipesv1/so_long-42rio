/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:42:41 by felperei          #+#    #+#             */
/*   Updated: 2023/10/30 13:37:04 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			l;	
	char			*str;

	l = 0;
	if (s == 0 || f == 0)
		return (0);
	while (s[l] != '\0')
		l++;
	i = 0;
	str = malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (0);
	while (i < l)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
