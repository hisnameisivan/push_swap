/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:34:47 by waddam            #+#    #+#             */
/*   Updated: 2019/06/20 23:56:18 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialization_push(t_push *push)
{
	push->i = 0;
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->size_a = 0;
	push->size_b = 0;
	push->max = 0;
	push->min = 0;
	push->res = 0;
	push->index = -1;
	push->fl = 0;
}

void	ft_initialization_swap(t_swap *swap)
{
	swap->pa = 0;
	swap->pb = 0;
	swap->ra = 0;
	swap->rb = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrb = 0;
	swap->rrr = 0;
}
