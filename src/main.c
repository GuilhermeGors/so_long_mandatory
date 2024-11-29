/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:33:04 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/29 19:16:01 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c
#include "../includes/game.h"
#include "../includes/render.h"
#include "../includes/input.h"

int main(void)
{
    t_game game;

    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);

    game.win = mlx_new_window(game.mlx, 800, 600, "so_long");
    if (!game.win)
        return (2);

    // Carregar as imagens
    if (!load_images(&game))
        return (4);

    game.x_pos = 400;
    game.y_pos = 300;
    game.current_frame = 0;
    game.frame_counter = 0;

    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop_hook(game.mlx, animate_sprite, &game);

    mlx_loop(game.mlx);

    return (0);
}
