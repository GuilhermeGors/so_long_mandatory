/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:30:14 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 02:12:32 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	validate_character(t_game *game, char c)
{
	if (c == 'P')
	{
		if (game->p_count > 1)
			return (ft_putstr_fd_int("Error: \
			 Too many players on the map!\n", 2));
	}
	else if (c == 'E')
	{
		if (game->e_count > 1)
			return (ft_putstr_fd_int("Error: Too many exits on the map!\n", 2));
	}
	else if (c == 'C')
		game->c_count++;
	else if (!ft_strchr("PCE01\n", c))
		return (ft_putstr_fd_int("Error: Invalid map element!\n", 2));
	return (1);
}

static int	validate_elements(char **map, t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!validate_character(game, map[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	if (game->p_count == 0)
		return (ft_putstr_fd_int("Error: No player on the map.\n", 2));
	if (game->c_count == 0)
		return (ft_putstr_fd_int("Error: No collectibles on the map.\n", 2));
	if (game->e_count == 0)
		return (ft_putstr_fd_int("Error: No exit on the map.\n", 2));
	return (1);
}

static int	validate_walls(char **map)
{
	size_t	row;
	size_t	width;
	size_t	col;

	col = 0;
	width = ft_strlen(map[0]);
	row = 0;
	while (map[row])
	{
		if (row == 0 || map[row + 1] == NULL)
		{
			while (col < width)
			{
				if (map[row][col] != '1')
					return (ft_putstr_fd_int("Error\nMap wall error\n", 2));
				col++;
			}
		}
		else if (map[row][0] != '1' || map[row][width - 1] != '1')
			return (ft_putstr_fd_int("Error\nMap wall error\n", 2));
		row++;
	}
	return (1);
}

static int	is_map_rectangular(char **map)
{
	size_t	width;
	size_t	row;

	width = ft_strlen(map[0]);
	row = 1;
	while (map[row])
	{
		if (ft_strlen(map[row]) != width)
			return (ft_putstr_fd_int("Error: map not rectangular.\n", 2));
		row++;
	}
	return (1);
}

int	validate_map(char **map, t_game *game)
{
	if (!is_map_rectangular(map))
		return (0);
	if (!validate_walls(map))
		return (0);
	if (!validate_elements(map, game))
		return (0);
	return (1);
}
