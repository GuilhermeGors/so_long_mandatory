/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:43 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/05 17:02:34 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int close_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int key_press(int keycode, t_game *game)
{
    if (keycode == 119) // W
        game->y_pos -= 10;
    else if (keycode == 97) // A
        game->x_pos -= 10;
    else if (keycode == 115) // S
        game->y_pos += 10;
    else if (keycode == 100) // D
        game->x_pos += 10;
    else if (keycode == 65307) // ESC
        close_game(game);

    return (0);
}

int load_map(t_game *game, const char *filename)
{
    int     fd;
    char    *line;
    int     y;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (-1);

    y = 0;
    while (y < MAP_HEIGHT && (line = get_next_line(fd)) != NULL) 
    {
        ft_strncpy(game->map[y], line, MAP_WIDTH);
        free(line);
        y++;
    }
    close(fd);
    return (0);
}

int render_map(t_game *game)
{
    int x;
    int y;

    mlx_clear_window(game->mlx, game->win);
    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_image, x * 32, y * 32);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->path_image, x * 32, y * 32);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player_image, x * 32, y * 32);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_image, x * 32, y * 32);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectable_image, x * 32, y * 32);
        }
    }
    return (0);
}