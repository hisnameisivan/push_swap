/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:29 by waddam            #+#    #+#             */
/*   Updated: 2019/06/20 23:13:32 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

void	swap_operations(t_push	*push, char letter) //Операции SA SB SS
{
	if (push->size_a > 1 && letter == 'a')
		ft_swap(&push->stack_a[0], &push->stack_a[1]);
	if(push->size_a > 1 && letter == 'b')
		ft_swap(&push->stack_b[0], &push->stack_b[1]);
	if(letter == 's')
	{
		swap_operations(push, 'a');
		swap_operations(push, 'b');
	}
	ft_print_stack(push);
}

void	push_operations(t_push	*push, char letter) //Операции PA PB SS
{
	int i;

	i = letter == 'a' ? push->size_a : push->size_b;
	if(letter == 'b' && push->size_a > 0)
	{
		if (push->size_b > 0)
			while(i > 0)
			{
				push->stack_b[i] = push->stack_b[i - 1];
				i--;
			}
		i = -1;
		ft_swap(&push->stack_a[0], &push->stack_b[0]);
		push->size_a--;
		push->size_b++;
		while (++i < push->size_a)
			push->stack_a[i] = push->stack_a[i + 1];
	}
	else if(letter == 'a' && push->size_b > 0)
	{
		if (push->size_a > 0)
			while(i > 0)
			{
				push->stack_a[i] = push->stack_a[i - 1];
				i--;
			}
		i = -1;
		ft_swap(&push->stack_b[0], &push->stack_a[0]);
		push->size_b--;
		push->size_a++;
		while (++i < push->size_b)
			push->stack_b[i] = push->stack_b[i + 1];
	}
	ft_print_stack(push);
}

void	rotate_operations(t_push *push, char letter) //Операции RA RB RR
{
	int tmp;
	int i;

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
		rotate_operations(push, 'a');
		rotate_operations(push, 'b');
	}
	ft_print_stack(push);
}

void	reverse_rotate_operations(t_push	*push, char letter) //Операции RRA RRB RRR
{
	int tmp;
	int i;

	i = letter == 'a' ? push->size_a - 1 : push->size_b - 1;
	tmp = letter == 'a' ? push->stack_a[i] : push->stack_b[i];
	if (letter == 'a' && push->size_a > 0)
	{
		while (i > 0)
		{
			push->stack_a[i] = push->stack_a[i - 1];
			i--;
		}
		push->stack_a[0] = tmp;
	}
	else if (letter == 'b' && push->size_b > 0)
	{
		while (i > 0)
		{
			push->stack_b[i] = push->stack_b[i - 1];
			i--;
		}
		push->stack_b[0] = tmp;
	}
	else if (letter == 'r')
	{
		reverse_rotate_operations(push, 'a');
		reverse_rotate_operations(push, 'b');
	}
	ft_print_stack(push);
}
