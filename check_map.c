/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:08:00 by feliperei         #+#    #+#             */
/*   Updated: 2024/03/13 08:43:55 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

static int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (map[i] == NULL)
		return (1);
	while (map[i] != NULL)
		i++;
	j = 0;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'K')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_pec(t_game *game)
{
	int	i;
	int	j;

	game->n_colects = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->n_player++;
			if (game->map[i][j] == 'E')
				game->n_exit++;
			if (game->map[i][j] == 'C')
				game->n_colects++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_colects == 0 || game->n_exit != 1)
		return (0);
	return (1);
}

int	map_valid(t_game *game)
{
	if (is_retangular(game->map)
		&& is_wall(game->map) && is_validate(game->map)
		&& is_pec(game) && size_map(game) && validate_block(game->map))
		return (1);
	return (0);
}
