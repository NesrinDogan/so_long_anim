#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free(map);
}

void	free_images(t_game *g)
{
	printf("free images\n");
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

	if (g->player_frames[0])
		mlx_destroy_image(g->mlx, g->player_frames[0]);
	if (g->player_frames[1])
		mlx_destroy_image(g->mlx, g->player_frames[1]);
	if (g->player_frames[2])
		mlx_destroy_image(g->mlx, g->player_frames[2]);
}

int	exit_game(t_game *g)
{
	if (g->map)
		free_map(g->map);
	mlx_loop_end(g->mlx);
	free_images(g); // Önce tüm img’leri temizle
	if (g->win)
	{
		printf("window destroyed \n");
		mlx_destroy_window(g->mlx, g->win);
	}
	if (g->mlx)
	{
		printf("display destroyed \n");
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	
	exit(0);
}
