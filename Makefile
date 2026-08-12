GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

MLX42_DIR = libs/MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = $(MLX42_DIR)/include/MLX42

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRC_DIR)/main.c \
	$(wildcard $(SRC_DIR)/render/*.c) \
	$(wildcard $(SRC_DIR)/parsing/*.c) \
	$(wildcard $(SRC_DIR)/utils/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -Iinc -I$(MLX42_INC) -I$(LIBFT_DIR)
LIBS = $(MLX42_LIB) $(LIBFT) -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Compiling Executable...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)CUB3D is cooked$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Building Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft ready$(RESET)"

mlx:
	@if [ -f "$(MLX42_LIB)" ]; then \
		echo "$(GREEN)MLX42 bereits gebaut$(RESET)"; \
	else \
		cmake $(MLX42_DIR) -B $(MLX42_DIR)/build -DCMAKE_BUILD_TYPE=Release; \
		cmake --build $(MLX42_DIR)/build -j4; \
	fi

clean:
	@echo "$(RED)Deleted .obj files$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Deleted exec file$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

clean-mlx:
	@echo "$(RED)Deleting mlx$(RESET)"
	@rm -rf $(MLX42_DIR)/build

re: fclean all

.PHONY: all clean fclean clean-mlx mlx re