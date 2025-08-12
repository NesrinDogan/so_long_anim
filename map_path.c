/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:06:46 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/11 12:00:55 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *g)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (g->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < g->map_height)
	{
		copy[i] = ft_strdup(g->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'S')
		return ;
	map[y][x] = 'S';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

static int	run_flood_and_check(t_game *g, char **copy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (++j < g->map_width)
			if (copy[i][j] == 'P')
				flood_fill(copy, i, j);
	}
	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (++j < g->map_width)
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (0);
	}
	return (1);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	return (count);
}

int	check_path(t_game *g)
{
	char	**copy;
	int		result;

	copy = copy_map(g);
	if (!copy)
		return (0);
	result = run_flood_and_check(g, copy);
	free_map(copy);
	return (result);
}


