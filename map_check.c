/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:40 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/15 10:27:42 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
// void return (int) yaparak deneyelim. çalışıyor
int	check_map_format(t_game *game)
{
	int	i;
	int	width;

	width = map_width_check(game->map[0]);
	game->map_width = width;
	i = 1;
	while (game->map[i])
	{
		if (map_width_check(game->map[i]) != width)
		{
			ft_error("Map is not rectangular! line length are different.");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_chars(t_game *g, int *p, int *e, int *c)
{
	int	x;
	int	y;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == PLAYER)
				(*p)++;
			else if (g->map[y][x] == EXIT)
				(*e)++;
			else if (g->map[y][x] == COIN)
				(*c)++;
			else if (g->map[y][x] != WALL && g->map[y][x] != FLOOR
				&& g->map[y][x] != ENEMY)
				ft_map_error("Unvalid character!", g);
		}
	}
}

void	check_walls(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if ((y == 0 || y == g->map_height - 1 || x == 0 || x == g->map_width
					- 1) && g->map[y][x] != WALL)
				ft_map_error("Map does not surrounded by walls!", g);
		}
	}
}

int	check_map(t_game *g)
{
	int	player;
	int	exit;
	int	coin;

	player = 0;
	exit = 0;
	coin = 0;
	if (!check_map_format(g))
		return (0);
	check_chars(g, &player, &exit, &coin);
	check_walls(g);
	if (player != 1 || exit < 1 || coin < 1)
		ft_map_error("There is no or more Player and Exit or no Coin!", g);
	g->coin_count = coin;
	return (1);
}
