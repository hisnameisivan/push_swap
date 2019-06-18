#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "./libft/libft.h"
#include <stdio.h>
# define BUFF_SIZE 1024

typedef struct	s_push
{
	int			i;
	long		*stack_a;
	long		*stack_b;
	int			*temp_arr; // массив для хранения элементов, которые остануться в стеке а
	int			size_a;
	int			size_b;
	int			size_temp_arr;
	int			max;
	int			min;
	int			res;
	int			index; // положение элемента, который будет возвращен в а
	int			fl; // для функции ft_analyze_operation
}				t_push;

typedef struct	s_swap
{
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}				t_swap;

int				ft_max(t_push *push);
int				ft_min(t_push *push);


void			ft_swap(long *a, long *b);
void			swap_operations(t_push	*pu, char letter);
void			push_operations(t_push	*pu, char letter);
void			rotate_operations(t_push	*pu, char letter);
void			reverse_rotate_operations(t_push	*pu, char letter);


void			ft_initialization_push(t_push *push);
void			ft_initialization_swap(t_swap *swap);

void			ft_count_digits(char *av, t_push *push);
int				ft_check_repeat(t_push	*push);
void			ft_valid(char *av, t_push *push);
void			printstack(t_push *push);
int				ft_skip_null_znak(char *argv);
int				ft_check_overflow(char *argv, int num);
void			ft_record(t_push *push, char *argv);

void			ft_stack_balance(t_push *push);
void			ft_analyze_operation(t_push *push, t_swap *swap, int i);

void			ft_sort_stack(t_push *push, t_swap *swap);
void			ft_write_index_res(t_push *push, t_swap *swap, int i);
void			ft_counter(t_push *push, t_swap *swap, int i);
void			ft_count_operation(t_push *push);

void			ft_sort_three_item(t_push *push);
int				ft_check_sort_elements(t_push *push);
void			ft_separate_stack(t_push *push);

int				ft_check_cyclic_sorting(t_push *push);

//int 	ft_stay_item(t_push *push, int num);

#endif
