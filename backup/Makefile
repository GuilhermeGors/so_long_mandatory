CC = gcc
CFLAGS = -Wall -Wextra -g
MLX_FLAGS = -lX11 -lXext -lmlx

SRC_DIR = src
OBJ_DIR = obj
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/game.c $(SRC_DIR)/render.c $(SRC_DIR)/input.c $(SRC_DIR)/background.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = game

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
