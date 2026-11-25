/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_rank.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 09:07:00 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:37:31 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Assigns ranks to all nodes in a stack.
*
* Computes the rank of each value by counting how many
* values in the stack are strictly smaller. The smallest
* value receives rank 0, the second smallest rank 1,
* and so on.
*
* @param a Stack whose nodes will be ranked.
*/

void	ft_rank(t_pile *a)
{
	t_pile	*ptr;
	t_pile	*tmp;

	ptr = a;
	while (ptr)
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->value < ptr->value)
				ptr->rank += 1;
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
