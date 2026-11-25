/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_sort.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 13:06:32 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:00:06 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Sorts a stack using an adaptive strategy.
*
* Selects the most appropriate sorting algorithm
* according to the stack size and disorder rate:
* - sa() for a stack of two elements
* - ft_select() for small or nearly sorted stacks
* - ft_chunk() for moderately disordered stacks
* - ft_turk() for highly disordered stacks
*
* If the stack is already sorted, no action is taken.
*
* @param a Stack A.
* @param b Stack B.
*/

void	ft_sort(t_pile **a, t_pile **b)
{
	int	size;
	int	d;

	size = ft_pilelen(*a);
	d = ft_disorder(*a, size);
	if (d == 0)
		return ;
	if (size == 2)
		sa(a);
	else if (size <= 5 || d < DISORDER_LOW)
		ft_select(a, b);
	else if (d < DISORDER_HIGH)
		ft_chunk(a, b);
	else
		ft_turk(a, b);
}
