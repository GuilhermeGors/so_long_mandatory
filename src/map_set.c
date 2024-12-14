/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:33 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 01:19:06 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

char	**parse_map(t_game *game, int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error\nMap file name is missing!\n", 32);
		exit(EXIT_FAILURE);
	}
	check_if_map_file_is_ber(argv[1]);
	game->file_path = ft_strjoin("./map/", argv[1]);
	if (!game->file_path)
	{
		write(1, "Error\nMemory allocation failed for file path.\n", 47);
		exit(EXIT_FAILURE);
	}
	trace_map(game);
	load_map(game);
    count_elements(game);
	if (!game->map)
	{
		write(1, "Error\nFailure reading the map, file name is invalid!\n", 52);
		free(game->file_path);
		exit(EXIT_FAILURE);
	}
	free(game->file_path);
	return (game->map);
}

int	check_if_map_file_is_ber(char *argv)
{
	char	*file_type;
	char	*file_type_expected;
	int		i;
	int		string_length;

	file_type_expected = ".ber";
	if (!argv || ft_strlen(argv) == 0)
		return (1);
	string_length = ft_strlen(argv);
	i = string_length - 4;
	file_type = ft_substr(argv, i, 4);
	if (!file_type)
	{
		write(1, "Error!\nMemory allocation failed for file type substring.\n", 57);
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(file_type, file_type_expected, 4))
	{
		write(1, "Error!\nMap file is not \".ber\"", 29);
		free(file_type);
		exit(EXIT_FAILURE);
	}
	free(file_type);
	return (0);
}
