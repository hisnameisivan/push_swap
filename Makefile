OBJ_DIR	 = ./obj
LIB_DIR	 = ./libft

NAME	 = push_swap
LIBFT 	 = $(LIB_DIR)/libft.a

SRC 	 = ft_push_swap.c operations.c min_max.c operations.c

OBJ 	 = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror
LIB_INC  = -I $(LIB_DIR)/includes
LIB_LINK = -L $(LIB_DIR) -lft

all: $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR) --no-print-directory	

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_INC) $(LIB_LINK) -o $(NAME)
	@echo push_swap Executable created.
 
$(addprefix $(OBJ_DIR)/, %.o):%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	rm -rf $(OBJ_DIR)
	@echo push_swap Object files deleted.

fclean: clean
	@make -C $(LIB_DIR) fclean --no-print-directory
	rm -f $(NAME)
	@echo push_swap Executable deleted.

re: fclean all

