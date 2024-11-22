#include "game.h"

int load_images(t_game *game)
{
   // game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/images/wall.xpm", &game->img_w, &game->img_h);
    game->img_backg = mlx_xpm_file_to_image(game->mlx, "assets/images/background.xpm", &game->img_w, &game->img_h);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/images/player.xpm", &game->img_w, &game->img_h);
    game->img_colect = mlx_xpm_file_to_image(game->mlx, "assets/images/collect.xpm", &game->img_w, &game->img_h);
  //  game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/images/exit.xpm", &game->img_w, &game->img_h);

    if (!game->img_wall || !game->img_backg || !game->img_player || !game->img_colect || !game->img_exit)
    {
        fprintf(stderr, "Erro ao carregar imagens!\n");
        return (1);
    }
    return (0);
}
