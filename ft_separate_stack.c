/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 23:32:39 by waddam            #+#    #+#             */
/*   Updated: 2019/06/28 00:24:49 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_separate(t_push *push)
{
	if (push->i < push->size_a - push->i)
	{
		while (push->i > 0)
		{
			ft_printf("ra\n");
			ft_rotate_operations(push, 'a');
			push->i--;
		}
	}
	else
	{
		while (push->size_a - push->i > 0)
		{
			ft_printf("rra\n");
			ft_reverse_rotate_operations(push, 'a');
			push->i++;
		}
	}
	ft_printf("pb\n");
	ft_push_operations(push, 'b');
	push->i = 0;
}

static int	ft_check_sort_elements(t_push *push)
{
	if ((push->stack_a[0] < push->stack_a[1] && push->stack_a[1] <
		push->stack_a[2]) ||
		(push->stack_a[0] == push->max && push->stack_a[1] <
		push->stack_a[2]) ||
		(push->stack_a[0] < push->stack_a[1] && push->stack_a[2] == push->min))
		return (1);
	else
		return (0);
}

static void	ft_sort_three_item(t_push *push)
{
	ft_printf("sa\n");
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
		ft_printf("ra\n");
	}
	else if (push->stack_a[2] == push->min)
	{
		ft_reverse_rotate_operations(push, 'a');
		ft_printf("rra\n");
	}
}

void		ft_separate_stack(t_push *push)
{
	push->i = 0;
	while (push->size_a > 3)
	{
		if ((push->stack_a[push->i] != push->min)
		&& (push->stack_a[push->i] != push->max))
			ft_do_separate(push);
		else
			push->i++;
	}
	if (push->size_a == 3 && ft_check_sort_elements(push) == 0)
		ft_sort_three_item(push);
	push->i = 0;
}
