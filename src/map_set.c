/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:33 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 14:31:07 by gugomes-         ###   ########.fr       */
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
	trace_map(game);
	load_map(game);

	free(game->file_path);
	if (!game->map)
	{
		write(1, "Error\nFailure reading the map, file name is invalid!\n", 52);
		exit(EXIT_FAILURE);
	}
	//validar mapa...
	return (game->map);
}

int	check_if_map_file_is_ber(char *argv)
{
	char	*file_type;
	char	*file_type_expected;
	int		i;
	int		string_length;
	int		j;

	j = 0;
	file_type_expected = ".ber";
	if (!argv || ft_strlen(argv) == 0)
		return (1);
	string_length = ft_strlen(argv);
	i = string_length - 4;
	file_type = ft_substr(argv, i, 4);
	if (!file_type)
	{
		free(file_type);
		return (1);
	}
	if (!ft_strnstr(file_type, file_type_expected, 4))
	{
		write(1, "Error!\nMap file is not \".ber\"", 29);
		exit(EXIT_FAILURE);
	}

	free(file_type);
	return (0);
}