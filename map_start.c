/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:19:54 by felperei          #+#    #+#             */
/*   Updated: 2024/03/13 09:13:00 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

static	void	img_put(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 50, y * 50);
}

static	void	p_player(t_game *game, void *img, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	img_put(game, img, x, y);
}

static	void	exit_door(t_game *game, int x, int y)
{
	if (game->n_colects == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"./textures/doorExit.xpm", &game->img_w, &game->img_h);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 50, y
		* 50);
}

static	void	verify_map(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		img_put(game, game->img_wall, x, y);
	else if (game->map[y][x] == '0')
		img_put(game, game->img_floor, x, y);
	else if (game->map[y][x] == 'P')
		p_player(game, game->player->img_player, x, y);
	else if (game->map[y][x] == 'C')
		img_put(game, game->img_colect, x, y);
	else if (game->map[y][x] == 'K')
		img_put(game, game->img_enemy, x, y);
	else if (game->map[y][x] == 'E')
		exit_door(game, x, y);
}

int	generate_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			verify_map(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
