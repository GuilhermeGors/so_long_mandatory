#include "game.h"

void img_draw(t_game *game, void *image, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

int map_draw(t_game *game)
{
    int y = 0;
    int x;

    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                img_draw(game, game->img_wall, x, y);
            else if (game->map[y][x] == '0')
                img_draw(game, game->img_backg, x, y);
            else if (game->map[y][x] == 'P')
                img_draw(game, game->img_player, x, y);
            else if (game->map[y][x] == 'C')
                img_draw(game, game->img_colect, x, y);
            else if (game->map[y][x] == 'E')
                img_draw(game, game->img_exit, x, y);
            x++;
        }
        y++;
    }
    return (0);
}
