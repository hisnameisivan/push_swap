/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheacker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:53:34 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/18 23:56:55 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker(t_push *push)
{
	int		i;
	int		pre;

	i = 1;
	if (push->stack_a[0] != ft_min(push))
		return (0);
	pre = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] < pre)
			return (0);
		pre = push->stack_a[i];
		i++;
	}
	if (push->stack_a[push->size_a - 1] != ft_max(push))
		return (0);
	return (1);
}

void	doop(t_push *push, char **oper, int i)
{
	if (ft_strcmp(oper[i], "ra") == 0)
		rotate_operations(push, 'a');
	else if (ft_strcmp(oper[i], "rb") == 0)
		rotate_operations(push, 'b');
	else if (ft_strcmp(oper[i], "rr") == 0)
		rotate_operations(push, 'r');
	else if (ft_strcmp(oper[i], "rra") == 0)
		reverse_rotate_operations(push, 'a');
	else if (ft_strcmp(oper[i], "rrb") == 0)
		reverse_rotate_operations(push, 'b');
	else if (ft_strcmp(oper[i], "rrr") == 0)
		reverse_rotate_operations(push, 'r');
	else if (ft_strcmp(oper[i], "pa") == 0)
		push_operations(push, 'a');
	else if (ft_strcmp(oper[i], "pb") == 0)
		push_operations(push, 'b');
	else if (ft_strcmp(oper[i], "sa") == 0)
		swap_operations(push, 'a');
	else if (ft_strcmp(oper[i], "sb") == 0)
		swap_operations(push, 'b');
	else
	{
		printf("Error\n");
		exit(0);
	}
}

void	read_input(t_push *push)
{
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		ret;
	char	*temp;
	char	**oper;
	int		i;

	i = 0;
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		i++;
	}
	//temp = "rra\nrra\npb\nra\npa\nra\nra"
	//temp = "ra\n";
	if (i == 0)
		return ;
	i = -1;
	oper = ft_strsplit(temp, '\n');
	while (oper[++i] != NULL)
	{
		//printf("%s\n", oper[i]);
		// if (i == 0)
		// 	oper[i] += 35;
		doop(push, oper, i); // выполняет считанные операции (там же частичная валидация)
	}
}

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
		read_input(push); //считывает со стандартного ввода
		printstack(push);
		if (checker(push) == 1) // проверка, что стек отсортирован (каждый следующий элемент больше предыдущего)
			printf("OK\n");
		else
			printf("KO\n");
	}
	exit(0);
}
