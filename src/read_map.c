/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:35:26 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 01:57:24 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	handle_line(char *line, t_game *game, int fd)
{
	int	max_width;

	max_width = ft_strlen(line) - 1;
	if (game->map_width == 0)
		game->map_width = max_width;
	else if (game->map_width != max_width)
	{
		ft_putstr_fd("Erro: strange height read.\n", 2);
		free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
	game->map_height++;
	free(line);
}

void	trace_map(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->file_path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error opening file.", 2));
	line = get_next_line(fd);
	while (line != NULL)
	{
		handle_line(line, game, fd);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->map_height <= 0 || game->map_width <= 0)
	{
		ft_putstr_fd("Invalid map dimensions.\n", 2);
		exit(EXIT_FAILURE);
	}
}
