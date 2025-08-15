#include "so_long.h"

void cleanup_game(t_game *g)
{
    int i = 0;
    if (g->map)
    {
        while (g->map[i])
        {
            free(g->map[i]);
            i++;
        }
        free(g->map);
    }
}

void ft_map_error(char *msg, t_game *g)
{
    ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
    cleanup_game(g);
    exit(EXIT_FAILURE);
}

int is_map_valid(t_game *g)
{
	if (!check_map(g))
	{
		cleanup_game(g);
		return (0);
	}
	return (1);
}

// if (!is_map_valid(g))
//     ft_error("Invalid map format");
