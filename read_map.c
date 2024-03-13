/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:13:25 by felperei          #+#    #+#             */
/*   Updated: 2024/03/13 08:48:58 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

int	get_size(char *path)
{
	int		fd;
	char	*line;
	int		i;
	char	*tmp;

	i = 1;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
	}
	close(fd);
	map = ft_split(holder_map, '\n');
	free(holder_map);
	return (map);
}
