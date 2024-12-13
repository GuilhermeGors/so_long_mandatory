/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:44:37 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 17:45:03 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int close_game(t_game *game)
{
    if (game->map)
        free_map(game->map, game->map_height);
    free_images(game);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}
void free_images(t_game *game)
{
    if (game->player_image)
        mlx_destroy_image(game->mlx, game->player_image);
    if (game->wall_image)
        mlx_destroy_image(game->mlx, game->wall_image);
    if (game->collectable_image)
        mlx_destroy_image(game->mlx, game->collectable_image);
    if (game->path_image)
        mlx_destroy_image(game->mlx, game->path_image);
    if (game->exit_image)
        mlx_destroy_image(game->mlx, game->exit_image);
}

void free_map(char **map, int height)
{
    int i;

    if (!map)
        return;
    i = 0;
    while (i < height)
    {
        if (map[i])
            free(map[i]);
        i++;
    }
    free(map);
}