#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define FRAME_DELAY 3000 // Delay em milissegundos

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	**front_frames;
	void	**back_frames;
	void	**left_frames;
	void	**right_frames;
	int		frame_count;
	int		current_frame;
	int		x_pos;
	int		y_pos;
	int		frame_counter;
	int		moving_up;
	int		moving_left;
	int		moving_right;
} t_game;

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 119) // W: move para cima
	{
		game->y_pos -= 10;
		game->moving_up = 1; // Flag para movimento para cima
		game->moving_left = 0;
		game->moving_right = 0;
	}
	else if (keycode == 97) // A: move para a esquerda
	{
		game->x_pos -= 10;
		game->moving_up = 0;
		game->moving_left = 1;
		game->moving_right = 0;
	}
	else if (keycode == 115) // S: move para baixo
	{
		game->y_pos += 10;
		game->moving_up = 0;
		game->moving_left = 0;
		game->moving_right = 0;
	}
	else if (keycode == 100) // D: move para a direita
	{
		game->x_pos += 10;
		game->moving_up = 0;
		game->moving_left = 0;
		game->moving_right = 1;
	}
	else if (keycode == 65307) // ESC: fecha o jogo
		close_game(game);

	return (0);
}

int	animate_sprite(t_game *game)
{
	void **current_frames;

	if (game->moving_up)
		current_frames = game->back_frames;
	else if(game->moving_left)
		current_frames = game->left_frames;
	else if(game->moving_right)
		current_frames = game->right_frames;
	else
		current_frames = game->front_frames;

	mlx_clear_window(game->mlx, game->win);
	if (game->frame_counter >= FRAME_DELAY)
	{
		mlx_put_image_to_window(game->mlx, game->win, current_frames[game->current_frame], game->x_pos, game->y_pos);
		game->current_frame = (game->current_frame + 1) % game->frame_count;
		game->frame_counter = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, current_frames[game->current_frame], game->x_pos, game->y_pos);
	}
	game->frame_counter++;

	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);

	game.win = mlx_new_window(game.mlx, 800, 600, "Sprite Animation");
	if (!game.win)
		return (2);

	game.frame_count = 3; // Temos 3 frames para cada direção (frente e costas)
	
	// Aloca memória para os arrays de frames
	game.front_frames = malloc(sizeof(void*) * game.frame_count);
	game.back_frames = malloc(sizeof(void*) * game.frame_count);
	game.left_frames = malloc(sizeof(void*) * game.frame_count);
	game.right_frames = malloc(sizeof(void*) * game.frame_count);

	if (!game.front_frames || !game.back_frames || !game.left_frames || !game.right_frames)
		return (3);

	// Carrega os frames frontais
	game.front_frames[0] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_1.xpm", &game.x_pos, &game.y_pos);
	game.front_frames[1] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_2.xpm", &game.x_pos, &game.y_pos);
	game.front_frames[2] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_3.xpm", &game.x_pos, &game.y_pos);

	// Carrega os frames das costas
	game.back_frames[0] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_back_1.xpm", &game.x_pos, &game.y_pos);
	game.back_frames[1] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_back_2.xpm", &game.x_pos, &game.y_pos);
	game.back_frames[2] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_back_3.xpm", &game.x_pos, &game.y_pos);

	game.left_frames[0] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_left_1.xpm", &game.x_pos, &game.y_pos);
	game.left_frames[1] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_left_2.xpm", &game.x_pos, &game.y_pos);
	game.left_frames[2] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_left_3.xpm", &game.x_pos, &game.y_pos);

	game.right_frames[0] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_right_1.xpm", &game.x_pos, &game.y_pos);
	game.right_frames[1] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_right_2.xpm", &game.x_pos, &game.y_pos);
	game.right_frames[2] = mlx_xpm_file_to_image(game.mlx, "./assets/fire/fire_right_3.xpm", &game.x_pos, &game.y_pos);


	// Verifica se todas as imagens foram carregadas com sucesso
	if (!game.front_frames[0] || !game.front_frames[1] || !game.front_frames[2] ||
		!game.back_frames[0] || !game.back_frames[1] || !game.back_frames[2] ||
		!game.left_frames[0] || !game.left_frames[1] || !game.left_frames[2] ||
		!game.right_frames[0] || !game.right_frames[1] || !game.right_frames[2])
		return (4);

	// Posição inicial do sprite
	game.x_pos = (800 - game.x_pos) / 2;
	game.y_pos = (600 - game.y_pos) / 2;

	// Frame inicial
	game.current_frame = 0;
	game.frame_counter = 0;
	game.moving_up = 0;

	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);

	mlx_loop_hook(game.mlx, animate_sprite, &game);

	mlx_loop(game.mlx);

	return (0);
}
