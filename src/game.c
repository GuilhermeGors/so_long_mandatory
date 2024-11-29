/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:35:19 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/29 19:05:44 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// game.c
#include "../includes/game.h"

#define FRAME_DELAY  3000

int close_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int animate_sprite(t_game *game)
{
    void **current_frames = game->front_frames;

    if (game->moving_up)
        current_frames = game->back_frames;
    else if (game->moving_left)
        current_frames = game->left_frames;
    else if (game->moving_right)
        current_frames = game->right_frames;

    mlx_clear_window(game->mlx, game->win);

    if (game->frame_counter >= FRAME_DELAY) {
        mlx_put_image_to_window(game->mlx, game->win, current_frames[game->current_frame], game->x_pos, game->y_pos);
        game->current_frame = (game->current_frame + 1) % game->frame_count;
        game->frame_counter = 0;
    } else {
        mlx_put_image_to_window(game->mlx, game->win, current_frames[game->current_frame], game->x_pos, game->y_pos);
    }

    game->frame_counter++;

    return (0);
}
