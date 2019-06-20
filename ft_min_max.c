/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:19 by waddam            #+#    #+#             */
/*   Updated: 2019/06/21 00:01:43 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_max(t_push *push)
{
	int		i;
	int		max;

	i = 1;
	max = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] > max)
			max = push->stack_a[i];
		i++;
	}
	return (max);
}

int		ft_min(t_push *push)
{
	int		i;
	int		min;

	i = 1;
	min = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] < min)
			min = push->stack_a[i];
		i++;
	}
	return (min);
}
