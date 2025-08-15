/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:34 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/15 10:26:04 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_game(t_game *game)
{
	exit_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.current_frame = 0;
	if (argc != 2)
		ft_map_error("Usage: ./so_long <map.ber>", &game);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_map_error("Map file name has to finish with .ber", &game);

	load_map(&game, argv[1]);
	if (!is_map_valid(&game))
		ft_map_error("Invalid map format",&game);


	find_player(&game);
	if (!check_path(&game))
		ft_map_error("Invalid path in map!", &game);

	game_init(&game);
	load_player_frames(&game);
	draw_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, animate_player, &game);
	mlx_loop(game.mlx);
	close_game(&game);
	return (0);
}

void	game_init(t_game *game)
{
	game->map_width = map_width_check(game->map[0]);
	// haritanın genişliğini atadık.
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_map_error("mlx_init failed!", game);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		ft_map_error("mlx_new_window failed!", game);
}

void	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
}
