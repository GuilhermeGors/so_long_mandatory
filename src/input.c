/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:34:56 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/29 19:00:13 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

// Função para capturar as teclas pressionadas
int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC
        close_game(game);

    // Movimentos das teclas WASD
    if (keycode == 119) { // W
        game->y_pos -= 10;
        game->moving_up = 1;
        game->moving_left = 0;
        game->moving_right = 0;
    }
    else if (keycode == 97) { // A
        game->x_pos -= 10;
        game->moving_up = 0;
        game->moving_left = 1;
        game->moving_right = 0;
    }
    else if (keycode == 115) { // S
        game->y_pos += 10;
        game->moving_up = 0;
        game->moving_left = 0;
        game->moving_right = 0;
    }
    else if (keycode == 100) { // D
        game->x_pos += 10;
        game->moving_up = 0;
        game->moving_left = 0;
        game->moving_right = 1;
    }

    return (0);
}
