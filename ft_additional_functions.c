/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:12:01 by waddam            #+#    #+#             */
/*   Updated: 2019/07/11 00:04:29 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_push *push)
{
	int		i;
	int		len;

	i = -1;
	len = push->size_a > push->size_b ? push->size_a : push->size_b;
	if (push->vis)
	{
		ft_printf("----------------------------\n");
		ft_printf("|%-11c ||" "%11c |\n", 'a', 'b');
		ft_printf("----------------------------");
		ft_printf("\n");
		while (++i < len)
		{
			if (i < push->size_a)
				ft_printf("|%11d |", push->stack_a[i]);
			else
				ft_printf("|%11s |", " ");
			if (i < push->size_b)
				ft_printf("|%11d |\n", push->stack_b[i]);
			else
				ft_printf("|%11s |\n", " ");
		}
		ft_printf("----------------------------\n\n");
	}
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
			ft_printf("ra\n");
			ft_rotate_operations(push, 'a');
			i--;
		}
	}
	else
	{
		i = push->size_a - i;
		while (i > 0)
		{
			ft_printf("rra\n");
			ft_reverse_rotate_operations(push, 'a');
			i--;
		}
	}
}

int		ft_check_cyclic_sorting(t_push *push)
{
	int i;

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
	if (push->stack_a[0] > push->stack_a[i])
		i = 0;
	else
		return (0);
	while (push->stack_a[i + 1] != push->min)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
