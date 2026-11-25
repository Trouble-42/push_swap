/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_is_sorted.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 17:40:43 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:10:57 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief Checks whether a stack is sorted in ascending order.
*
* Traverses the stack from top to bottom and compares each node
* with its successor. If a value is greater than the next value,
* the stack is considered unsorted.
*
* @param a Pointer to the first node of the stack.
* @return 1 if the stack is sorted, 0 otherwise.
*/
#include "ft_push_swap.h"

int	ft_is_sorted(t_pile *a)
{
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
