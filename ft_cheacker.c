/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheacker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:26:39 by waddam            #+#    #+#             */
/*   Updated: 2019/06/25 23:43:01 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_sort(t_push *push)
{
	int		i;
	int		last;

	i = 1;
	if (push->stack_a[0] != push->min)
		return (0);
	last = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] < last)
			return (0);
		last = push->stack_a[i];
		i++;
	}
	if (push->stack_a[push->size_a - 1] != push->max)
		return (0);
	return (1);
}

static void	ft_do_operation(t_push *push, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate_operations(push, 'a');
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate_operations(push, 'b');
	else if (ft_strcmp(line, "rr") == 0)
		ft_rotate_operations(push, 'r');
	else if (ft_strcmp(line, "rra") == 0)
		ft_reverse_rotate_operations(push, 'a');
	else if (ft_strcmp(line, "rrb") == 0)
		ft_reverse_rotate_operations(push, 'b');
	else if (ft_strcmp(line, "rrr") == 0)
		ft_reverse_rotate_operations(push, 'r');
	else if (ft_strcmp(line, "pa") == 0)
		ft_push_operations(push, 'a');
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_operations(push, 'b');
	else if (ft_strcmp(line, "sa") == 0)
		ft_swap_operations(push, 'a');
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap_operations(push, 'b');
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void		ft_read_input(t_push *push)
{
	char	*line;

	while (ft_fgnl(0, &line) > 0)
	{
		ft_do_operation(push, line);
		free(line);
	}
}
