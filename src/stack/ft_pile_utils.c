/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_pile_utils.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 13:19:04 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:04:25 by rkraan          ###   ########.fr        */
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

t_pile	*ft_pilenew(int value)
{
	t_pile	*start;

	start = malloc(sizeof(t_pile));
	if (!start)
		return (NULL);
	start->value = value;
	start->rank = 0;
	start->next = NULL;
	return (start);
}
/**
* @brief Appends a node to the end of a stack.
*
* Adds the specified node at the back of the linked
* list representing the stack.
*
* @param a Stack receiving the node.
* @param new Node to append.
*/

void	ft_pileadd_back(t_pile **a, t_pile *new)
{
	t_pile	*ptr;

	if (!a || !new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	ptr = *a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}
/**
* @brief Frees an entire stack.
*
* Releases all nodes in the stack and leaves the
* stack pointer set to NULL.
*
* @param p Stack to free.
*/

void	ft_pileclear(t_pile **p)
{
	t_pile	*next;

	while (p && *p)
	{
		next = (*p)->next;
		free(*p);
		*p = next;
	}
}
/**
* @brief Checks a stack for duplicate values.
*
* Compares each node against all following nodes
* and detects whether the same value appears more
* than once in the stack.
*
* @param a Stack to inspect.
*
* @return 1 if a duplicate is found, 0 otherwise.
*/

int	ft_has_dup(t_pile *a)
{
	t_pile	*cur;

	while (a)
	{
		cur = a->next;
		while (cur)
		{
			if (cur->value == a->value)
				return (1);
			cur = cur->next;
		}
		a = a->next;
	}
	return (0);
}
