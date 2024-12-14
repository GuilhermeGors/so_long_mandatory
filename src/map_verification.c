/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 23:30:14 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 23:34:08 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	check_element(char element, t_game *game, int row, int col)
{
	char	*valid_elements = "PCE01\n";

	if (element == 'P')
	{
		game->p_count++;
		if (game->p_count > 1)
			return (ft_putstr_fd_int("Error: Too many players on the map!\n", 2));
		game->x_pos = col;
		game->y_pos = row;
	}
	if (element == 'E')
	{
		game->e_count++;
		if (game->e_count > 1)
			return (ft_putstr_fd_0("Error: Too many exits on the map!\n", 2));
	}
	if (element == 'C')
		game->c_count++;
	if (!ft_strchr_v3(valid_elements, element))
		return (ft_putstr_fd_0("Error: Invalid map element!\n", 2));
	return (1);
}

static int	validate_elements(char **map, t_game *game)
{
	int row;
	int col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (!check_element(map[row][col], game, row, col))
				return (0);
			col++;
		}
		row++;
	}
	if (game->p_count == 0)
		return (ft_putstr_fd_0("Error: No player on the map.\n", 2));
	if (game->c_count == 0)
		return (ft_putstr_fd_0("Error: No collectibles on the map.\n", 2));
	if (game->e_count == 0)
		return (ft_putstr_fd_0("Error: No exit on the map.\n", 2));
	return (1);
}

static int	validate_walls(char **map)
{
	size_t row;
	size_t col;
	size_t map_width;

	row = 0;
	map_width = ft_strlen(map[row]);
	while (map[row] != NULL)
	{
		col = 0;
		if (row == 0 || map[row + 1] == NULL)
		{
			while (map[row][col] != '\0' && map[row][col] != '\n')
			{
				if (map[row][col] != '1')
					return (ft_putstr_fd_0("Error: Map borders must be walls (1).\n", 2));
				col++;
			}
		}
		else if (map[row][0] != '1' || map[row][map_width - 2] != '1')
			return (ft_putstr_fd_0("Error: Map borders must be walls (1).\n", 2));
		row++;
	}
	return (1);
}

static int	is_map_rectangular(char **map)
{
	size_t	row_width;
	size_t	current_width;
	size_t	row;

	row_width = ft_strlen(map[0]);
	row = 0;
	while (map[row] != NULL)
	{
		current_width = ft_strlen(map[row]);
		if (current_width != row_width)
			return (ft_putstr_fd_0("Error: The map is not rectangular.\n", 2));
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
