/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sortings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:05 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 22:09:22 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max(t_stack *a)
{
	int	max;

	max = a->val;
	while (a)
	{
		if (max < a->val)
			max = a->val;
		a = a->next;
	}
	return (max);
}

int	*sort_array(t_lists *structure)
{
	int		temp;
	int		i;
	int		cnt;

	cnt = 0;
	while (cnt < structure->size)
	{
		i = 0;
		while (i < structure->size - 1)
		{
			if (structure->array[i] > structure->array[i + 1])
			{
				temp = structure->array[i];
				structure->array[i] = structure->array[i + 1];
				structure->array[i + 1] = temp;
			}
			i++;
		}
		cnt++;
	}
	cnt = 0;
	return (structure->array);
}

int	is_sorted(t_lists *structure, t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->val != structure->array[i])
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}

void	stack_a_fillment(t_stack **a, t_lists *structure, int argc, char **argv)
{
	int			i;
	int			j;
	long long	check;

	i = 1;
	j = 0;
	while (i < argc)
	{
		check = ft_atoi(argv[i]);
		if (check > INT_MAX || check < INT_MIN)
		{
			leaks_cleaner(a, NULL, structure);
			error_dup();
		}
		structure->array[j] = (int) check;
		if (doubles_checker((int) check, structure, j))
		{
			leaks_cleaner(a, NULL, structure);
			error_dup();
		}
		ft_listback(a, ft_lstinit((int) check));
		i++;
		j++;
	}
}
