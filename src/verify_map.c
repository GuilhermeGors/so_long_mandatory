/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:40:36 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/13 17:13:43 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void print_map(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;

	while (y <= game->map_height - 1)
	{
		x = 0;
		while (x <= game->map_width)
		{
			printf("%c", game->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
