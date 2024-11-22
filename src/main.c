/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:33:04 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/22 19:43:21 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c
#include "game.h"
#include "render.h"
#include "input.h" // Inclua o novo arquivo de entrada

int main(void)
{
    t_game game;

    // Inicializa o MLX
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);

    // Cria a janela
    game.win = mlx_new_window(game.mlx, 800, 600, "Sprite Animation");
    if (!game.win)
        return (2);

    // Carregar as imagens
    if (!load_images(&game))
        return (4);

    // Configurações iniciais
    game.x_pos = 400; // Posição inicial X
    game.y_pos = 300; // Posição inicial Y
    game.current_frame = 0;
    game.frame_counter = 0;

    // Hooks
    mlx_hook(game.win, 2, 1L << 0, key_press, &game); // Agora chama a função de key_press de input.c
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop_hook(game.mlx, animate_sprite, &game);

    // Inicia o loop do MLX
    mlx_loop(game.mlx);

    return (0);
}
