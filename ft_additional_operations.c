/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:32:38 by waddam            #+#    #+#             */
/*   Updated: 2019/06/25 22:33:12 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void	ft_additional_po(t_push *push, char letter)
{
	ft_swap(&push->stack_a[0], &push->stack_b[0]);
	if (letter == 'a')
	{
		push->size_b--;
		push->size_a++;
	}
	else if (letter == 'b')
	{
		push->size_a--;
		push->size_b++;
	}
}
