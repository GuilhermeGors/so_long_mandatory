/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:53:20 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/09 16:17:41 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int load_images(t_game *game)
{
    game->player_image = mlx_xpm_file_to_image(game->mlx, "./assets/player/cell.xpm", &game->x_pos, &game->y_pos);
    game->wall_image = mlx_xpm_file_to_image(game->mlx, "./assets/tiles/wall.xpm", &game->x_pos, &game->y_pos);
    game->path_image = mlx_xpm_file_to_image(game->mlx, "./assets/tiles/path.xpm", &game->x_pos, &game->y_pos);
    game->exit_image = mlx_xpm_file_to_image(game->mlx, "./assets/tiles/vein.xpm", &game->x_pos, &game->y_pos);
    game->collectable_image = mlx_xpm_file_to_image(game->mlx, "./assets/tiles/o2.xpm", &game->x_pos, &game->y_pos);

    if (!game->player_image || !game->wall_image || !game->path_image ||
        !game->exit_image || !game->collectable_image)
    {
        write(1, "erro aqui", 10);
        return (-1);
    }

    return (0);
}