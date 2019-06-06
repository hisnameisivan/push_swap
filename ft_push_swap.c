/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:19:59 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/06 22:38:46 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialization(t_push *push)
{
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->index = 	NULL;
	push->size_a = 0;
	push->size_b = 0;
	push->max = 0;
	push->i = 0;
}

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

void	printstack(t_push *push)
{
	int i;
	int t = push->size_a > push->size_b ? push->size_a : push->size_b;

	i = -1;
	printf("----------------------------\n");
	printf("|%-11c ||" "%11c |\n", 'a', 'b');
	printf("----------------------------");
	printf("\n");
	while (++i < t)
	{
		if (i < push->size_a)
			printf("|%11ld |", push->stack_a[i]);
		else
			printf("|%11s |", " ");
		if (i < push->size_b)
			printf("|%11ld |\n", push->stack_b[i]);
		else
			printf("|%11s |\n", " ");
	}
	printf("----------------------------\n\n");
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
	str = ft_itoa(num);
	if (num != 0)
		j = ft_skip_null_znak(argv);
	else
		j = 0;
	while (str[i] != '\0')
	{
		if (argv[j] != str[i])
			return (1);
		i++;
		j++;
	}
	return (0);
}

void	ft_record(t_push *push, char *argv)
{
	while (*argv != '\0')
	{
		if ((*argv >= '0' && *argv <= '9') || (*argv == '-'))
		{
			push->stack_a[push->i] = ft_atoi(argv);
			if (ft_check_overflow(argv, push->stack_a[push->i]) == 1)
			{
				printf("overflow");
				exit(0);
			}
			while (*argv != ' ' && *argv != '\0')
				argv++;
			argv--;
			push->i++;
		}
		argv++;
	}
}

// int		main(int argc, char **argv)
// {
// 	int		count;
// 	t_push	*push;

// 	count = 0;
// 	push = (t_push*)malloc(sizeof(t_push));
// 	ft_initialization(push);
// 	while (++count < argc)
// 		ft_valid(argv[count], push);
// 	push->stack_a = (int *)malloc(push->size * sizeof(int));
// 	push->stack_b = (int *)malloc(push->size * sizeof(int));
// 	count = 0;
// 	//printf("%s\n", argv[1]);
// 	while (++count < argc)
// 		ft_record(push, argv[count]);
// 	ft_check_repeat(push);
// 	printstack(push);
// 	return (0);
// }


// int		ft_analize_up_down(t_push *push, int i)
// {
// 	int		count;

// 	count = (i < (push->size_a - i) ? i : push->size_a - i);
// 	return (count);
// }

void	ft_separate_stack(t_push *push, int max, int min, int med)
{
	int i;
	int	true_i;

	i = 0;
	while (i < push->size_a)
	{
		if (push->stack_a[i] != max && push->stack_a[i] != min && push->stack_a[i] != med) 
		{
			if (i < push->size_a - i)
			{
				while (i > 0)
				{
					rotate_operations(push, 'a');
					i--;
				}
			}
			else
			{
				while (push->size_a - i > 0)
				{
					reverse_rotate_operations(push, 'a');
					i++;
				}
			}
			push_operations(push, 'b');
			i = 0;
		}
		i++;
	}
	printstack(push);
}

void	ft_sep_stack(t_push *push)
{
	int		i;
	int		j;
	int		temp;

	i = 1;
	j = 1;
	push->temp_arr = (int *)malloc(sizeof(int) * push->size_a);
	push->temp_arr[0] = push->stack_a[0];
	temp = push->stack_a[0];
	while (push->stack_a[i] < push->max)
	{
		if (push->stack_a[i] > push->stack_a[0] && push->stack_a[i] > temp)
		{
			temp = push->stack_a[i];
			push->temp_arr[j] = push->stack_a[i];
			j++;
		}
		i++;
	}
	push->temp_arr = push->stack_a[i];
	i++;
	while (i < push->size_a)
	{
		if (push->stack_a[i] > push->stack_a[0] && push->stack_a[i] > temp)
		{
			temp = push->stack_a[i];
			push->temp_arr[j] = push->stack_a[i];
			j++;
		}
		i++;
	}
	
}

int		main(int ac, char **av)
{
	int		count;
	t_push	*push;

	count = 0;
	push = (t_push*)malloc(sizeof(t_push));
	ft_initialization(push);
	while (++count < ac)
		ft_valid(av[count], push);
	push->stack_a = (long *)malloc(push->size_a * sizeof(long));
	push->stack_b = (long *)malloc(push->size_a * sizeof(long));
	push->index = (long *)malloc(push->size_a * sizeof(long));
	count = 0;
	while (++count < ac)
		ft_record(push, av[count]);
	ft_check_repeat(push);

	//ft_separate_stack(push, ft_max(push), ft_min(push),ft_median(push));
	push->max = ft_max(push);
	ft_sep_stack(push);

	// printf("%d\n", push->index[0]);
	// printf("%d\n", push->index[1]);
	// printf("%d\n", push->index[2]);
	// printf("%d\n", push->index[3]);
	// printf("%d\n", push->index[4]);
	// printf("%d\n", ft_max(push));
	// printf("%d\n", ft_min(push));
	// printf("%d\n", ft_median(push));
	// printstack(push);
	// push_operations(push, 'b');
	// push_operations(push, 'b');
	// push_operations(push, 'b');
	// push_operations(push, 'b');
	// reverse_rotate_operations(push, 'r');
	// reverse_rotate_operations(push, 'r');
	// reverse_rotate_operations(push, 'r');
	// reverse_rotate_operations(push, 'r');
	exit (0);
}
