/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_chunk.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 14:19:02 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:49:09 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Computes the chunk size for the chunk algorithm.
*
* Calculates the number of ranks that should be processed
* together during each phase of the chunk sort.
*
* @param size Number of elements in the stack.
*
* @return Computed chunk size.
*/

int	get_chunk_size(int size)
{
	return (size * 3 / 100 + 14);
}
/**
* @brief Pushes all elements from stack A to stack B.
*
* Processes stack A in chunks. Elements belonging
* to the current chunk are moved to stack B while
* preserving a favorable ordering for reconstruction.
*
* @param a Stack A.
* @param b Stack B.
*/

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
/**
* @brief Restores all elements from stack B to stack A.
*
* Repeatedly moves the largest available rank to the
* top of stack B and pushes it back to stack A until
* stack B becomes empty.
*
* @param a Stack A.
* @param b Stack B.
*/

void	push_to_a(t_pile **a, t_pile **b)
{
	while (*b)
	{
		move_max_top(b);
		pa(a, b);
	}
}
/**
* @brief Sorts a stack using the chunk algorithm.
*
* Splits the stack into rank-based chunks, pushes
* the chunks to stack B, then rebuilds stack A in
* sorted order.
*
* @param a Stack A.
* @param b Stack B.
*/

void	ft_chunk(t_pile **a, t_pile **b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}
