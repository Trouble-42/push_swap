/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_radix.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 10:02:24 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:51:26 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Sorts a stack using the radix sort algorithm.
*
* Processes node ranks bit by bit, starting from the
* least significant bit. Elements with a cleared bit
* are pushed to stack B, while elements with a set bit
* remain in stack A through rotation. After each pass,
* all elements are moved back to stack A.
*
* @param a Stack A.
* @param b Stack B.
*/

void	ft_radix(t_pile **a, t_pile **b)
{
	int	n;
	int	bit;
	int	size;

	bit = 1;
	size = ft_pilelen(*a);
	while (bit <= size - 1)
	{
		n = size;
		while (n > 0)
		{
			if (((*a)->rank / bit % 2) == 0)
				pb(a, b);
			else
				ra(a);
			n--;
		}
		while (*b != NULL)
			pa(a, b);
		bit *= 2;
	}
}
