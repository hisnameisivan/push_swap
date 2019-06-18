/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:19:59 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/18 23:16:46 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialization_push(t_push *push)
{
	push->i = 0;
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->temp_arr = NULL;
	push->size_a = 0;
	push->size_b = 0;
	push->size_temp_arr = 0;
	push->max = 0;
	push->min  = 0;
	push->res = 0;
	push->index = -1;
	push->fl = 0;
}

void	ft_initialization_swap(t_swap *swap)
{
	swap->pa = 0;
	swap->pb = 0;
	swap->ra = 0;
	swap->rb = 0;
	swap->rr = 0;
	swap->rra = 0;
	swap->rrb = 0;
	swap->rrr = 0;
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



void	printstack(t_push *push)
{
	int i;
	int t = push->size_a > push->size_b ? push->size_a : push->size_b;

	i = -1;
	t = i * 1; /* стереть */
	// printf("----------------------------\n");
	// printf("|%-11c ||" "%11c |\n", 'a', 'b');
	// printf("----------------------------");
	// printf("\n");
	// while (++i < t)
	// {
	// 	if (i < push->size_a)
	// 		printf("|%11ld |", push->stack_a[i]);
	// 	else
	// 		printf("|%11s |", " ");
	// 	if (i < push->size_b)
	// 		printf("|%11ld |\n", push->stack_b[i]);
	// 	else
	// 		printf("|%11s |\n", " ");
	// }
	// printf("----------------------------\n\n");
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


void	ft_stack_balance(t_push *push)
{
	int	i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	if (i < push->size_a / 2 + 1)
	{
		while (i > 0)
		{
			printf("ra\n");
			rotate_operations(push, 'a');
			i--;
		}
	}
	else
	{
		i = push->size_a - i;
		while (i > 0)
		{
			printf("rra\n");
			reverse_rotate_operations(push, 'a');
			i--;
		}
	}
}

void	ft_analyze_operation(t_push *push, t_swap *swap, int i)
{
	swap->pa = 1;
	while (swap->ra != 0 && swap->rb != 0)
	{
		swap->ra--;
		swap->rb--;
		swap->rr++;
	}
	while (swap->rra != 0 && swap->rrb != 0)
	{
		swap->rra--;
		swap->rrb--;
		swap->rrr++;
	}
}


void	ft_sort_stack(t_push *push, t_swap *swap)
{
	ft_counter(push, swap, push->index);

	while (swap->ra > 0)
	{
		printf("ra\n");
		rotate_operations(push, 'a');
		swap->ra--;
	}
	while (swap->rb > 0)
	{
		printf("rb\n");
		rotate_operations(push, 'b');
		swap->rb--;
	}
	while (swap->rr > 0)
	{
		printf("rr\n");
		rotate_operations(push, 'r');
		swap->rr--;
	}
	while (swap->rra > 0)
	{
		printf("rra\n");
		reverse_rotate_operations(push, 'a');
		swap->rra--;
	}
	while (swap->rrb > 0)
	{
		printf("rrb\n");
		reverse_rotate_operations(push, 'b');
		swap->rrb--;
	}
	while (swap->rrr > 0)
	{
		printf("rrr\n");
		reverse_rotate_operations(push, 'r');
		swap->rrr--;
	}
	printf("pa\n");
	push_operations(push, 'a');
}


void	ft_write_index_res(t_push *push, t_swap *swap, int i)
{
	if (push->fl == 0)
		{
			push->res = swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + swap->rrr;
			push->index = i;
			push->fl = 1;
		}
	else if (push->fl == 1 && ((push->res > swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + swap->rrr) || (push->size_b == 1)))
	{
		push->res = swap->ra + swap->rb + swap->rr + swap->rra + swap->rrb + swap->rrr;
		push->index = i;
	}
}


void	ft_counter(t_push *push, t_swap *swap, int i) /* считает сколько требуется операций, чтобы перебросить i-ый элемент из b в a */
{
	int j;
	int tmp;

	j = 0;
	tmp = push->stack_b[i];
	if (i < push->size_b - i)
		swap->rb = i;
	else
		swap->rrb = push->size_b - i;
	while (j + 1 < push->size_a)
	{
		if ((push->stack_a[j] < tmp) && (push->stack_a[j + 1] > tmp))
		{
			if (j + 1 < push->size_a - (j + 1))
				swap->ra = j + 1;
			else
				swap->rra = push->size_a - (j + 1);
			break ;
		}
		else
			j++;
	}
	ft_analyze_operation(push, swap, i);
}


void	ft_count_operation(t_push *push)
{
	int		i;
	int		j;
	int		tmp;
	t_swap	*swap;

	i = 0;
	if (!(swap = (t_swap *)malloc(sizeof(t_swap))))
		return ;
	while (i < push->size_b)
	{
		ft_initialization_swap(swap);
		ft_counter(push, swap, i);
		ft_write_index_res(push, swap, i);
		i++;
	}
	ft_initialization_swap(swap);
	ft_sort_stack(push, swap);
	free(swap);
}


void	ft_sort_three_item(t_push *push)
{
	printf("sa\n");
	if (push->stack_a[1] == push->min)
	{
		swap_operations(push, 'a');
		return ;
	}
	else
		swap_operations(push, 'a');
	if (push->stack_a[0] == push->min)
	{
		rotate_operations(push, 'a');
		printf("ra\n");
	}
	else if (push->stack_a[2] == push->min)
	{
		reverse_rotate_operations(push, 'a');
		printf("rra\n");
	}
}



int		ft_check_sort_elements(t_push *push)
{
	if ((push->stack_a[0] < push->stack_a[1] && push->stack_a[1] < push->stack_a[2]) ||
		(push->stack_a[0] == push->max && push->stack_a[1] < push->stack_a[2]) ||
		(push->stack_a[0] < push->stack_a[1] && push->stack_a[2] == push->min))
		return (1);
	else
		return (0);
}


void	ft_separate_stack(t_push *push) /* от 17/06 оставляем min, max, рандом и сортируем  */
{
	int i;

	i = 0;
	while (push->size_a != 3)
	{
		if ((push->stack_a[i] != push->min) && (push->stack_a[i] != push->max))
		{
			if (i < push->size_a - i)
			{
				while (i > 0)
				{
					printf("ra\n");
					rotate_operations(push, 'a');
					i--;
				}
			}
			else
			{
				while (push->size_a - i > 0)
				{
					printf("rra\n");
					reverse_rotate_operations(push, 'a');
					i++;
				}
			}
			printf("pb\n");
			push_operations(push, 'b');
			i = 0;
		}
		else
			i++;

	}
	if (push->size_a == 3 && ft_check_sort_elements(push) == 0)
		ft_sort_three_item(push);
}


int		ft_check_cyclic_sorting(t_push *push)
{
	int i;

	i = 0;
	while (push->stack_a[i] != push->min)
		i++;
	while (i + 1 < push->size_a)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	if (push->stack_a[i] != push->max)
	{
		if (push->stack_a[0] > push->stack_a[i])
			i = 0;
		else
			return (0);
	}
	while (i + 1 != push->min)
	{
		if (push->stack_a[i] < push->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}


// int		main(int ac, char **av)
// {
// 	int		count;
// 	t_push	*push;

// 	count = 0;
// 	push = (t_push*)malloc(sizeof(t_push));
// 	ft_initialization_push(push);
// 	while (++count < ac)
// 		ft_valid(av[count], push);
// 	push->stack_a = (long *)malloc(push->size_a * sizeof(long));
// 	push->stack_b = (long *)malloc(push->size_a * sizeof(long));
// 	count = 0;
// 	while (++count < ac)
// 		ft_record(push, av[count]);
// 	ft_check_repeat(push);
// 	push->max = ft_max(push);
// 	push->min = ft_min(push);
// 	//ft_select_to_leave_a(push);
// 	if (ft_check_cyclic_sorting(push) == 1)
// 	{
// 		ft_stack_balance(push);
// 		exit (0);
// 	}
// 	ft_separate_stack(push);
// 	while (push->size_b)
// 	{
// 		push->fl = 0;
// 		ft_count_operation(push);
// 	}
// 	ft_stack_balance(push);
// 	exit (0);
// }
