/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:31 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 02:15:03 by gugomes-         ###   ########.fr       */
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

# define SZ 32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*o_img;
	void	*z_img;
	void	*e_img;
	void	*c_img;
	int		e_count;
	int		p_count;
	int		c_count;
	int		x_pos;
	int		y_pos;
	int		collectables;
	int		map_height;
	int		map_width;
	char	**map;
	char	*file_path;
}	t_game;

void	load_map(t_game *game);
void	free_images(t_game *game);
void	free_map(char **map, int height);
void	print_map(t_game *game);
int		key_press(int keycode, t_game *game);
int		close_game(t_game *game);
int		render_player(t_game *game);
int		render_map(t_game *game);
int		load_images(t_game *game);
int		check_if_map_file_is_ber(char *argv);
int		count_digits(int n);
int		ft_putstr_fd_int(const char *s, int fd);
int		init_game(t_game *game, int argc, char **argv);
char	**parse_map(t_game *game, int argc, char **argv);
void	trace_map(t_game *game);
void	count_elements(t_game *game);
int		validate_map(char **map, t_game *game);
void	debug_map(char **map);

#endif
