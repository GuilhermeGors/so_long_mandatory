/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:34:26 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/22 19:42:17 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"

int load_images(t_game *game)
{
    // Aloca memória para os arrays de frames
    game->frame_count = 3;
    game->front_frames = malloc(sizeof(void*) * game->frame_count);
    game->back_frames = malloc(sizeof(void*) * game->frame_count);
    game->left_frames = malloc(sizeof(void*) * game->frame_count);
    game->right_frames = malloc(sizeof(void*) * game->frame_count);

    if (!game->front_frames || !game->back_frames || !game->left_frames || !game->right_frames)
        return (0);

    // Carregar os frames de animação
    game->front_frames[0] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_1.xpm", &game->x_pos, &game->y_pos);
    game->front_frames[1] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_2.xpm", &game->x_pos, &game->y_pos);
    game->front_frames[2] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_3.xpm", &game->x_pos, &game->y_pos);

    game->back_frames[0] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_back_1.xpm", &game->x_pos, &game->y_pos);
    game->back_frames[1] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_back_2.xpm", &game->x_pos, &game->y_pos);
    game->back_frames[2] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_back_3.xpm", &game->x_pos, &game->y_pos);

    game->left_frames[0] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_left_1.xpm", &game->x_pos, &game->y_pos);
    game->left_frames[1] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_left_2.xpm", &game->x_pos, &game->y_pos);
    game->left_frames[2] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_left_3.xpm", &game->x_pos, &game->y_pos);

    game->right_frames[0] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_right_1.xpm", &game->x_pos, &game->y_pos);
    game->right_frames[1] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_right_2.xpm", &game->x_pos, &game->y_pos);
    game->right_frames[2] = mlx_xpm_file_to_image(game->mlx, "./assets/fire/fire_right_3.xpm", &game->x_pos, &game->y_pos);

    // Verifica se todas as imagens foram carregadas com sucesso
    if (!game->front_frames[0] || !game->front_frames[1] || !game->front_frames[2] ||
        !game->back_frames[0] || !game->back_frames[1] || !game->back_frames[2] ||
        !game->left_frames[0] || !game->left_frames[1] || !game->left_frames[2] ||
        !game->right_frames[0] || !game->right_frames[1] || !game->right_frames[2])
        return (0);

    return (1);
}
