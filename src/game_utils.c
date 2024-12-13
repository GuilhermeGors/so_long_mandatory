/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:43 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 20:25:14 by gugomes-         ###   ########.fr       */
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
            mlx_put_image_to_window(game->mlx, game->win, game->player_image, new_x * 32, new_y * 32);
    }
    print_map(game);
    return (0);
}

void load_map(t_game *game)
{
    int fd;
    char *line;
    int y;
    int x;

    fd = open(game->file_path, O_RDONLY);
    if (fd == -1)
        return (ft_putstr_fd("Erro ao abrir o arquivo do mapa.\n", 2));
    game->map = (char **)malloc((game->map_height + 1) * sizeof(char *));
    if (!game->map)
    {
        close(fd);
        write(1, "Erro ao alocar memória para o mapa.\n", 36);
        return;
    }

    y = 0;
    while (y < game->map_height && (line = get_next_line(fd)) != NULL)
    {
        game->map[y] = (char *)malloc((game->map_width + 1) * sizeof(char));
        if (!game->map[y])
        {   
            close(fd);
            return (ft_putstr_fd("Erro alocating line memory.\n", 2));
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
            {
                game->collectables++;
            }
            x++;
        }
        y++;
    }
    free(get_next_line(fd));
    close(fd);
    if (y < game->map_height)
        return(ft_putstr_fd("Erro: map has too fewer lines than expexted\n", 2));
    game->map[y] = NULL;
}

void trace_map(t_game *game)
{
    int     fd;
    char    *line;
    int     max_width;

    max_width = 0;
    fd = open(game->file_path, O_RDONLY);
    if (fd == -1)
        return (ft_putstr_fd("Error opening file.", 2));
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line)
        {
            max_width = ft_strlen(line) - 1;
            if (game->map_width == 0)
                game->map_width = max_width;
            else if (game->map_width != max_width)
            {
                write(1, "Erro: strange height read.\n", 39);
                free(line);
                close(fd);
                exit(EXIT_FAILURE);
            }
            game->map_height++;
            free(line);
        }
    }
    free(get_next_line(fd));
    close(fd);
    if (game->map_height <= 0 || game->map_width <= 0)
    {
        ft_putstr_fd("Invalid map dimentions.\n", 2);
        exit(EXIT_FAILURE);
    }
    printf("Dimensões do mapa - Altura: %d, Largura: %d\n", game->map_height, game->map_width);
}


