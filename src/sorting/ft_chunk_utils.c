/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_chunk_utils.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 11:25:57 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:46:15 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Finds the nearest node belonging to a chunk.
*
* Searches for nodes whose rank is less than or equal
* to the specified limit and returns the position of
* the closest one relative to either end of the stack.
*
* @param a Stack to search.
* @param limit Maximum rank accepted in the chunk.
*
* @return Position of the nearest matching node.
*/

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
/**
* @brief Moves a chunk node to the top of stack A.
*
* Rotates or reverse rotates stack A using the
* shortest path until the node at the specified
* position reaches the top of the stack.
*
* @param a Stack A.
* @param pos Position of the target node.
*/

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
/**
* @brief Finds the position of the maximum rank.
*
* Searches stack B and returns the position of
* the node containing the highest rank.
*
* @param b Stack B.
*
* @return Position of the highest-ranked node.
*/

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
/**
* @brief Moves the maximum-ranked node to the top.
*
* Rotates or reverse rotates stack B using the
* shortest path until the node with the highest
* rank reaches the top of the stack.
*
* @param b Stack B.
*/

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
