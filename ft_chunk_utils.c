/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_chunk_utils.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 11:25:57 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 11:34:16 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_chunk_pos(t_pile *a, int limit)
{
	int	pos;
	int	first;
	int	last;

	pos = 0;
	first = -1;
	last = 0;
	while (a)
	{
		if (a->rank <= limit)
		{
			if (first < 0)
				first = pos;
			last = pos;
		}
		pos++;
		a = a->next;
	}
	if (first < 0)
		return (0);
	if (first <= pos - last)
		return (first);
	return (last);
}

void	move_chunk_top(t_pile **a, int pos)
{
	int	size;

	size = ft_pilelen(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a);
	}
}

int	find_max_pos(t_pile *b)
{
	int	max;
	int	max_pos;
	int	pos;

	max = b->rank;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (b->rank > max)
		{
			max = b->rank;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

void	move_max_top(t_pile **b)
{
	int	pos;
	int	size;

	size = ft_pilelen(*b);
	pos = find_max_pos(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b);
	}
}
