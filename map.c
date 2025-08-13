/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:50 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/13 19:40:09 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *file)
{
	int	fd;
	int	height;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("File does not open/read");
	height = count_lines(fd);
	close(fd);
	return (height);
}

static void	read_map_lines(int fd, char **map, int height)
{
	int	i;
	int	len;

	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (map[i])
		{
			len = map_width_check(map[i]);
			map[i][len] = '\0';
		}
		i++;
	}
	map[i] = NULL;
}

char	**alloc_map(char *file, int *height)
{
	int		fd;
	char	**map;

	*height = get_map_height(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("File does not open again!");
	map = malloc(sizeof(char *) * (*height + 1));
	if (!map)
		ft_error("map malloc failed!");
	read_map_lines(fd, map, *height);
	close(fd);
	return (map);
}

int	load_map(t_game *game, char *filename)
{
	int	y;
	int	x;

	game->map = alloc_map(filename, &game->map_height);
	if (!game->map)
		ft_error("Map does not loaded!");
	if (!check_map(game))
		return (0);
	y = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
			}
		}
	}
	return (1);
}

