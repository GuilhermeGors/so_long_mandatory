/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:43 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 21:42:08 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int is_valid_move(t_game *game, int x, int y)
{
    static int count = 0;
    char *count_str;

    count_str = ft_itoa(count);
    if (!count_str)
        free(count_str);
    if (game->map[y][x] == 'E')  
    {
        if (game->collectables == 0)
            return (ft_putstr_fd("Game Over", 2), close_game(game));
    }    
    if (game->map[y][x] == '1')
        return (0);
    if (game->map[y][x] == 'C')
    {     
        game->map[y][x] = '0';
        game->collectables--;
    }
    count++;
    write(1, "Moves: ", 7);
    write(1, count_str, sizeof(count_str));
    write(1, "\n", 1);
    free(count_str);
    return (1);
} 

int key_press(int keycode, t_game *game)
{    
    int new_x = game->x_pos / 32;
    int new_y = game->y_pos / 32;

    if (keycode == 119) // W
        new_y--;
    else if (keycode == 97) // A
        new_x--;
    else if (keycode == 115) // S
        new_y++;
    else if (keycode == 100) // D
        new_x++;
    else if (keycode == 65307) // ESC
        close_game(game);

    int move_status = is_valid_move(game, new_x, new_y);

    if (move_status)
    {
        if (game->map[game->y_pos / 32][game->x_pos / 32] == 'P')
            game->map[game->y_pos / 32][game->x_pos / 32] = '0';
        game->x_pos = new_x * 32;
        game->y_pos = new_y * 32;

        if (move_status != 2)
            game->map[new_y][new_x] = 'P';
        render_map(game);
        if (move_status == 2)
            mlx_put_image_to_window(game->mlx, game->win, game->P_img, new_x * 32, new_y * 32);
    }
    print_map(game);
    return (0);
}


