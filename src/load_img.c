/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:53:20 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 14:36:46 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int load_images(t_game *game)
{
    int widht;
    int height;
    
    game->player_image = mlx_xpm_file_to_image(game->mlx, "./img/P.xpm", &widht, &height);
    game->wall_image = mlx_xpm_file_to_image(game->mlx, "./img/1.xpm", &widht, &height);
    game->path_image = mlx_xpm_file_to_image(game->mlx, "./img/0.xpm", &widht, &height);
    game->exit_image = mlx_xpm_file_to_image(game->mlx, "./img/E.xpm", &widht, &height);
    game->collectable_image = mlx_xpm_file_to_image(game->mlx, "./img/C.xpm", &widht, &height);

    if (!game->player_image || !game->wall_image || !game->path_image ||
        !game->exit_image || !game->collectable_image)
    {
        write(1, "erro aqui", 10);
        return (-1);
    }

    return (0);
}
