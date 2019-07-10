/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:07 by waddam            #+#    #+#             */
/*   Updated: 2019/07/10 23:59:58 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_main_additions(t_push *push)
{
	ft_check_repeat(push);
	push->max = ft_max(push);
	push->min = ft_min(push);
	if (ft_check_cyclic_sorting(push) == 1 || ft_check_sort(push) == 1)
	{
		ft_stack_balance(push);
		exit(0);
	}
	ft_separate_stack(push);
}

int			main(int argc, char **argv)
{
	int		count;
	t_push	push;

	count = 0;
	ft_initialization_push(&push);
	while (++count < argc)
		ft_valid(argv[count], &push);
	if (push.size_a > 0)
	{
		push.stack_a = (int *)malloc(push.size_a * sizeof(int));
		push.stack_b = (int *)malloc(push.size_a * sizeof(int));
		count = 0;
		while (++count < argc)
			ft_record(&push, argv[count]);
		ft_main_additions(&push);
		while (push.size_b > 0)
		{
			push.fl = 0;
			ft_count_operation(&push);
		}
		ft_stack_balance(&push);
	}
	free(push.stack_a);
	free(push.stack_b);
	return (0);
}
