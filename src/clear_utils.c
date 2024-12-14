/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:44:37 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 00:12:42 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	close_game(t_game *game)
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

void	free_images(t_game *game)
{
	if (game->p_img)
		mlx_destroy_image(game->mlx, game->p_img);
	if (game->o_img)
		mlx_destroy_image(game->mlx, game->o_img);
	if (game->c_img)
		mlx_destroy_image(game->mlx, game->c_img);
	if (game->z_img)
		mlx_destroy_image(game->mlx, game->z_img);
	if (game->e_img)
		mlx_destroy_image(game->mlx, game->e_img);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

