/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:52:42 by feliperei         #+#    #+#             */
/*   Updated: 2024/03/13 14:04:55 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->player->img_player);
	mlx_destroy_image(game->mlx, game->img_colect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->player);
	exit(0);
	return (0);
}
