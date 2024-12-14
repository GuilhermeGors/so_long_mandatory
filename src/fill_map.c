/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:40:10 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 21:40:24 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void handle_line_map(t_game *game, char *line, int y, int fd)
{
    int x;

    game->map[y] = (char *)malloc((game->map_width + 1) * sizeof(char));
    if (!game->map[y])
    {
        close(fd);
        ft_putstr_fd("Error allocating line memory.\n", 2);
        exit(EXIT_FAILURE);
    }
    ft_strncpy(game->map[y], line, game->map_width);
    game->map[y][game->map_width] = '\0';
    free(line);
    x = 0;
    while (x < game->map_width)
    {
        if (game->map[y][x] == 'P')
        {
            game->x_pos = x * 32;
            game->y_pos = y * 32;
        }
        else if (game->map[y][x] == 'C')
            game->collectables++;
        x++;
    }
}

void load_map(t_game *game)
{
    int     fd;
    char    *line;
    int     y;

    fd = open(game->file_path, O_RDONLY);
    if (fd == -1)
        return (ft_putstr_fd("Error opening map file.\n", 2));
    game->map = (char **)malloc((game->map_height + 1) * sizeof(char *));
    if (!game->map)
    {
        close(fd);
        return (ft_putstr_fd("Error allocating memory for map.\n", 2));
    }
    y = 0;
    line = get_next_line(fd);
    while (y < game->map_height && line != NULL)
    {
        handle_line_map(game, line, y, fd);
        line = get_next_line(fd);
        y++;
    }
    close(fd);
    if (y < game->map_height)
        return (ft_putstr_fd("Error: map has fewer lines than expected.\n", 2));
    game->map[y] = NULL;
}
