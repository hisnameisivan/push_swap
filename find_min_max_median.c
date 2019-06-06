/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_median.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:41:36 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/01 20:12:29 by draudrau         ###   ########.fr       */
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
	while (i > push->size_a)
	{
		if (push->stack_a[i] > min)
			min = push->stack_a[i];
		i++;	
	}
	return (min);
}

void	ft_buble_sort(int **mas, t_push *push)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < push->size_a - 1)
	{
		if ((*mas)[i] > (*mas)[i + 1])
		{
			tmp = (*mas)[i];
			(*mas)[i] = (*mas)[i + 1];
			(*mas)[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int		ft_median(t_push *push)
{
	int i;
	int med;
	int *tmp;

	tmp = (int*)malloc(sizeof(int) * push->size_a);
	ft_memcpy(tmp, push->stack_a, push->size_a);
	ft_buble_sort(&tmp, push);
	i = push->size_a % 2;
	med = tmp[i];
	free(tmp);
	return (med);
}