NAME_P = push_swap

NAME_C = checker

SRC_P = ft_min_max.c ft_operations.c ft_additional_operations.c\
	ft_valid.c ft_initialization.c ft_record.c ft_separate_stack.c\
	ft_cheacker.c main_ps.c ft_count_operation.c ft_sort.c\
	ft_additional_functions.c

SRC_C = ft_cheacker.c ft_additional_functions.c ft_operations.c\
	ft_additional_operations.c main_chk.c ft_valid.c ft_initialization.c\
	ft_record.c ft_min_max.c

LIBFT = ./libft/libft.a

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(SRC_P)
	make -C ./libft
	gcc -Wall -Werror -Wextra $(SRC_P) $(LIBFT) -o $(NAME_P)

$(NAME_C): $(SRC_C)
	make -C ./libft
	gcc -Wall -Werror -Wextra $(SRC_C) $(LIBFT) -o $(NAME_C)

clean:
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME_P)
	rm -f $(NAME_C)

re: fclean all
