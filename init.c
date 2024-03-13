/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:50:51 by felperei          #+#    #+#             */
/*   Updated: 2024/03/12 14:36:52 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_Long.h"

void	img_initial(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->img_w, &game->img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&game->img_w, &game->img_h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./textures/enemy.xpm",
			&game->img_w, &game->img_h);
	game->player->img_player = mlx_xpm_file_to_image(game->mlx,
			"./textures/playerIndiana.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./textures/doorExit.xpm",
			&game->img_w, &game->img_h);
}

static void	size_window(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 50;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 50;
}

int	size_map(t_game *game)
{
	int	i;

	game->width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	if (game->width != game->height)
		return (1);
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	size_window(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	img_initial(game);
	generate_map(game);
}
