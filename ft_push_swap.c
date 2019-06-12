/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:19:59 by draudrau          #+#    #+#             */
/*   Updated: 2019/06/12 22:46:40 by draudrau         ###   ########.fr       */
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

int		ft_random(t_push *push)
{
	int i;

	i = 0;
	while (i < push->size_a)
	{
		if (push->stack_a[i] != push->max && push->stack_a[i] != push->min)
			return (push->stack_a[i]);
		i++;
	}
	return (123);
}

void	ft_select_to_leave_a(t_push *push) /* идем от min элемента и собираем отсортированную последовательность */
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	push->temp_arr = (int *)malloc(sizeof(int) * push->size_a);
	while (push->stack_a[i] != push->min)
		i++;
	push->temp_arr[j] = push->stack_a[i];
	j++;
	while (++i < push->size_a)
	{
		if (push->stack_a[i] == push->max)
		{
			push->temp_arr[j] = push->stack_a[i];
			break ;
		}
		else if (push->stack_a[i] > push->temp_arr[j - 1])
		{
			push->temp_arr[j] = push->stack_a[i];
			j++;
		}
	}
	i = 0;
	while (push->stack_a[i] != push->min)
	{
		if (push->stack_a[i] > push->temp_arr[j])
		{
			push->temp_arr[j + 1] = push->stack_a[i];
			j++;
		}
		i++;
	}
	push->size_temp_arr = j + 1;
}

int 	ft_stay_item(t_push *push, int num)
{
	int i;

	i = 0;
	while (i < push->size_temp_arr)
	{
		if (num != push->temp_arr[i])
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_separate_stack(t_push *push)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < push->size_a)
	{
		if (ft_stay_item(push, push->stack_a[i]) == 1)
			i++;
		else
		{
			if (push->size_a == 3) /* чтобы оставить в стеке а как минимум 3 элемента, но не факт что они будут отсортированы */
				break ;
			if (i <= push->size_a / 2)
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
	}
	if (push->size_a == 3 && ft_check_sort_elements(push) == 0)
		ft_sort_three_item(push);
}

void	ft_sort_three_item(t_push *push)
{
	swap_operations(push, 'a');
	printf("sa\n");
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

void	ft_free(t_swap ***temp, int i)
{
	while (--i >= 0)
	{
		free((*temp)[i]);
		(*temp)[i] = NULL;
	}
	free(*temp);
	*temp = NULL;
}

t_swap	**ft_allocate_memory(t_push *push)
{
	int		i;
	t_swap 	**temp;

	i = 0;
	if (!(temp = (t_swap **)malloc(sizeof(t_swap *) * (push->size_b + 1))))
		return (NULL);
	while (i < push->size_b)
	{
		if (!(temp[i] = (t_swap *)malloc(sizeof(t_swap))))
		{
			ft_free(&temp, i);
			return (NULL);
		}
		ft_initialization_swap(temp[i]);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

void	ft_analyze_operation(t_push *push, t_swap **swap, int count_arr, int count_b)
{
	swap[count_arr]->pa = 1;
	while (swap[count_arr]->ra != 0 && swap[count_arr]->rb != 0)
	{
		swap[count_arr]->ra--;
		swap[count_arr]->rb--;
		swap[count_arr]->rr++;
	}
	while (swap[count_arr]->rra != 0 && swap[count_arr]->rrb != 0)
	{
		swap[count_arr]->rra--;
		swap[count_arr]->rrb--;
		swap[count_arr]->rrr++;
	}
	if (push->fl == 0)
	{
		push->res = swap[count_arr]->ra + swap[count_arr]->rb +
					swap[count_arr]->rr + swap[count_arr]->rra +
					swap[count_arr]->rrb + swap[count_arr]->rrr;
		push->index = count_b;
		push->fl  = 1;
	}
	else if (push->fl  == 1 && push->res > swap[count_arr]->ra + swap[count_arr]->rb + swap[count_arr]->rr + swap[count_arr]->rra
	+ swap[count_arr]->rrb + swap[count_arr]->rrr)
	{
		push->res = swap[count_arr]->ra + swap[count_arr]->rb +
					swap[count_arr]->rr + swap[count_arr]->rra +
					swap[count_arr]->rrb + swap[count_arr]->rrr;
		push->index = count_b;
	}
}

void	ft_sort_stack(t_push *push, t_swap *swap)
{
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
	while (swap->rrb> 0)
	{
		printf("rrb\n");
		reverse_rotate_operations(push, 'b');
		swap->rrb--;
	}
	while (swap->rrr> 0)
	{
		printf("rrr\n");
		reverse_rotate_operations(push, 'r');
		swap->rrr--;
	}
	printf("pa\n");
	push_operations(push, 'a');
}

void	ft_count_operation(t_push *push)
{
	int		count_b;
	int		count_a;
	int		count_arr;
	t_swap **swap;

	count_b = 0;
	count_a = 0;
	count_arr = 0;
	swap = ft_allocate_memory(push);
	while (count_b < push->size_b)
	{
		if (count_b < push->size_b / 2 + 1)
			swap[count_arr]->rb = count_b;
		else
			swap[count_arr]->rrb = push->size_b - count_b;
		count_a = 0;
		while (count_a + 1 < push->size_a) /* если мы не нашли пару  i < элемента < i + 1 значит вставляем элемент в начало -> ra = 0 */
		{
			if ((push->stack_a[count_a] < push->stack_b[count_b]) && (push->stack_a[count_a + 1] > push->stack_b[count_b]))
			{
				if (count_a + 1 < push->size_a / 2 + 1)
					swap[count_arr]->ra = count_a + 1;
				else
					swap[count_arr]->rra = push->size_a - (count_a + 1);
				break ;
			}
			else
				count_a++;
		}
		if (push->stack_b[count_b] == push->min)
		{
			count_a = 0;
			while (push->stack_a[count_a] != push->max && count_a < push->size_a)
			{
				count_a++;
			}
			if (count_a + 1 != push->size_a) /* если max элемент не последний */
			{
				if (count_a + 1 < push->size_a / 2 + 1)
				{
					swap[count_arr]->ra = count_a;
				}
				else
					swap[count_arr]->rra = push->size_a - (count_a + 1);
			}
		}
		ft_analyze_operation(push, swap, count_arr, count_b);
		count_b++;
	// printf("pa = %d, pb = %d,\nra = %d, rb = %d, rr = %d,\nrra = %d, rrb = %d, rrr = %d\n",
	// 	swap[count_arr]->pa,
	// 	swap[count_arr]->pb,
	// 	swap[count_arr]->ra,
	// 	swap[count_arr]->rb,
	// 	swap[count_arr]->rr,
	// 	swap[count_arr]->rra,
	// 	swap[count_arr]->rrb,
	// 	swap[count_arr]->rrr
	// 	);
		count_arr++;
	}
	ft_sort_stack(push, swap[push->index]);
	ft_free(&swap, 0);

}

void	ft_stack_balance(t_push *push)
{
	int		min;
	int		i;

	i = 0;
	while (push->stack_a[i] != push->min)
	{
		i++;
	}
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
	ft_select_to_leave_a(push);
	ft_separate_stack(push);
	while (push->size_b)
	{
		ft_count_operation(push);
	}
	ft_stack_balance(push);
	exit (0);
}
