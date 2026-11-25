/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_adaptive.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 09:35:42 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:42:59 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Selects and executes a sorting algorithm automatically.
*
* Evaluates the disorder rate of stack A and chooses
* the most suitable sorting strategy:
* - ft_select() for nearly sorted stacks
* - ft_chunk() for moderately disordered stacks
* - ft_turk() for highly disordered stacks
*
* @param a Stack A.
* @param b Stack B.
*
* @return Identifier of the strategy used:
*         - 1 for Select
*         - 2 for Chunk
*         - 3 for Turk
*         - 0 if no strategy was selected
*/

int	ft_adaptative(t_pile **a, t_pile **b)
{
	long	order_rate;
	int		start;

	start = 0;
	order_rate = ft_disorder(*a, ft_pilelen(*a));
	if (order_rate > 0 && order_rate < 2000)
	{
		ft_select(a, b);
		start = 1;
	}
	else if (order_rate >= 2000 && order_rate < 5000)
	{
		ft_chunk(a, b);
		start = 2;
	}
	else if (order_rate >= 5000 && order_rate <= 10000)
	{
		ft_turk(a, b);
		start = 3;
	}
	return (start);
}
