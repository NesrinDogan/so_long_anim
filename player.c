/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:58 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/10 19:24:52 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_move(t_game *g, int x, int y)
{
	if (y < 0 || y >= g->map_height || x < 0 || x >= g->map_width)
		return (0);
	if (g->map[y][x] == WALL)
		return (0);
	return (1);
}

static void	handle_special_tile(t_game *g, int x, int y)
{
	if (g->map[y][x] == COIN)
	{
		g->coin_count--;
		g->map[y][x] = FLOOR;
	}
	if (g->map[y][x] == EXIT && g->coin_count == 0)
	{
		write(1, "You win!\n", 9);
		exit_game(g);
	}
	if (g->map[y][x] == ENEMY)
	{
		write(1, "You Lost!\n", 10);
		exit_game(g);
	}
}

static void	update_player(t_game *g, int x, int y)
{
	if (g->map[y][x] != EXIT)
	{
		g->player_x = x;
		g->player_y = y;
		print_moves(++g->move_count);
		draw_map(g);
	}
}

void	move_player(t_game *g, int dx, int dy)
{
	int	x;
	int	y;

	x = g->player_x + dx;
	y = g->player_y + dy;
	if (!check_move(g, x, y))
		return ;
	handle_special_tile(g, x, y);
	update_player(g, x, y);
}
