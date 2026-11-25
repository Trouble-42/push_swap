/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_select.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 13:37:00 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:58:50 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Finds the position of a given rank in a stack.
*
* Searches the stack from top to bottom and returns
* the position of the first node whose rank matches
* the specified value.
*
* @param a Stack to search.
* @param i Rank to locate.
*
* @return Position of the rank, or -1 if not found.
*/

int	ft_pos_select(t_pile *a, int i)
{
	int	n;

	n = 0;
	while (a)
	{
		if (a->rank == i)
			return (n);
		a = a->next;
		n++;
	}
	return (-1);
}
/**
* @brief Sorts a stack using selection sort.
*
* Repeatedly moves the smallest remaining rank to the
* top of stack A, pushes it to stack B, and continues
* until only the largest element remains. The sorted
* elements are then pushed back to stack A.
*
* This algorithm is intended for small stacks due to
* its quadratic time complexity.
*
* @param a Stack A.
* @param b Stack B.
*/

void	ft_select(t_pile **a, t_pile **b)
{
	int	i;
	int	n;
	int	z;

	i = 0;
	n = ft_pilelen(*a);
	while (i < n - 1)
	{
		z = ft_pos_select(*a, i);
		while ((*a)->rank != i)
		{
			if (z < ft_pilelen(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}
