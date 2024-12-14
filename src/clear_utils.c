/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:44:37 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 22:28:08 by gugomes-         ###   ########.fr       */
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
	if (game->P_img)
		mlx_destroy_image(game->mlx, game->P_img);
	if (game->O_img)
		mlx_destroy_image(game->mlx, game->O_img);
	if (game->C_img)
		mlx_destroy_image(game->mlx, game->C_img);
	if (game->Z_img)
		mlx_destroy_image(game->mlx, game->Z_img);
	if (game->E_img)
		mlx_destroy_image(game->mlx, game->E_img);
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

void	failure_char(void)
{
	exit(EXIT_FAILURE);
}
