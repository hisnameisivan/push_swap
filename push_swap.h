/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:52 by waddam            #+#    #+#             */
/*   Updated: 2019/07/11 23:21:24 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct	s_push
{
	int			i;
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
	int			max;
	int			min;
	int			res;
	int			index;
	int			vis;
	int			fl;
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

void			ft_print_stack(t_push *push);
void			ft_stack_balance(t_push *push);
int				ft_check_cyclic_sorting(t_push *push);

void			ft_swap(int *a, int *b);
void			ft_additional_po(t_push *push, char letter);

int				ft_check_sort(t_push *push);
void			ft_read_input(t_push *push);

void			ft_counter(t_push *push, t_swap *swap, int i);
void			ft_count_operation(t_push *push);

void			ft_initialization_push(t_push *push);
void			ft_initialization_swap(t_swap *swap);

int				ft_max(t_push *push);
int				ft_min(t_push *push);

void			ft_swap_operations(t_push *push, char letter);
void			ft_push_operations(t_push *push, char letter);
void			ft_rotate_operations(t_push *push, char letter);
void			ft_reverse_rotate_operations(t_push *push, char letter);

void			ft_record(t_push *push, char *argv);

void			ft_separate_stack(t_push *push);

void			ft_sort_stack(t_push *push, t_swap *swap);

void			ft_valid(char *argv, t_push *push);
int				ft_check_repeat(t_push *push);

#endif
