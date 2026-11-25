/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk_cost.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:39:31 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:16:25 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Returns the absolute value of an integer.
*
* @param n Value to process.
*
* @return Absolute value of n.
*/

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
/**
* @brief Converts a position into a signed rotation count.
*
* Positions in the first half of the stack are expressed
* as positive rotations, while positions in the second
* half are expressed as negative reverse rotations.
*
* @param pos Position in the stack.
* @param size Stack size.
*
* @return Signed rotation count.
*/

int	ft_signed(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}
/**
* @brief Computes the combined cost of two rotations.
*
* When both rotations are performed in the same
* direction, shared rotations can be used and the
* cost is the larger absolute value. Otherwise the
* costs are added together.
*
* @param ma Signed movement for stack A.
* @param mb Signed movement for stack B.
*
* @return Total movement cost.
*/

int	ft_pair_cost(int ma, int mb)
{
	if ((ma >= 0) == (mb >= 0))
	{
		if (ft_abs(ma) > ft_abs(mb))
			return (ft_abs(ma));
		return (ft_abs(mb));
	}
	return (ft_abs(ma) + ft_abs(mb));
}
/**
* @brief Computes the insertion cost of a node.
*
* Evaluates the number of operations required to move
* a node from stack A to its correct position in stack B.
*
* @param a Stack A.
* @param b Stack B.
* @param i Position of the node in stack A.
* @param rank Rank of the node being evaluated.
*
* @return Estimated movement cost.
*/

int	node_cost(t_pile *a, t_pile *b, int i, int rank)
{
	int	j;

	j = ft_pos(b, ft_target_b(b, rank));
	return (ft_pair_cost(ft_signed(i, ft_pilelen(a)), ft_signed(j, ft_pilelen(b))));
}
/**
* @brief Finds the cheapest node to move from stack A.
*
* Evaluates every node in stack A and selects the one
* requiring the fewest operations to be inserted into
* stack B.
*
* @param a Stack A.
* @param b Stack B.
*
* @return Rank of the cheapest node to move.
*/

int	ft_cheapest_a(t_pile *a, t_pile *b)
{
	t_pile	*cur;
	int		i;
	int		best;
	int		min;
	int		cost;

	cur = a;
	i = 0;
	best = 0;
	min = -1;
	while (cur)
	{
		cost = node_cost(a, b, i, cur->rank);
		if (min < 0 || cost < min)
		{
			min = cost;
			best = cur->rank;
		}
		cur = cur->next;
		i++;
	}
	return (best);
}
