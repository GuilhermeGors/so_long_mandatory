/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:29:43 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 17:16:20 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int close_game(t_game *game)
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
void free_images(t_game *game)
{
    if (game->player_image)
        mlx_destroy_image(game->mlx, game->player_image);
    if (game->wall_image)
        mlx_destroy_image(game->mlx, game->wall_image);
    if (game->collectable_image)
        mlx_destroy_image(game->mlx, game->collectable_image);
    if (game->path_image)
        mlx_destroy_image(game->mlx, game->path_image);
    if (game->exit_image)
        mlx_destroy_image(game->mlx, game->exit_image);
}

void free_map(char **map, int height)
{
    int i;

    if (!map)
        return;
    i = 0;
    while (i < height)
    {
        if (map[i])
            free(map[i]);
        i++;
    }
    free(map);
}

int is_valid_move(t_game *game, int x, int y)
{
    printf("\nColectables: %d\n", game->collectables);
    static int count = 0;
    
    // if (x < 0 || x >= game->map_height || y < 0 || y >= game->map_width)
    //     return (0);
    if (game->map[y][x] == 'E')  
    {
        if (game->collectables == 0)
        {
            write(1, "Parabéns, você venceu!\n", 23);
            close_game(game);
        }
        return (2);    
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
    write(1, ft_itoa(count), sizeof(ft_itoa(count)));
    write(1, "\n", 1);

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
    {
        write(1, "Erro ao abrir o arquivo do mapa.\n", 33);
        return;
    }

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
            write(1, "Erro ao alocar memória para a linha do mapa.\n", 45);
            close(fd);
            return;
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

    close(fd);

    if (y < game->map_height)
    {
        write(1, "Erro: o mapa tem menos linhas do que o esperado.\n", 49);
        return;
    }

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
    {
        write(1, "Erro ao abrir o arquivo!\n", 25);
        return;
    }

    game->map_width = 0;
    game->map_height = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line)
        {
            max_width = ft_strlen(line) - 1;
            if (game->map_width == 0)
                game->map_width = max_width;
            else if (game->map_width != max_width)
            {
                write(1, "Erro: mapa com largura inconsistente.\n", 39);
                free(line);
                close(fd);
                exit(EXIT_FAILURE);
            }
            game->map_height++;
            free(line);
        }
    }
    close(fd);
    if (game->map_height <= 0 || game->map_width <= 0)
    {
        printf("%s", game->file_path);
        printf("\nHeight %d\nWidth %d\n", game->map_height, game->map_width);
        write(1, "Dimensões do mapa inválidas.\n", 28);
        exit(EXIT_FAILURE);
    }

    printf("Dimensões do mapa - Altura: %d, Largura: %d\n", game->map_height, game->map_width);
}


