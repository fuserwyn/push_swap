/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sortings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:29 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 18:51:48 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_elements(t_stack **a)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 2)
	{
		if ((*a)->val > (*a)->next->val)
			ra(a, 1);
	}
}

void	three_elements(t_stack **a)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 3)
	{
		if ((*a)->val > (*a)->next->val
			&& (*a)->val > (*a)->next->next->val)
		{
			ra(a, 1);
			if ((*a)->val > (*a)->next->val)
				sa(a, 1);
		}
		else if ((*a)->val > (*a)->next->val
			&& (*a)->val < (*a)->next->next->val)
			sa(a, 1);
		else if ((*a)->val < (*a)->next->val
			&& (*a)->next->val > (*a)->next->next->val)
		{
			rra(a, 1);
			if ((*a)->val > (*a)->next->val)
				sa(a, 1);
		}
	}
}

void	four_elements(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 4)
	{
		pb(a, b, 1);
		if ((*a)->val > (*a)->next->val)
			sa(a, 1);
		pb(a, b, 1);
		if ((*b)->val < (*b)->next->val)
			rb(b, 1);
		two_elements(a);
		if ((*b)->val > (*a)->next->val)
			pa(a, b, 1);
		if (find_max(*a) == (*a)->val)
			ra(a, 1);
		if ((*a)->val > (*a)->next->val)
			sa(a, 1);
		pa(a, b, 1);
		if ((*a)->val > (*a)->next->val)
			sa(a, 1);
		pb(b, a, 1);
		if ((*a)->val > (*a)->next->val)
			sa(a, 1);
	}
}

void	five_elements(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		while (find_elem(0, *a) == 5 || find_elem(1, *a) == 5)
			rra(a, 1);
		while ((*a)->index > 1)
			ra(a, 1);
		pb(a, b, 1);
	}
	if ((*b)->val < (*b)->next->val)
		sb(b, 1);
	three_elements(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	less_than_six_elem(t_stack **a, t_stack **b, t_lists *structure)
{
	if (structure->size == 2)
		two_elements(a);
	if (structure->size == 3)
		three_elements(a);
	if (structure->size == 4)
		four_elements(a, b);
	if (structure->size == 5)
		five_elements(a, b);
}
