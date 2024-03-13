/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:59:10 by felperei          #+#    #+#             */
/*   Updated: 2024/03/13 09:09:02 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

int	arg_valid(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] == 'r' && av[i - 1] == 'e'
		&& av[i - 2] == 'b' && av[i - 3] == '.')
		return (1);
	ft_printf("Error");
	exit(1);
	return (0);
}

int	validate_block(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C')
				&& (map[i][j + 1] == '1' && map[i][j - 1] == '1'
				&& map[i + 1][j] == '1' && map[i - 1][j] == '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	gameplay(char *av, t_game *game)
{
	game->map = read_map(av);
	if (arg_valid(av) && map_valid(game))
	{
		start_game(game);
		start_moves(game);
		mlx_loop(game->mlx);
	}
	else
	{
		if (game->map)
		{
			free_map(game->map);
			ft_printf("Error\nInvalid Map\n");
			exit(1);
		}
	}
}
