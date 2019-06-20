#include "push_swap.h"

int		main(int ac, char **av)
{
	int		count;
	t_push	*push;

	count = 0;
	push = (t_push*)malloc(sizeof(t_push));
	ft_initialization_push(push);
	while (++count < ac)
		ft_valid(av[count], push);
	push->stack_a = (long *)malloc(push->size_a * sizeof(long));
	push->stack_b = (long *)malloc(push->size_a * sizeof(long));
	count = 0;
	while (++count < ac)
		ft_record(push, av[count]);
	ft_check_repeat(push);
	push->max = ft_max(push);
	push->min = ft_min(push);
	if (ft_check_cyclic_sorting(push) == 1 || checker(push) == 1)
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
