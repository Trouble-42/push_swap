/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 14:19:02 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 11:32:01 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_chunk_size(int size)
{
	return (size * 3 / 100 + 14);
}

void	push_to_b(t_pile **a, t_pile **b)
{
	int	chunk;
	int	pushed;

	pushed = 0;
	chunk = get_chunk_size(ft_pilelen(*a));
	while (*a)
	{
		move_chunk_top(a, find_chunk_pos(*a, pushed + chunk));
		pb(a, b);
		if ((*b)->rank <= pushed)
			rb(b);
		pushed++;
	}
}

void	push_to_a(t_pile **a, t_pile **b)
{
	while (*b)
	{
		move_max_top(b);
		pa(a, b);
	}
}

void	ft_chunk(t_pile **a, t_pile **b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}
