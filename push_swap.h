#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include <stdio.h> // для printf;

typedef struct	s_push
{
	int		i;
	long 	*stack_a;
	long 	*stack_b;
	int		size_a;
	int		size_b;
}				t_push;

void		printstack(t_push *pu);
void		swap_operations(t_push	*pu, char letter);
void		push_operations(t_push	*pu, char letter);
void		rotate_operations(t_push	*pu, char letter);
void		reverse_rotate_operations(t_push	*pu, char letter);

int		ft_min(t_push *push);		// 05.06 add prototypes
int		ft_max(t_push *push);		// 05.06 add prototypes
int		ft_median(t_push *push);	// 05.06 add prototypes


#endif
