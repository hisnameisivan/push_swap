/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:29 by waddam            #+#    #+#             */
/*   Updated: 2019/07/10 23:59:20 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_operations(t_push *push, char letter)
{
	if (push->size_a > 1 && letter == 'a')
		ft_swap(&push->stack_a[0], &push->stack_a[1]);
	if (push->size_a > 1 && letter == 'b')
		ft_swap(&push->stack_b[0], &push->stack_b[1]);
	if (letter == 's')
	{
		ft_swap_operations(push, 'a');
		ft_swap_operations(push, 'b');
	}
	ft_print_stack(push);
}

void	ft_push_operations(t_push *push, char letter)
{
	int		i;

	i = (letter == 'a' ? push->size_a : push->size_b) + 1;
	if (letter == 'b' && push->size_a > 0)
	{
		if (push->size_b > 0)
			while (--i > 0)
				push->stack_b[i] = push->stack_b[i - 1];
		i = -1;
		ft_additional_po(push, letter);
		while (++i < push->size_a)
			push->stack_a[i] = push->stack_a[i + 1];
	}
	else if (letter == 'a' && push->size_b > 0)
	{
		if (push->size_a > 0)
			while (--i > 0)
				push->stack_a[i] = push->stack_a[i - 1];
		i = -1;
		ft_additional_po(push, letter);
		while (++i < push->size_b)
			push->stack_b[i] = push->stack_b[i + 1];
	}
	ft_print_stack(push);
}

void	ft_rotate_operations(t_push *push, char letter)
{
	int		tmp;
	int		i;

	i = -1;
	tmp = letter == 'a' ? push->stack_a[0] : push->stack_b[0];
	if (letter == 'a' && push->size_a > 0)
	{
		while (++i < push->size_a)
			push->stack_a[i] = push->stack_a[i + 1];
		push->stack_a[push->size_a - 1] = tmp;
	}
	else if (letter == 'b' && push->size_a > 0)
	{
		while (++i < push->size_b)
			push->stack_b[i] = push->stack_b[i + 1];
		push->stack_b[push->size_b - 1] = tmp;
	}
	else if (letter == 'r')
	{
		ft_rotate_operations(push, 'a');
		ft_rotate_operations(push, 'b');
	}
	ft_print_stack(push);
}

void	ft_reverse_rotate_operations(t_push *push, char letter)
{
	int		tmp;
	int		i;

	i = letter == 'a' ? push->size_a : push->size_b;
	tmp = letter == 'a' ? push->stack_a[i - 1] : push->stack_b[i - 1];
	if (letter == 'a' && push->size_a > 0)
	{
		while (--i > 0)
			push->stack_a[i] = push->stack_a[i - 1];
		push->stack_a[0] = tmp;
	}
	else if (letter == 'b' && push->size_b > 0)
	{
		while (--i > 0)
			push->stack_b[i] = push->stack_b[i - 1];
		push->stack_b[0] = tmp;
	}
	else if (letter == 'r')
	{
		ft_reverse_rotate_operations(push, 'a');
		ft_reverse_rotate_operations(push, 'b');
	}
	ft_print_stack(push);
}
