/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:21 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 18:55:06 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **first, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!first || !(*first))
		return ;
	if (!((*first)->next))
		return ;
	temp = *first;
	last = *first;
	while (last->next)
		last = last->next;
	last->next = temp;
	*first = temp->next;
	temp->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rra(t_stack **first, int print)
{
	t_stack	*tmp;
	t_stack	*prelast;

	if (!first || !(*first))
		return ;
	if (!((*first)->next))
		return ;
	tmp = *first;
	prelast = *first;
	while (prelast->next->next)
		prelast = prelast->next;
	*first = prelast->next;
	prelast->next->next = tmp;
	prelast->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

void	rb(t_stack **first, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!first || !(*first))
		return ;
	if (!((*first)->next))
		return ;
	temp = *first;
	last = *first;
	while (last->next)
		last = last->next;
	last->next = temp;
	*first = temp->next;
	temp->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rrb(t_stack **first, int print)
{
	t_stack	*tmp;
	t_stack	*prelast;

	if (!first || !(*first))
		return ;
	if (!((*first)->next))
		return ;
	tmp = *first;
	prelast = *first;
	while (prelast->next->next)
		prelast = prelast->next;
	*first = prelast->next;
	prelast->next->next = tmp;
	prelast->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
