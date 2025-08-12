/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:25 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/11 22:42:28 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *g)
{
	int	w;
	int	h;

	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_enemy)
		mlx_destroy_image(g->mlx, g->img_enemy);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_coin)
		mlx_destroy_image(g->mlx, g->img_coin);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
	g->img_enemy = mlx_xpm_file_to_image(g->mlx, "textures/enemy.xpm", &w, &h);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "textures/player_1.xpm", &w,
			&h);
	g->img_coin = mlx_xpm_file_to_image(g->mlx, "textures/coin.xpm", &w, &h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
	if (!g->img_wall || !g->img_floor || !g->img_player || !g->img_coin
		|| !g->img_exit || !g->img_enemy)
		ft_error("Images does not uploaded!");
}
void	draw_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_tile_type(t_game *g, int x, int y)
{
	if (g->map[y][x] == WALL)
		draw_tile(g, g->img_wall, x, y);
	else
		draw_tile(g, g->img_floor, x, y);
	if (g->map[y][x] == COIN)
		draw_tile(g, g->img_coin, x, y);
	else if (g->map[y][x] == EXIT)
		draw_tile(g, g->img_exit, x, y);
	if (g->map[y][x] == ENEMY)
		draw_tile(g, g->img_enemy, x, y);
	if (x == g->player_x && y == g->player_y)
        draw_tile(g, g->player_frames[g->current_frame], x, y);

}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	load_images(g);
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			draw_tile_type(g, x, y);
			x++;
		}
		y++;
	}
}
