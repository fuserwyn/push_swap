/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:10:26 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/11 23:22:51 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = (*lst).next;
		i++;
	}
	return (i);
}

int	max_index_finder(t_stack *curr)
{
	int	max_index;

	max_index = 1;
	if (curr)
	{
		max_index = curr->index;
		while (curr != NULL)
		{
			if (max_index < curr->index)
				max_index = curr->index;
			curr = curr->next;
		}
	}
	return (max_index);
}

int	find_elem(int index, t_stack *a)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index == index)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	position_finder(t_stack *curr)
{
	int	len;
	int	pos;
	int	check;

	pos = 1;
	if (!curr)
		return (0);
	len = ft_lstsize(curr);
	check = max_index_finder(curr);
	while (curr->next && curr->index != check)
	{
		pos++;
		curr = curr->next;
	}
	if (pos > len / 2)
		check = 1;
	else
		check = 0;
	return (check);
}

void	index_lists_finder(t_lists *structure, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		while (tmp->val != structure->array[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
		i = 0;
	}
}
