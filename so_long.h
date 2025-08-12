/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:25:12 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/12 11:08:54 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h> // silinecek mi?
# include <stdlib.h>

# define TILE_SIZE 64

// Keycodes (Linux)
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

// Map characters
# define WALL '1'
# define FLOOR '0'
# define ENEMY 'X'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_width;
	int		map_height;

	void	*img_wall;
	void	*img_floor;
	void	*img_enemy;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;

	// Player animasyonu için:
	void	*player_frames[3];
	int		current_frame;

	int		player_x;
	int		player_y;
	int		coin_count;
	int		move_count;

}			t_game;

int			load_map(t_game *game, char *filename);
void		free_map(char **map);
void		free_images(t_game *g);

void		ft_error(char *msg);
int			map_width_check(char *s);
int			check_map(t_game *g);

void		load_images(t_game *g);
void		draw_tile(t_game *g, void *img, int x, int y);
void		draw_map(t_game *g);
void		print_moves(int moves);
void		find_player(t_game *g);

int			handle_key(int key, t_game *g);
int			exit_game(t_game *g);
int			check_path(t_game *g);
int			count_lines(int fd);
void		check_walls(t_game *g);
void		check_chars(t_game *g, int *p, int *e, int *c);
int		check_map_format(t_game *game);
void		flood_fill(char **map, int y, int x);
char		**alloc_map(char *file, int *height);
void		move_player(t_game *g, int dx, int dy);
void		game_init(t_game *game);

void		load_player_frames(t_game *g);
int			animate_player(t_game *g);

#endif
