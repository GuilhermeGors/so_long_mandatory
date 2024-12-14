/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:06:58 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 00:07:47 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void validate_counts(t_game *game)
{
    if (game->p_count != 1)
    {
        ft_putstr_fd("Error: Invalid number of players on the map.\n", 2);
        exit(EXIT_FAILURE);
    }
    if (game->e_count < 1)
    {
        ft_putstr_fd("Error: No exits found on the map.\n", 2);
        exit(EXIT_FAILURE);
    }
    if (game->c_count < 1)
    {
        ft_putstr_fd("Error: No collectibles found on the map.\n", 2);
        exit(EXIT_FAILURE);
    }
}

void count_elements(t_game *game)
{
    int x;
    int y;

    game->p_count = 0;
    game->e_count = 0;
    game->c_count = 0;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == 'P')
                game->p_count++;
            else if (game->map[y][x] == 'E')
                game->e_count++;
            else if (game->map[y][x] == 'C')
                game->c_count++;
            x++;
        }
        y++;
    }
    validate_counts(game);
}

