/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:40:10 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 01:24:51 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	allocate_map_line(t_game *game, char *line, int y, int fd)
{
	game->map[y] = (char *)malloc((game->map_width + 1) * sizeof(char));
	if (!game->map[y])
	{
		close(fd);
		free(line);
		ft_putstr_fd("Error allocating line memory.\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_strncpy(game->map[y], line, game->map_width);
	game->map[y][game->map_width] = '\0';
	free(line);
}

static void	process_map_characters(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (x < game->map_width)
	{
		if (line[x] == 'P')
		{
			game->x_pos = x * 32;
			game->y_pos = y * 32;
		}
		else if (line[x] == 'C')
			game->collectables++;
		x++;
	}
}

static void	handle_line_map(t_game *game, char *line, int y, int fd)
{
	if ((int)ft_strlen(line) < game->map_width)
	{
		close(fd);
		free(line);
		ft_putstr_fd("Error: Inconsistent line length in map file.\n", 2);
		exit(EXIT_FAILURE);
	}
	allocate_map_line(game, line, y, fd);
	process_map_characters(game, game->map[y], y);
}

static void	allocate_map_memory(t_game *game, int fd)
{
	game->map = (char **)malloc((game->map_height + 1) * sizeof(char *));
	if (!game->map)
	{
		close(fd);
		ft_putstr_fd("Error allocating memory for map.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	load_map(t_game *game)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(game->file_path, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	allocate_map_memory(game, fd);
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
	{
		ft_putstr_fd("Error: map has fewer lines than expected.\n", 2);
		free_map(game->map, game->map_height);
		exit(EXIT_FAILURE);
	}
	game->map[y] = NULL;
}
