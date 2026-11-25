/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:38:22 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:15:13 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Sorts a stack containing up to three elements.
*
* Uses a minimal sequence of operations to place
* three or fewer ranked elements in ascending order.
*
* @param a Stack to sort.
*/

void	ft_sort_three(t_pile **a)
{
	int	len;
	int	x;
	int	y;
	int	z;

	len = ft_pilelen(*a);
	if (len < 2)
		return ;
	if (len == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			sa(a);
		return ;
	}
	x = (*a)->rank;
	y = (*a)->next->rank;
	z = (*a)->next->next->rank;
	if (x > y && x > z)
		ra(a);
	else if (y > x && y > z)
		rra(a);
	if ((*a)->rank > (*a)->next->rank)
		sa(a);
}
/**
* @brief Pushes the cheapest node from stack A to stack B.
*
* Selects the node with the lowest insertion cost,
* aligns both stacks to minimize operations and
* pushes the node to stack B.
*
* @param a Stack A.
* @param b Stack B.
*/

void	push_cheapest(t_pile **a, t_pile **b)
{
	int	rank;

	rank = ft_cheapest_a(*a, *b);
	ft_align(a, b, ft_pos(*a, rank), ft_pos(*b, ft_target_b(*b, rank)));
	pb(a, b);
}
/**
* @brief Reinserts the top node of stack B into stack A.
*
* Rotates stack A so that the insertion target is at
* the top, then pushes the element from stack B back
* into its sorted position.
*
* @param a Stack A.
* @param b Stack B.
*/

void	push_back(t_pile **a, t_pile **b)
{
	int	target;

	target = ft_target_a(*a, (*b)->rank);
	ft_rot_a(a, ft_signed(ft_pos(*a, target), ft_pilelen(*a)));
	pa(a, b);
}
/**
* @brief Sorts a stack using the Turk algorithm.
*
* The algorithm first moves a small number of elements
* to stack B, then repeatedly pushes the cheapest node
* from stack A to stack B using a cost-based strategy.
* Once three elements remain, they are sorted directly.
*
* Stack B is then aligned so its largest rank is on top,
* after which all elements are reinserted into stack A
* in sorted order. Finally, stack A is rotated until
* the smallest rank is at the top.
*
* @param a Stack A.
* @param b Stack B.
*/

void	ft_turk(t_pile **a, t_pile **b)
{
	if (ft_pilelen(*a) <= 3)
	{
		ft_sort_three(a);
		return ;
	}
	pb(a, b);
	if (ft_pilelen(*a) > 3)
		pb(a, b);
	while (ft_pilelen(*a) > 3)
		push_cheapest(a, b);
	ft_sort_three(a);
	ft_rot_b(b, ft_signed(ft_pos(*b, ft_max_rank(*b)), ft_pilelen(*b)));
	while (*b)
		push_back(a, b);
	ft_rot_a(a, ft_signed(ft_pos(*a, ft_min_rank(*a)), ft_pilelen(*a)));
}
