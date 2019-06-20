/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:13:07 by waddam            #+#    #+#             */
/*   Updated: 2019/06/20 23:21:04 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **argv)
{
	int		count;
	t_push	*push;

	count = 0;
	push = (t_push*)malloc(sizeof(t_push));
	ft_initialization_push(push);
	while (++count < ac)
		ft_valid(argv[count], push);
	push->stack_a = (int *)malloc(push->size_a * sizeof(int));
	push->stack_b = (int *)malloc(push->size_a * sizeof(int));
	count = 0;
	while (++count < ac)
		ft_record(push, argv[count]);
	ft_check_repeat(push);
	push->max = ft_max(push);
	push->min = ft_min(push);
	if (ft_check_cyclic_sorting(push) == 1 || ft_checker(push) == 1)
	{
		ft_stack_balance(push);
		exit (0);
	}
	ft_separate_stack(push);
	while (push->size_b)
	{
		push->fl = 0;
		ft_count_operation(push);
	}
	ft_stack_balance(push);
	exit (0);
}
