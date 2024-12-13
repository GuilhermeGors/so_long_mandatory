/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:30:42 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 20:36:38 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int render_player(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->P_img, \
         game->x_pos, game->y_pos);
    return (0);
}

int render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map_height )
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->O_img, x * SZ, y * SZ);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->Z_img, x * SZ, y * SZ);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->C_img, x * SZ, y * SZ);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->E_img, x * SZ, y * SZ);
            x++;
        }
        y++;
    }
    return (0);
}

int load_images(t_game *game)
{
    int wdt;
    int hgt;
    
    game->P_img = mlx_xpm_file_to_image(game->mlx, "./img/P.xpm", &wdt, &hgt);
    game->O_img = mlx_xpm_file_to_image(game->mlx, "./img/1.xpm", &wdt, &hgt);
    game->Z_img = mlx_xpm_file_to_image(game->mlx, "./img/0.xpm", &wdt, &hgt);
    game->E_img = mlx_xpm_file_to_image(game->mlx, "./img/E.xpm", &wdt, &hgt);
    game->C_img = mlx_xpm_file_to_image(game->mlx, "./img/C.xpm", &wdt, &hgt);

    if (!game->P_img || !game->O_img || !game->Z_img ||
        !game->E_img || !game->C_img)
        return (ft_putstr_fd("Image loading error.", 2), -1);
    return (0);
}
