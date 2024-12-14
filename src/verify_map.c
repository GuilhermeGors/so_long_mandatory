/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:40:36 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/14 01:49:20 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	print_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= game->map_height - 1)
	{
		x = 0;
		while (x <= game->map_width)
		{
			write(1, &game->map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
