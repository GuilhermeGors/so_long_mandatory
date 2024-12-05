/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:31 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/05 16:47:26 by gugomes-         ###   ########.fr       */
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

# define MAP_HEIGHT 15
# define MAP_WIDTH 64

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
    char    map[MAP_HEIGHT][MAP_WIDTH + 1];
} t_game;

int     load_map(t_game *game, const char *filename);
int     key_press(int keycode, t_game *game);
int     close_game(t_game *game);
int     render_player(t_game *game);
int     render_map(t_game *game);
int     load_map(t_game *game, const char *filename);


#endif
