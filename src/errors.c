/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuserwyn <fuserwyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:08:08 by fuserwyn          #+#    #+#             */
/*   Updated: 2021/10/11 19:13:04 by fuserwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_args(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_max(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_dup(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_args(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
