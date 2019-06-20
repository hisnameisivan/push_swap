#include "push_swap.h"

int		main(int ac, char **av)
{
	int		count;
	t_push	*push;

	count = 0;
	push = (t_push *)malloc(sizeof(t_push));
	ft_initialization_push(push);
	while (++count < ac)
		ft_valid(av[count], push);
	if (push->size_a > 0)
	{
		push->stack_a = (long *)malloc(push->size_a * sizeof(long));
		push->stack_b = (long *)malloc(push->size_a * sizeof(long));
		count = 0;
		while (++count < ac)
			ft_record(push, av[count]);
		ft_check_repeat(push);
		push->max = ft_max(push);
		push->min = ft_min(push);
		read_input(push); //считывает со стандартного ввода
		printstack(push);
		if (checker(push) == 1) // проверка, что стек отсортирован (каждый следующий элемент больше предыдущего)
			printf("OK\n");
		else
			printf("KO\n");
	}
	exit(0);
}