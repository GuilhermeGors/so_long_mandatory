/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:31 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/10 15:58:46 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *player_image;
    void    *wall_image;
    void    *path_image;
    void    *exit_image;
    void    *collectable_image;
    int     x_pos;
    int     y_pos;
    int     collectables;
    int     map_height;
    int     map_width;
    char    **map;
    char    *file_path;
} t_game;


void     load_map(t_game *game);
int     key_press(int keycode, t_game *game);
int     close_game(t_game *game);
int     render_player(t_game *game);
int     render_map(t_game *game);
int     load_images(t_game *game);
void     trace_map(t_game *game);
void    print_map(t_game *game);
char    **parse_map(t_game *game, int argc, char **argv);
int     check_if_map_file_is_ber(char *argv);

#endif
