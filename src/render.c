/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:30:42 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 01:55:01 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->p_img, \
		game->x_pos, game->y_pos);
	return (0);
}

static void	put_image_for_cell(t_game *game, char cell, int x, int y)
{
	if (cell == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->o_img, \
			x * SZ, y * SZ);
	else if (cell == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->z_img, \
			x * SZ, y * SZ);
	else if (cell == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->c_img, \
			x * SZ, y * SZ);
	else if (cell == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->e_img, \
			x * SZ, y * SZ);
}

int	render_map(t_game *game)
{
	int		x;
	int		y;
	char	cell;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			cell = game->map[y][x];
			put_image_for_cell(game, cell, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	load_images(t_game *game)
{
	int	wdt;
	int	hgt;

	game->p_img = mlx_xpm_file_to_image(game->mlx, "./img/P.xpm", &wdt, &hgt);
	game->o_img = mlx_xpm_file_to_image(game->mlx, "./img/1.xpm", &wdt, &hgt);
	game->z_img = mlx_xpm_file_to_image(game->mlx, "./img/0.xpm", &wdt, &hgt);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "./img/E.xpm", &wdt, &hgt);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "./img/C.xpm", &wdt, &hgt);
	if (!game->p_img || !game->o_img || !game->z_img || \
		!game->e_img || !game->c_img)
		return (ft_putstr_fd("Image loading error.", 2), -1);
	return (0);
}
