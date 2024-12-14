
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gugomes- <gugomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:27:09 by gugomes-          #+#    #+#             */
/*   Updated: 2024/12/09 12:25:21 by gugomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"


int main(int argc, char **argv)
{
    t_game game;
    
    init_game(&game, argc, argv);
    render_map(&game);
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop_hook(game.mlx, render_player, &game);
    mlx_loop(game.mlx);
    close_game(&game);
    return (0);
}

