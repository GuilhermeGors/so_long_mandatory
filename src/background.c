/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:49:13 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/22 19:30:00 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// background.c
#include "background.h"
#include <mlx.h>

int load_background(t_game *game)
{
    game->background = mlx_xpm_file_to_image(game->mlx, "./assets/tiles/background.xpm", &game->x_pos, &game->y_pos);
    if (!game->background)
    {
        fprintf(stderr, "Erro ao carregar a imagem do fundo!\n");
        return (1);
    }
    return (0);
}

void render_background(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->background, 0, 0);
}

void clear_background(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
}
