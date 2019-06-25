/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:52 by waddam            #+#    #+#             */
/*   Updated: 2019/06/25 23:43:18 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "./libft/libft.h"
# include "./ft_printf/header/ft_printf.h"
#include <stdio.h>
# define BUFF_SIZE 1024

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

int				ft_max(t_push *push);
int				ft_min(t_push *push);

void			ft_swap(int *a, int *b);
void			ft_additional_po(t_push *push, char letter);
void			ft_swap_operations(t_push *push, char letter);
void			ft_push_operations(t_push *push, char letter);
void			ft_rotate_operations(t_push *push, char letter);
void			ft_reverse_rotate_operations(t_push *push, char letter);

void			ft_initialization_push(t_push *push);
void			ft_initialization_swap(t_swap *swap);

//void			ft_count_digits(char *argv, t_push *push);
int				ft_check_repeat(t_push	*push);
void			ft_valid(char *argv, t_push *push);
//int				ft_skip_null_sign(char *argv);
//int				ft_check_overflow(char *argv, int num);
void			ft_record(t_push *push, char *argv);
void			ft_print_stack(t_push *push);

void			ft_stack_balance(t_push *push);
void			ft_analyze_operation(t_swap *swap);

void			ft_sort_stack(t_push *push, t_swap *swap);
void			ft_write_index_res(t_push *push, t_swap *swap, int i);
void			ft_counter(t_push *push, t_swap *swap, int i);
void			ft_count_operation(t_push *push);

void			ft_sort_three_item(t_push *push);
int				ft_check_sort_elements(t_push *push);
void			ft_separate_stack(t_push *push);

int				ft_check_cyclic_sorting(t_push *push);

int				ft_check_sort(t_push *push);
void			ft_read_input(t_push *push);

//int 	ft_stay_item(t_push *push, int num);

#endif
