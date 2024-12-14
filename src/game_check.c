/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:37:47 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 00:51:34 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	init_countables(t_game *game)
{
	game->collectables = 0;
	game->map_width = 0;
    game->map_height = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->c_count = 0;

}
int	init_game(t_game *game, int argc, char **argv)
{
	init_countables(game);
	game->map = parse_map(game, argc, argv);
	if (!game->map  || !validate_map(game->map, game))
		return (ft_putstr_fd_int("Invalid map file.\n", 2));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_putstr_fd_int("MLX connection error.\n.", 2));
	game->win = mlx_new_window(game->mlx, game->map_width * SZ, \
		game->map_height * SZ, "Game");
    if (!game->win)
    {
        free_map(game->map, game->map_height);
        return (ft_putstr_fd_int("Error opening MLX window.\n", 2));
    }
	if (load_images(game) == -1)
		return (ft_putstr_fd_int("Error loading images\n", 2));
	return (1);
}
