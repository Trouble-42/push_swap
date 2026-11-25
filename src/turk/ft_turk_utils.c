/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk_utils.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:42:34 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:13:05 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Finds the position of a rank in a stack.
*
* Searches the stack from top to bottom until the
* specified rank is found.
*
* @param p Stack to search.
* @param rank Rank to locate.
*
* @return Position of the rank in the stack.
*/

int	ft_pos(t_pile *p, int rank)
{
	int	i;

	i = 0;
	while (p)
	{
		if (p->rank == rank)
			return (i);
		p = p->next;
		i++;
	}
	return (0);
}
/**
* @brief Returns the smallest rank in a stack.
*
* Traverses the stack and determines the minimum
* rank value present.
*
* @param p Stack to inspect.
*
* @return Smallest rank found.
*/

int	ft_min_rank(t_pile *p)
{
	int	min;

	min = p->rank;
	while (p)
	{
		if (p->rank < min)
			min = p->rank;
		p = p->next;
	}
	return (min);
}
/**
* @brief Returns the largest rank in a stack.
*
* Traverses the stack and determines the maximum
* rank value present.
*
* @param p Stack to inspect.
*
* @return Largest rank found.
*/

int	ft_max_rank(t_pile *p)
{
	int	max;

	max = p->rank;
	while (p)
	{
		if (p->rank > max)
			max = p->rank;
		p = p->next;
	}
	return (max);
}
/**
* @brief Finds the insertion target in stack A.
*
* Returns the smallest rank greater than the given
* rank. If no such rank exists, the minimum rank of
* the stack is returned.
*
* @param a Stack A.
* @param rank Rank being inserted.
*
* @return Target rank in stack A.
*/

int	ft_target_a(t_pile *a, int rank)
{
	t_pile	*cur;
	int		target;

	cur = a;
	target = -1;
	while (cur)
	{
		if (cur->rank > rank && (target < 0 || cur->rank < target))
			target = cur->rank;
		cur = cur->next;
	}
	if (target < 0)
		return (ft_min_rank(a));
	return (target);
}
/**
* @brief Finds the insertion target in stack B.
*
* Returns the largest rank smaller than the given
* rank. If no such rank exists, the maximum rank of
* the stack is returned.
*
* @param b Stack B.
* @param rank Rank being inserted.
*
* @return Target rank in stack B.
*/

int	ft_target_b(t_pile *b, int rank)
{
	t_pile	*cur;
	int		target;

	cur = b;
	target = -1;
	while (cur)
	{
		if (cur->rank < rank && cur->rank > target)
			target = cur->rank;
		cur = cur->next;
	}
	if (target < 0)
		return (ft_max_rank(b));
	return (target);
}
