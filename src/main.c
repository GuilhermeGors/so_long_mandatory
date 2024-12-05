/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:27:09 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/05 17:03:07 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int main(void)
{
    t_game game;

    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);

    game.win = mlx_new_window(game.mlx, 800, 600, "Game");
    if (!game.win)
        return (2);

    game.player_image = mlx_xpm_file_to_image(game.mlx, "./assets/player/cell.xpm", &game.x_pos, &game.y_pos);
    game.wall_image = mlx_xpm_file_to_image(game.mlx, "./assets/tiles/wall.xpm", &game.x_pos, &game.y_pos);
    game.path_image = mlx_xpm_file_to_image(game.mlx, "./assets/tiles/path.xpm", &game.x_pos, &game.y_pos);
    game.exit_image = mlx_xpm_file_to_image(game.mlx, "./assets/tiles/vein.xpm", &game.x_pos, &game.y_pos);
    game.collectable_image = mlx_xpm_file_to_image(game.mlx, "./assets/tiles/o2.xpm", &game.x_pos, &game.y_pos);

    if (!game.player_image || !game.wall_image || !game.path_image || !game.exit_image || !game.collectable_image)
        return (3);

    if (load_map(&game, "./assets/map/testmap.txt") == -1)
    {
        printf("Erro ao carregar o mapa!\n");
        return (4);
    }

    render_map(&game);

    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);

    mlx_loop_hook(game.mlx, render_player, &game);
    mlx_loop(game.mlx);

    return (0);
}
