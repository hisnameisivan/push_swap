/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:36:57 by waddam            #+#    #+#             */
/*   Updated: 2019/07/10 23:57:36 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_skip_null_sign(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] == '0' || argv[i] == '+')
		i++;
	return (i);
}

static int	ft_check_overflow(char *argv, int num)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_itoa(num);
	if (num != 0)
	{
		j = ft_skip_null_sign(argv);
		i = ft_skip_null_sign(str);
	}
	while (str[i] != '\0')
	{
		if (argv[j] != str[i])
			return (1);
		i++;
		j++;
	}
	free(str);
	return (0);
}

void		ft_record(t_push *push, char *argv)
{
	while (*argv != '\0')
	{
		if (argv[0] == '-' && argv[1] == 'v')
			argv++;
		else if ((*argv >= '0' && *argv <= '9')
		|| (*argv == '-' || *argv == '+'))
		{
			push->stack_a[push->i] = ft_atoi(argv);
			if (ft_check_overflow(argv, push->stack_a[push->i]) == 1)
			{
				ft_printf("Error\n");
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
