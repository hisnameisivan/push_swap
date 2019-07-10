/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:22:26 by waddam            #+#    #+#             */
/*   Updated: 2019/07/11 00:05:00 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_count_digits(char *argv, t_push *push)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ' || (push->vis && argv[i] == '-')
			|| (push->vis && argv[i] == 'v'))
		{
			i++;
			flag = 0;
		}
		else if (((argv[i] >= '0' && argv[i] <= '9')
			|| (argv[i] == '-' || argv[i] == '+')) && flag == 0)
		{
			push->size_a++;
			flag = 1;
			i++;
		}
		else if ((argv[i] >= '0' && argv[i] <= '9') && flag == 1)
			i++;
	}
}

void		ft_valid(char *argv, t_push *push)
{
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (((argv[i] == '-' || argv[i] == '+') &&
			(argv[i + 1] >= '0' && argv[i + 1] <= '9')) &&
			(i == 0 || argv[i - 1] == ' '))
			i++;
		else if ((argv[i] >= '0' && argv[i] <= '9') || (argv[i] == ' '))
			i++;
		else if (argv[0] == '-' && argv[1] == 'v')
		{
			push->vis = 1;
			i = i + 2;
		}
		else
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
	ft_count_digits(argv, push);
}

int			ft_check_repeat(t_push *push)
{
	int		i;
	int		j;

	i = 0;
	while (i < push->size_a)
	{
		j = 0;
		while (j < push->size_a)
		{
			if (i == j || push->stack_a[i] != push->stack_a[j])
				j++;
			else
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		i++;
	}
	return (1);
}
