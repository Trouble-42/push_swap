/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_pilelen.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 19:54:34 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:04:49 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Creates a new stack node.
*
* Allocates and initializes a new node with the
* specified value. The rank is initialized to 0
* and the next pointer to NULL.
*
* @param value Value stored in the node.
*
* @return Pointer to the new node, or NULL on failure.
*/

int	ft_pilelen(t_pile *a)
{
	int	i;

	i = 1;
	if (!a)
		return (0);
	while (a->next != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}
