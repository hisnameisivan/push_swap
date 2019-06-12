#include "push_swap.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		count;
	t_push	*push;
	int		check; // сигнал того, что стек отсортирован

	count = 0;
	push = (t_push*)malloc(sizeof(t_push));
	ft_initialization_push(push);
	while (++count < ac)
		ft_valid(av[count], push);
	push->stack_a = (long *)malloc(push->size_a * sizeof(long));
	push->stack_b = (long *)malloc(push->size_a * sizeof(long));
	//push->index = (long *)malloc(push->size_a * sizeof(long));
	count = 0;
	while (++count < ac)
		ft_record(push, av[count]);
	ft_check_repeat(push);
	while (check != 0)
	{
		get_next_line(0, &line);
		x = ft_strcmp(line, "OK");
		y = ft_strcmp(line, "KO");
		//printf("%s\nx = %d\ny = %d\n", line, x, y);
		free(line);
	}
}
