CC = cc

LIB_DIR = libs/libft
LIBFT = $(LIB_DIR)/libft.a

CFLAGS = -Wall -Wextra -g

MLX_FLAGS = -L/usr/X11R6/lib -lmlx -lXext -lX11

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/render.c $(SRC_DIR)/game_utils.c \
		$(LIB_DIR)/ft_strncpy.c $(LIB_DIR)/get_next_line.c $(SRC_DIR)/verify_map.c \
		$(SRC_DIR)/map_set.c $(SRC_DIR)/game_check.c $(SRC_DIR)/func_utils.c \
		$(SRC_DIR)/clear_utils.c $(SRC_DIR)/read_map.c $(SRC_DIR)/fill_map.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = game

VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes map.ber

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -L$(LIB_DIR) -lft $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

valgrind: $(NAME)
	valgrind $(VALGRIND_FLAGS) ./$(NAME)
