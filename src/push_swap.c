/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:25 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 19:40:03 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_lists	*structure;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	args_checker(argc, argv);
	structure = init_structure(argc);
	stack_a_fillment(&a, structure, argc, argv);
	structure->array = sort_array(structure);
	if (is_sorted(structure, a))
		make_love_not_war_and_sorting(&a, &b, structure);
	leaks_cleaner(&a, &b, structure);
	return (0);
}
