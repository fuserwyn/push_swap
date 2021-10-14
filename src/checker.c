/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:43:21 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 19:43:24 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	exec_cmd(char *com, t_stack **a, t_stack **b, t_lists *structure)
{
	if (!ft_strcmp("sa\n", com))
		sa(a, 0);
	else if (!ft_strcmp("sb\n", com))
		sb(b, 0);
	else if (!ft_strcmp("ss\n", com))
		ss(a, b, 0);
	else if (!ft_strcmp("ra\n", com))
		ra(a, 0);
	else if (!ft_strcmp("rb\n", com))
		rb(b, 0);
	else if (!ft_strcmp("rr\n", com))
		rr(a, b, 0);
	else if (!ft_strcmp("rra\n", com))
		rra(a, 0);
	else if (!ft_strcmp("rrb\n", com))
		rrb(b, 0);
	else if (!ft_strcmp("rrr\n", com))
		rrr(a, b, 0);
	else if (!ft_strcmp("pa\n", com))
		pa(a, b, 0);
	else if (!ft_strcmp("pb\n", com))
		pb(a, b, 0);
	else
		commands_clean(com, a, b, structure);
}

void	leaks_cleaner1(t_stack **a, t_stack **b, t_lists *structure, int error)
{
	ft_listclear(a);
	ft_listclear(b);
	if (structure)
	{
		if (structure->array)
			free(structure->array);
		free(structure);
	}
	if (error)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

int	get_next_line(char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buffer;

	rd = 1;
	i = 0;
	buffer = malloc(256);
	*line = buffer;
	while (rd > 0 && ch != '\n')
	{
		rd = read(0, &ch, 1);
		buffer[i++] = ch;
	}
	buffer[i] = '\0';
	return (rd);
}

void	gnl(t_stack **a, t_stack **b, t_lists *structure)
{
	char	*buf;

	buf = NULL;
	while (get_next_line(&buf) > 0)
	{
		if (*buf)
			exec_cmd(buf, a, b, structure);
		free(buf);
		buf = NULL;
	}
	if (buf)
		free(buf);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_lists	*structure;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	args_checker(argc, argv);
	structure = init_structure(argc);
	stack_a_fillment(&a, structure, argc, argv);
	structure->array = sort_array(structure);
	gnl(&a, &b, structure);
	whether_sorted(structure, &a, &b);
	return (0);
}
