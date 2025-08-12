#include "so_long.h"

void    load_player_frames(t_game *g)
{
    int w;
    int h;

    g->player_frames[0] = mlx_xpm_file_to_image(g->mlx, "textures/player_1.xpm", &w, &h);
    g->player_frames[1] = mlx_xpm_file_to_image(g->mlx, "textures/player_2.xpm", &w, &h);
    g->player_frames[2] = mlx_xpm_file_to_image(g->mlx, "textures/player_3.xpm", &w, &h);
	if (!g->player_frames[0] || !g->player_frames[1] || !g->player_frames[2])
        ft_error("Failed to load player animation frames");
}

int animate_player(t_game *g)
{
    static int counter = 0;

    counter++;
    if (counter >= 30) // Hızı ayarlamak için
    {
        g->current_frame++;
        if (g->current_frame >= 3)
            g->current_frame = 0;
        counter = 0;
    }
    draw_map(g); // Haritayı tekrar çiz
    return (0);
}

