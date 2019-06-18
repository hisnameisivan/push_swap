/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheacker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:53:34 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/18 21:46:51 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker(t_push *push)
{
	int		i;
	int		pre;

	i = 1;
	if (push->stack_a[0] != push->min)
		return (0);
	pre = push->stack_a[0];
	while (i < push->size_a)
	{
		if (push->stack_a[i] < pre)
			return (0);
		pre = push->stack_a[i];
		i++;
	}
	if (push->stack_a[push->size_a - 1] != push->max)
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
	// while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	// {
	// 	buff[ret] = '\0';
	// 	del = temp;
	// 	temp = ft_strjoin(temp, buff);
	// 	i++;
	// }
	temp = "pb\nsa\nra\npa\nrra";
	// if (i == 0)
	// 	return ;
	i = -1;
	oper = ft_strsplit(temp, '\n');
	while (oper[++i] != NULL)
	{
		// if (i == 0)
		// 	oper[i] += 35;
		doop(push, oper, i);
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
		read_input(push);
		printstack(push);
		if (checker(push) == 1)
			printf("OK\n");
		else
			printf("KO\n");
	}
	exit(0);
}