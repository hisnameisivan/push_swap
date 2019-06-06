#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "./libft/libft.h"
#include <stdio.h>

typedef struct	s_push
{
	int		i;
	long 	*stack_a;
	long 	*stack_b;
	long 	*index; // пока не используем
	int		*temp_arr;
	int		size_a;
	int		size_b;
	int		max;
}				t_push;

typedef struct	s_swap
{
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}				t_swap;

int			ft_max(t_push *push);
int			ft_min(t_push *push);
void		ft_buble_sort(int **mas, t_push *push);
int			ft_median(t_push *push);
void		printstack(t_push *pu);
void		swap_operations(t_push	*pu, char letter);
void		push_operations(t_push	*pu, char letter);
void		rotate_operations(t_push	*pu, char letter);
void		reverse_rotate_operations(t_push	*pu, char letter);


#endif