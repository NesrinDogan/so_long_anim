NAME 		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-g silinecek

MAKEFLAGS += --no-print-directory

MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft
GNL_DIR		= get_next_line

MLX			= $(MLX_DIR)/libmlx.a
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/gnl.a

SRC			= main.c helper.c map.c player_anim.c draw_map.c player.c player_utils.c map_check.c map_path.c free_all.c
OBJ			= $(SRC:.c=.o)

MLX_CONFIG	= $(MLX_DIR)/Makefile.gen

all: $(NAME)

$(MLX_CONFIG):
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
