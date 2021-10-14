/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:17 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 19:38:52 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack **first_a, t_stack **first_b, int print)
{
	t_stack	*temp;

	if (!first_a || !(*first_a))
		return ;
	temp = (*first_a);
	(*first_a) = (*first_a)->next;
	temp->next = (*first_b);
	(*first_b) = temp;
	if (print)
		write(1, "pb\n", 3);
}

void	pa(t_stack **first_a, t_stack **first_b, int print)
{
	t_stack	*temp;

	if (!first_b || !(*first_b))
		return ;
	temp = (*first_b);
	(*first_b) = (*first_b)->next;
	temp->next = (*first_a);
	(*first_a) = temp;
	if (print)
		write(1, "pa\n", 3);
}

void	sa(t_stack **first, int print)
{
	t_stack	*temp;

	if (!first || !(*first))
		return ;
	if (!((*first)->next))
		return ;
	temp = *first;
	*first = (*first)->next;
	temp->next = (*first)->next;
	(*first)->next = temp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **first, int print)
{
	t_stack	*temp;

	if (!first || !(*first))
		return ;
	if (!((*first)->next))
		return ;
	temp = *first;
	*first = (*first)->next;
	temp->next = (*first)->next;
	(*first)->next = temp;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
