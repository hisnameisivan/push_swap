/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:13:58 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/18 18:54:21 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_max(t_push *push)
{
	int i;
	int max;

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
	int i;
	int min;

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
