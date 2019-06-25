/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:12:01 by waddam            #+#    #+#             */
/*   Updated: 2019/06/25 23:33:27 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_push *push)
{
	int		i;
	int		t = push->size_a > push->size_b ? push->size_a : push->size_b;

	i = -1;
	t = i * 1; /* стереть */
	// printf("----------------------------\n");
	// printf("|%-11c ||" "%11c |\n", 'a', 'b');
	// printf("----------------------------");
	// printf("\n");
	// while (++i < t)
	// {
	// 	if (i < push->size_a)
	// 		printf("|%11d |", push->stack_a[i]);
	// 	else
	// 		printf("|%11s |", " ");
	// 	if (i < push->size_b)
	// 		printf("|%11d |\n", push->stack_b[i]);
	// 	else
	// 		printf("|%11s |\n", " ");
	// }
	// printf("----------------------------\n\n");
}

void	ft_stack_balance(t_push *push)
{
	int		i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	if (i < push->size_a / 2 + 1)
	{
		while (i > 0)
		{
			printf("ra\n");
			ft_rotate_operations(push, 'a');
			i--;
		}
	}
	else
	{
		i = push->size_a - i;
		while (i > 0)
		{
			printf("rra\n");
			ft_reverse_rotate_operations(push, 'a');
			i--;
		}
	}
}

void	ft_analyze_operation(t_swap *swap)
{
	swap->pa = 1;
	while (swap->ra != 0 && swap->rb != 0)
	{
		swap->ra--;
		swap->rb--;
		swap->rr++;
	}
	while (swap->rra != 0 && swap->rrb != 0)
	{
		swap->rra--;
		swap->rrb--;
		swap->rrr++;
	}
}

void	ft_sort_stack(t_push *push, t_swap *swap)
{
	ft_counter(push, swap, push->index);
	while (swap->ra > 0)
	{
		printf("ra\n");
		ft_rotate_operations(push, 'a');
		swap->ra--;
	}
	while (swap->rb > 0)
	{
		printf("rb\n");
		ft_rotate_operations(push, 'b');
		swap->rb--;
	}
	while (swap->rr > 0)
	{
		printf("rr\n");
		ft_rotate_operations(push, 'r');
		swap->rr--;
	}
	while (swap->rra > 0)
	{
		printf("rra\n");
		ft_reverse_rotate_operations(push, 'a');
		swap->rra--;
	}
	while (swap->rrb > 0)
	{
		printf("rrb\n");
		ft_reverse_rotate_operations(push, 'b');
		swap->rrb--;
	}
	while (swap->rrr > 0)
	{
		printf("rrr\n");
		ft_reverse_rotate_operations(push, 'r');
		swap->rrr--;
	}
	printf("pa\n");
	ft_push_operations(push, 'a');
}

void	ft_write_index_res(t_push *push, t_swap *swap, int i)
{
	if (push->fl == 0)
	{
		push->res = swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + swap->rrr;
		push->index = i;
		push->fl = 1;
	}
	else if (push->fl == 1 && ((push->res > swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + swap->rrr) || (push->size_b == 1)))
	{
		push->res = swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + swap->rrr;
		push->index = i;
	}
}

void	ft_counter(t_push *push, t_swap *swap, int i) /* считает сколько требуется операций, чтобы перебросить i-ый элемент из b в a */
{
	int		j;
	int		tmp;

	j = 0;
	tmp = push->stack_b[i];
	if (i < push->size_b - i)
		swap->rb = i;
	else
		swap->rrb = push->size_b - i;
	while (j + 1 < push->size_a)
	{
		if ((push->stack_a[j] < tmp) && (push->stack_a[j + 1] > tmp))
		{
			if (j + 1 < push->size_a - (j + 1))
				swap->ra = j + 1;
			else
				swap->rra = push->size_a - (j + 1);
			break ;
		}
		else
			j++;
	}
	ft_analyze_operation(swap);
}

void	ft_count_operation(t_push *push)
{
	int		i;
	t_swap	*swap;

	i = 0;
	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
		return ;
	while (i < push->size_b)
	{
		ft_initialization_swap(swap);
		ft_counter(push, swap, i);
		ft_write_index_res(push, swap, i);
		i++;
	}
	ft_initialization_swap(swap);
	ft_sort_stack(push, swap);
	free(swap);
}

void	ft_sort_three_item(t_push *push)
{
	printf("sa\n");
	if (push->stack_a[1] == push->min)
	{
		ft_swap_operations(push, 'a');
		return ;
	}
	else
		ft_swap_operations(push, 'a');
	if (push->stack_a[0] == push->min)
	{
		ft_rotate_operations(push, 'a');
		printf("ra\n");
	}
	else if (push->stack_a[2] == push->min)
	{
		ft_reverse_rotate_operations(push, 'a');
		printf("rra\n");
	}
}

int		ft_check_sort_elements(t_push *push)
{
	if ((push->stack_a[0] < push->stack_a[1] && push->stack_a[1] < push->stack_a[2]) ||
		(push->stack_a[0] == push->max && push->stack_a[1] < push->stack_a[2]) ||
		(push->stack_a[0] < push->stack_a[1] && push->stack_a[2] == push->min))
		return (1);
	else
		return (0);
}

void	ft_separate_stack(t_push *push) /* от 17/06 оставляем min, max, рандом и сортируем  */
{
	int		i;

	i = 0;
	while (push->size_a > 3)
	{
		if ((push->stack_a[i] != push->min) && (push->stack_a[i] != push->max))
		{
			if (i < push->size_a - i)
			{
				while (i > 0)
				{
					printf("ra\n");
					ft_rotate_operations(push, 'a');
					i--;
				}
			}
			else
			{
				while (push->size_a - i > 0)
				{
					printf("rra\n");
					ft_reverse_rotate_operations(push, 'a');
					i++;
				}
			}
			printf("pb\n");
			ft_push_operations(push, 'b');
			i = 0;
		}
		else
			i++;

	}
	if (push->size_a == 3 && ft_check_sort_elements(push) == 0)
		ft_sort_three_item(push);
}

int		ft_check_cyclic_sorting(t_push *push)
{
	int		i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	while (i + 1 < push->size_a)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	if (push->stack_a[i] != push->max)
	{
		if (push->stack_a[0] > push->stack_a[i])
			i = 0;
		else
			return (0);
	}
	while (i + 1 != push->min)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
