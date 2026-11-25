/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk_move.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:42:08 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:11:29 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Performs shared rotations on both stacks.
*
* Executes simultaneous rotations while the required
* movements for both stacks are in the same direction.
* This reduces the total operation count by using
* rr() or rrr().
*
* @param a Stack A.
* @param b Stack B.
* @param ma Remaining movement for stack A.
* @param mb Remaining movement for stack B.
*/

void	rot_both(t_pile **a, t_pile **b, int *ma, int *mb)
{
	while (*ma > 0 && *mb > 0)
	{
		rr(a, b);
		(*ma)--;
		(*mb)--;
	}
	while (*ma < 0 && *mb < 0)
	{
		rrr(a, b);
		(*ma)++;
		(*mb)++;
	}
}
/**
* @brief Applies the remaining rotations to stack A.
*
* Positive values perform rotations, while negative
* values perform reverse rotations.
*
* @param a Stack A.
* @param m Signed movement count.
*/

void	ft_rot_a(t_pile **a, int m)
{
	while (m > 0)
	{
		ra(a);
		m--;
	}
	while (m < 0)
	{
		rra(a);
		m++;
	}
}
/**
* @brief Applies the remaining rotations to stack B.
*
* Positive values perform rotations, while negative
* values perform reverse rotations.
*
* @param b Stack B.
* @param m Signed movement count.
*/

void	ft_rot_b(t_pile **b, int m)
{
	while (m > 0)
	{
		rb(b);
		m--;
	}
	while (m < 0)
	{
		rrb(b);
		m++;
	}
}
/**
* @brief Aligns both stacks for an insertion.
*
* Computes the required rotations for the selected
* positions in stacks A and B, performs any possible
* shared rotations, then completes the remaining
* individual rotations.
*
* @param a Stack A.
* @param b Stack B.
* @param i Target position in stack A.
* @param j Target position in stack B.
*/

void	ft_align(t_pile **a, t_pile **b, int i, int j)
{
	int	ma;
	int	mb;

	ma = ft_signed(i, ft_pilelen(*a));
	mb = ft_signed(j, ft_pilelen(*b));
	rot_both(a, b, &ma, &mb);
	ft_rot_a(a, ma);
	ft_rot_b(b, mb);
}
