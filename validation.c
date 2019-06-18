/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:56:04 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/18 20:02:07 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_digits(char *av, t_push *push)
{
	int i;
	int fl;

	i = 0;
	fl = 0;
	while (av[i] != '\0')
	{
		if (av[i] == ' ')
		{
			i++;
			fl = 0;
		}
		else if (((av[i] >= '0' && av[i] <= '9') || av[i] == '-') && fl == 0)
		{
			push->size_a++;
			fl = 1;
			i++;
		}
		else if ((av[i] >= '0' && av[i] <= '9') && fl == 1)
			i++;
	}
}

int		ft_check_repeat(t_push	*push)
{
	int	i;
	int j;

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
				printf("repeat");
				exit(0);
			}
		}
		i++;
	}
	return (1);
}

void	ft_valid(char *av, t_push *push)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if (((av[i] == '-'  || av[i] == '+') && (av[i + 1] >= '0' && av[i + 1] <= '9')) && (i == 0 || av[i - 1] == ' '))
			i++;
		else if ((av[i] >= '0'&& av[i] <= '9') || (av[i] == ' '))
			i++;
		else
		{
			printf("invalid file\n");
			exit(0);
		}
	}
	ft_count_digits(av, push);
}

int		ft_skip_null_znak(char *argv)
{
	int i;

	i = 0;
	while (argv[i] == '0' || argv[i] == '-' || argv[i] == '+')
		i++;
	return (i);
}

int			ft_check_overflow(char *argv, int num) /*  Проверка на переполнение int */
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_itoa(num);
	if (num != 0)
	{
		j = ft_skip_null_znak(argv);
		i = ft_skip_null_znak(str);
	}
	// else
	// 	j = 0;
	while (str[i] != '\0')
	{
		if (argv[j] != str[i])
			return (1);
		i++;
		j++;
	}
	return (0);
}