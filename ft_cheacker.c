/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheacker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:26:39 by waddam            #+#    #+#             */
/*   Updated: 2019/06/21 00:03:58 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(t_push *push)
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

static void	doop(t_push *push, char **oper, int i)
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
		ft_printf("Error\n");
		exit(0);
	}
}

static void ft_valid_buf(char **buff)
{
	int i;

	i = 0;
	while (buff[i] != NULL)
	{
		if (ft_strcmp(buff[i], "ra") == 0)
			return ;
		else if (ft_strcmp(buff[i], "rb") == 0)
			return ;
		else if (ft_strcmp(buff[i], "rr") == 0)
			return ;
		else if (ft_strcmp(buff[i], "rra") == 0)
			return ;
		else if (ft_strcmp(buff[i], "rrb") == 0)
			return ;
		else if (ft_strcmp(buff[i], "rrr") == 0)
			return ;
		else if (ft_strcmp(buff[i], "pa") == 0)
			return ;
		else if (ft_strcmp(buff[i], "pb") == 0)
			return ;
		else if (ft_strcmp(buff[i], "sa") == 0)
			return ;
		else if (ft_strcmp(buff[i], "sb") == 0)
			return ;
		else
		{
			ft_printf("%s\n", buff[i]);
			ft_printf("Error\n");
			exit(0);
		}
	}
}

void	ft_read_input(t_push *push)
{
	char	buff[BUFF_SIZE + 1];
	char	*del;
	int		ret;
	char	*temp;
	char	**oper;
	int		i;

	i = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		i++;
		oper = ft_strsplit(temp, '\n');
		ft_valid_buf(oper);
	}
	if (i == 0)
		return ;
	i = -1;
	oper = ft_strsplit(temp, '\n');
	while (oper[++i] != NULL)
	{
		doop(push, oper, i);
	}
}
