/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_chunk.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 14:19:02 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/21 15:19:57 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	find_chunk_pos(t_pile *a, int limit)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index <= limit)
			return (pos);
		pos++;
		a = a->next;
	}
	return (0);
}

static void	move_chunk_top(t_pile **a, int pos)
{
	int	size;

	size = stack_size(*a);
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

static void	push_to_b(t_pile **a, t_pile **b)
{
	int	chunk;
	int	pushed;
	int	pos;

	pushed = 0;
	chunk = ft_pilelen(*a) / 10;
	//size to define by testing
	while (*a)
	{
		pos = find_chunk_pos(*a, pushed + chunk);
		move_chunk_top(a, pos);
		if ((*a)->index <= pushed)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
		pushed++;
	}
}

static int	find_max_pos(t_pile *b)
{
	int	max;
	int	max_pos;
	int	pos;

	max = b->index;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

static void	move_max_top(t_pile **b)
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

static void	push_to_a(t_pile **a, t_pile **b)
{
	while (*b)
	{
		move_max_top(b);
		pa(a, b);
	}
}
