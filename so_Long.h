/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:39:59 by felperei          #+#    #+#             */
/*   Updated: 2024/03/13 09:06:19 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# define ESC 65307
# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_Q 113
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define MLX_ERROR 1

typedef struct s_player
{
	void		*img_player;
	int			x;
	int			y;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*img_wall;
	void		*img_floor;
	void		*img_enemy;
	void		*img_colect;
	void		*img_exit;
	t_player	*player;
	int			map_h;
	int			map_w;
	int			img_w;
	int			img_h;
	int			n_player;
	int			n_exit;
	int			n_colects;
	int			n_enemys;
	int			moves;
	int			endgame;
	int			width;
	int			height;
}				t_game;

void			start_game(t_game *game);
int				generate_map(t_game *game);
char			**read_map(char *path);
void			img_initial(t_game *game);
int				get_size(char *path);
void			player_w(t_game *game);
int				exit_game(t_game *game);
void			start_moves(t_game *game);
int				map_valid(t_game *game);
void			free_map(char **map);
int				size_map(t_game *game);
int				validate_block(char **map);
int				arg_valid(char *av);
void			gameplay(char *av, t_game *game);
// moves player
void			player_w(t_game *game);
void			player_s(t_game *game);
void			player_d(t_game *game);
void			player_a(t_game *game);

#endif
