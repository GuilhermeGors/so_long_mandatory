
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

    // Parse do mapa
    map = parse_map(&game, argc, argv);
    if (!map)
    {
        write(1, "Erro ao carregar o mapa.\n", 25);
        return (1);
    }
    game.map = map;

    // Inicialização do MLX
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        write(1, "Erro ao inicializar o MLX.\n", 27);
        free_map(game.map, game.map_height);
        return (2);
    }

    // Criação da janela
    game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE, game.map_height * TILE_SIZE, "Game");
    if (!game.win)
    {
        write(1, "Erro ao criar janela.\n", 22);
        free_map(game.map, game.map_height);
        return (3);
    }

    // Carregamento de imagens
    if (load_images(&game) == -1)
    {
        write(1, "Erro ao carregar imagens.\n", 26);
        free_images(&game);
        free_map(game.map, game.map_height);
        mlx_destroy_window(game.mlx, game.win);
        return (4);
    }

    // Renderização inicial
    render_map(&game);

    // Hooks para eventos
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop_hook(game.mlx, render_player, &game);

    // Loop principal
    mlx_loop(game.mlx);

    // Limpeza de recursos ao sair
    close_game(&game);
    return (0);
}

