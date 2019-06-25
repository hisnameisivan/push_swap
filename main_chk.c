/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:54:52 by waddam            #+#    #+#             */
/*   Updated: 2019/06/25 23:43:10 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
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
		ft_check_repeat(&push);
		push.max = ft_max(&push);
		push.min = ft_min(&push);
		ft_read_input(&push);
		ft_print_stack(&push); //?
		ft_check_sort(&push) ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	free(push.stack_a);
	free(push.stack_b);
	return (0);
}
