/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:43:12 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 19:43:15 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	commands_clean(char *com, t_stack **a, t_stack **b, t_lists *structure)
{
	free(com);
	leaks_cleaner1(a, b, structure, 1);
}

void	whether_sorted(t_lists *structure, t_stack **a, t_stack **b)
{
	if (is_sorted(structure, *a))
	{
		write(2, "KO\n", 3);
		leaks_cleaner1(a, b, structure, 0);
	}
	else
	{
		write(2, "OK\n", 3);
		leaks_cleaner1(a, b, structure, 0);
	}
}
