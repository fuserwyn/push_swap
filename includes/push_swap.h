/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:43:46 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/14 19:43:48 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				index;
	int				flag;
	struct s_stack	*next;
}					t_stack;

typedef struct s_lists
{
	int				val;
	int				index;
	int				*array;
	int				size;
	struct s_lists	*next;
}				t_lists;

void		pa(t_stack **first_a, t_stack **first_b, int print);
void		pb(t_stack **first_a, t_stack **first_b, int print);
void		sa(t_stack **first, int print);
void		sb(t_stack **first, int print);
void		ss(t_stack **a, t_stack **b, int print);
void		ra(t_stack **first, int print);
void		rb(t_stack **first, int print);
void		rra(t_stack **first, int print);
void		rrb(t_stack **first, int print);
void		rr(t_stack **a, t_stack **b, int print);
void		rrr(t_stack **a, t_stack **b, int print);
t_stack		*ft_listback(t_stack **lst, t_stack *new);
t_stack		*ft_lstinit(int content);
t_stack		*ft_listlast(t_stack *lst);
int			main(int argc, char **argv);
void		error(void);
int			*sort_array(t_lists *structure);
t_lists		*init_structure(int argc);
void		ft_lstadd_first(t_stack **a, int number, int index);
int			find_max(t_stack *a);
void		use_args(void);
void		args_checker(int argc, char **argv);
int			ft_len(const char *str);
int			position_finder(t_stack *curr);
int			max_index_finder(t_stack *curr);
void		algos_butterfly_start(t_stack **a, t_stack **b, t_lists *structure);
void		algos_butterfly_finish(t_stack **a, t_stack **b);
int			ft_lstsize(t_stack *lst);
void		index_lists_finder(t_lists *structure, t_stack **a);
int			is_sorted(t_lists *structure, t_stack *a);
int			doubles_checker(int argc, t_lists *structure, int j);
void		error_max(void);
void		error_dup(void);
void		algos_butterfly(t_stack **a, t_stack **b, t_lists *structure);
void		two_elements(t_stack **a);
void		three_elements(t_stack **a);
void		error_args(void);
void		four_elements(t_stack **a, t_stack **b);
void		five_elements(t_stack **a, t_stack **b);
void		less_than_six_elem(t_stack **a, t_stack **b, t_lists *structure);

void		make_love_not_war_and_sorting(t_stack **a, t_stack **b,
				t_lists *structure);
void		error_sorting(void);

void		stack_a_fillment(t_stack **a, t_lists *structure,
				int argc, char **argv);
int			find_elem(int index, t_stack *a);
int			numbers_for_algos(t_lists *structure);
void		ft_listclear(t_stack **lst);
void		leaks_cleaner(t_stack **a, t_stack **b, t_lists *structure);
void		exec_com(char *com, t_stack **a, t_stack **b, t_lists *structure);
void		gnl(t_stack **a, t_stack **b, t_lists *structure);
int			get_next_line(char **line);

void		leaks_cleaner1(t_stack **a, t_stack **b,
				t_lists *structure, int error);

void		whether_sorted(t_lists *structure, t_stack **a, t_stack **b);

void		commands_clean(char *com, t_stack **a,
				t_stack **b, t_lists *structure);

#endif