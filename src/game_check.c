/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:37:47 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 21:21:13 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	init_countables(t_game *game)
{
	game->map_width = 0;
    game->map_height = 0;
	// game->collectible = 0;
	// game->exit = 0;
	// game->player = 0;
	// game->floor_flag = 0;
	// game->wall_flag = 0;
	// game->exit_flag = 0;
	// game->player_flag = 0;
	// game->collectible_flag = 0;
}
int	init_game(t_game *game, int argc, char **argv)
{
	init_countables(game);
	game->map = parse_map(game, argc, argv);
	if (!game->map) // validar mapa aqui
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
