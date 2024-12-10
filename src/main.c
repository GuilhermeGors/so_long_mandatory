
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:27:09 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/09 12:25:21 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int main(int argc, char **argv)
{
    t_game game;
    char **map;

    game.collectables = 0;
	map = NULL;
	map = parse_map(&game, argc, argv);
    game.map = map;
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        write(1, "Erro ao inicializar o MLX.\n", 27);
        return (1);
    }

    game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "Game");

    if (!game.win)
    {
        write(1, "Erro ao criar janela.\n", 22);
        return (2);
    }
    if (load_images(&game) == -1)
    {
        write(1, "Erro ao carregar imagens.\n", 26);
        return (3);
    }
    
    render_map(&game);
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);

    mlx_loop_hook(game.mlx, render_player, &game);
    mlx_loop(game.mlx);

    return (0);
}
