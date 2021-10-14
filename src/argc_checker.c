/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:02 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/13 19:41:45 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_lists	*init_structure(int argc)
{
	t_lists	*structure;

	structure = NULL;
	if (argc > 1)
	{
		structure = (t_lists *)malloc(sizeof(t_lists));
		structure->array = (int *)malloc(sizeof(int) * (argc - 1));
		structure->size = argc - 1;
	}
	return (structure);
}

void	leaks_cleaner(t_stack **a, t_stack **b, t_lists *structure)
{
	ft_listclear(a);
	ft_listclear(b);
	if (structure)
	{
		if (structure->array)
			free(structure->array);
		free(structure);
	}
}

int	doubles_checker(int elem, t_lists *structure, int j)
{
	int		i;

	i = 0;
	while (i < j)
	{
		if (structure->array[i] == elem)
			return (1);
		i++;
	}
	return (0);
}

void	args_checker(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 1)
		exit (0);
	i = 1;
	while (i < argc)
	{
		if (!((argv[i][0] == '-' || argv[i][0] == '+')
			|| (argv[i][0] <= 57 && argv[i][0] >= 48)))
			 error();
		if ((argv[i][0] == '-' || argv[i][0] == '+')
			&& !argv[i][1])
			 error();
		j = 1;
		while (j < ft_len(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
				error();
			j++;
		}
		i++;
	}
}
