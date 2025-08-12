/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:54 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/11 15:43:13 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == PLAYER)
			{
				g->player_x = x;
				g->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	handle_key(int key, t_game *g)
{
	if (key == KEY_ESC)
		exit_game(g);
	if (key == KEY_W)
		move_player(g, 0, -1);
	else if (key == KEY_S)
		move_player(g, 0, 1);
	else if (key == KEY_A)
		move_player(g, -1, 0);
	else if (key == KEY_D)
		move_player(g, 1, 0);
	return (0);
}

void	print_moves(int moves)
{
	ft_putstr_fd("Step: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putchar_fd('\n', 1);
}
