OBJ_DIR	 = ./obj
OBJ_DIRC = ./objc
LIB_DIR	 = ./ft_printf

NAME	 = push_swap
NAMEC    = checker
LIBFT 	 = $(LIB_DIR)/libftprintf.a

SRC 	 = ft_push_swap.c operations.c min_max.c ft_cheacker.c main_ps.c
SRCC     = ft_cheacker.c ft_push_swap.c min_max.c operations.c main_chk.c

OBJ 	 = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJC	 = $(addprefix $(OBJ_DIRC)/,$(SRCC:.c=.o))

CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror
LIB_INC  = -I $(LIB_DIR)/include
LIB_LINK = -L $(LIB_DIR) -lft

all: $(NAME) $(NAMEC)

$(LIBFT):
	@make -C $(LIB_DIR) #--no-print-directory

$(OBJ_DIR):
	@mkdir -p $@
$(OBJ_DIRC):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_INC) $(LIB_LINK) -o $(NAME)
	#@echo push_swap Executable created.
$(NAMEC): $(LIBFT) $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) $(LIB_INC) $(LIB_LINK) -o $(NAMEC)
	#@echo checker Executable created.

$(addprefix $(OBJ_DIR)/, %.o):%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@
$(addprefix $(OBJ_DIRC)/, %.o):%.c | $(OBJ_DIRC)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean #--no-print-directory
	rm -rf $(OBJ_DIR)
	#@echo push_swap Object files deleted.
	rm -rf $(OBJ_DIRC)
	#@echo checker Object files deleted.

fclean: clean
	@make -C $(LIB_DIR) fclean --no-print-directory
	rm -f $(NAME)
	#@echo push_swap Executable deleted.
	rm -f $(NAMEC)
	#@echo checker Executable deleted.

re: fclean all
