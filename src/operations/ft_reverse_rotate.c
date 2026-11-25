/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_reverse_rotate.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 16:06:13 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:54:13 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Performs a reverse rotation on a stack.
*
* Moves the last node of the stack to the top.
* If the stack contains fewer than two nodes,
* no action is performed.
*
* @param a Stack to rotate.
*/

void	ft_reverse_rotate(t_pile **a)
{
	t_pile	*rotate;
	t_pile	*tmp;

	if (!*a || !(*a)->next)
		return ;
	rotate = *a;
	while (rotate->next->next != NULL)
		rotate = rotate->next;
	tmp = rotate->next;
	rotate->next = NULL;
	tmp->next = *a;
	*a = tmp;
}
/**
* @brief Executes the "rra" operation.
*
* Reverse rotates stack A, prints the operation
* name and updates operation statistics.
*
* @param a Stack A.
*/

void	rra(t_pile **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
	ft_count(C_RRA, 1);
}
/**
* @brief Executes the "rra" operation.
*
* Reverse rotates stack A, prints the operation
* name and updates operation statistics.
*
* @param a Stack A.
*/

void	rrb(t_pile **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
	ft_count(C_RRB, 1);
}
/**
* @brief Executes the "rra" operation.
*
* Reverse rotates stack A, prints the operation
* name and updates operation statistics.
*
* @param a Stack A.
*/

void	rrr(t_pile **a, t_pile **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
	ft_count(C_RRR, 1);
}
