/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_butterfly_sortings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:07:56 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 18:49:25 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	numbers_for_algos(t_lists *structure)
{
	int	n;

	if (structure->size > 300)
		n = 30;
	else
		n = 15;
	return (n);
}

void	algos_butterfly_start(t_stack **a, t_stack **b, t_lists *structure)
{
	int		i;
	double	size;
	int		n;

	i = 0;
	n = numbers_for_algos(structure);
	size = ft_lstsize(*a);
	while ((*a) != NULL)
	{
		if (i > 1 && (*a)->index <= i)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else if ((*a)->index <= i + n)
		{
			pb(a, b, 1);
			i++;
		}
		else if ((*a)->index >= i)
			ra(a, 1);
	}
}

void	algos_butterfly_finish(t_stack **a, t_stack **b)
{
	int	check;

	while ((*b) != NULL)
	{
		check = max_index_finder(*b);
		if ((*b)->index != check && !position_finder(*b))
		{
			while ((*b)->index != check)
				rb(b, 1);
			pa(a, b, 1);
		}
		else if ((*b)->index != check && position_finder(*b))
		{
			while ((*b)->index != check)
				rrb(b, 1);
			pa(a, b, 1);
		}
		else if ((*b)->index == check)
			pa(a, b, 1);
	}
}

void	algos_butterfly(t_stack **a, t_stack **b, t_lists *structure)
{
	algos_butterfly_start(a, b, structure);
	algos_butterfly_finish(a, b);
}

void	make_love_not_war_and_sorting(t_stack **a, t_stack **b,
	t_lists *structure)
{
	index_lists_finder(structure, a);
	if (structure->size > 5)
		algos_butterfly(a, b, structure);
	else
		less_than_six_elem(a, b, structure);
}
