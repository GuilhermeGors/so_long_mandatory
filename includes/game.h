#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_game {
    void    *mlx;              // Ponteiro para a estrutura MLX
    void    *win;              // Ponteiro para a janela do jogo
    void    *background;       // Ponteiro para a imagem de fundo
    void    *img_wall;         // Imagem da parede
    void    *img_backg;        // Imagem do fundo
    void    *img_player;       // Imagem do jogador
    void    *img_colect;       // Imagem dos itens coletáveis
    void    *img_exit;         // Imagem da saída
	void	**front_frames;
	void	**back_frames;
	void	**left_frames;
	void	**right_frames;
    int     img_w;             // Largura da imagem
    int     img_h;             // Altura da imagem
    char    **map;             // Mapa carregado (matriz de strings)
    int     frame_count;       // Quantidade de frames de animação
    int     current_frame;     // Frame atual da animação
    int     x_pos;             // Posição X do personagem
    int     y_pos;             // Posição Y do personagem
    int     frame_counter;     // Contador de quadros (para animação)
    int     moving_up;         // Flag para movimento para cima
    int     moving_left;       // Flag para movimento para a esquerda
    int     moving_right;      // Flag para movimento para a direita
    int     n_colect;          // Número de itens coletáveis
} t_game;

// Funções relacionadas ao jogo
int     close_game(t_game *game);                     // Fecha o jogo
int     animate_sprite(t_game *game);                 // Anima o sprite do jogador
int     load_images(t_game *game);                    // Carrega as imagens necessárias
int     load_background(t_game *game);                // Carrega o fundo
int     map_draw(t_game *game);                       // Desenha o mapa
char    **read_map(char *path);                       // Lê o mapa do arquivo
void    img_draw(t_game *game, void *image, int x, int y); // Desenha as imagens no mapa

#endif // GAME_H
