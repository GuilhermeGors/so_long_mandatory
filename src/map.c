/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:35:44 by gugomes-          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:47 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	load_tiles(t_data *data)
{
	// Carregar as imagens dos tiles
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/tiles/wall.xpm", &data->x_pos, &data->y_pos);
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/tiles/floor.xpm", &data->x_pos, &data->y_pos);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/tiles/collectible.xpm", &data->x_pos, &data->y_pos);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/tiles/exit.xpm", &data->x_pos, &data->y_pos);

	// Verificar se todas as imagens foram carregadas corretamente
	if (!data->wall_img || !data->floor_img || !data->collectible_img || !data->exit_img)
	{
		printf("Erro ao carregar as imagens dos tiles!\n");
		return (0);
	}

	return (1);
}
