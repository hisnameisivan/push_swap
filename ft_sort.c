/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 23:59:43 by waddam            #+#    #+#             */
/*   Updated: 2019/06/28 00:01:25 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_do_rotate(t_push *push, t_swap *swap)
{
	while (swap->ra > 0)
	{
		ft_printf("ra\n");
		ft_rotate_operations(push, 'a');
		swap->ra--;
	}
	while (swap->rb > 0)
	{
		ft_printf("rb\n");
		ft_rotate_operations(push, 'b');
		swap->rb--;
	}
	while (swap->rr > 0)
	{
		ft_printf("rr\n");
		ft_rotate_operations(push, 'r');
		swap->rr--;
	}
}

static void	ft_do_reverse_rotate(t_push *push, t_swap *swap)
{
	while (swap->rra > 0)
	{
		ft_printf("rra\n");
		ft_reverse_rotate_operations(push, 'a');
		swap->rra--;
	}
	while (swap->rrb > 0)
	{
		ft_printf("rrb\n");
		ft_reverse_rotate_operations(push, 'b');
		swap->rrb--;
	}
	while (swap->rrr > 0)
	{
		ft_printf("rrr\n");
		ft_reverse_rotate_operations(push, 'r');
		swap->rrr--;
	}
}

void		ft_sort_stack(t_push *push, t_swap *swap)
{
	ft_counter(push, swap, push->index);
	if (swap->ra || swap->rb || swap->rr)
		ft_do_rotate(push, swap);
	if (swap->rra || swap->rrb || swap->rrr)
		ft_do_reverse_rotate(push, swap);
	ft_printf("pa\n");
	ft_push_operations(push, 'a');
}
