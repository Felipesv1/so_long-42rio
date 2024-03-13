/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:49:51 by felperei          #+#    #+#             */
/*   Updated: 2024/03/12 10:51:52 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!(buffer[i]))
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] == '\n')
		i++;
	rest = malloc(ft_strlen(buffer) - i + 1 * sizeof(char));
	if (!(rest))
		return (NULL);
	j = 0;
	while (buffer[i])
	{
		rest[j++] = buffer[i++];
	}
	rest[j++] = '\0';
	free(buffer);
	return (rest);
}

void	put(char *buffer, char *line, int i)
{
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		flag;
	int		j;

	i = 0;
	flag = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		flag = 1;
	line = (char *)malloc(sizeof(char) * (i + flag + 1));
	if (!(line))
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	put(buffer, line, i);
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*content;
	int		bytes_read;

	content = malloc(BUFFER_SIZE + 1);
	if (!(content))
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, content, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(content);
			return (NULL);
		}
		content[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, content);
	}
	free(content);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = read_file(fd, content);
	if (!(content))
		return (NULL);
	line = ft_line(content);
	content = ft_next(content);
	return (line);
}
