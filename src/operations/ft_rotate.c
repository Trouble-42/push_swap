/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_rotate.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 15:13:27 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:55:56 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Performs a rotation on a stack.
*
* Moves the first node of the stack to the bottom.
* No action is performed if the stack contains
* fewer than two nodes.
*
* @param a Stack to rotate.
*/

void	ft_rotate(t_pile **a)
{
	t_pile	*rotate;
	t_pile	*tmp;

	if (!*a || !(*a)->next)
		return ;
	rotate = *a;
	tmp = (*a)->next;
	while (rotate->next != NULL)
		rotate = rotate->next;
	rotate->next = *a;
	(*a)->next = NULL;
	*a = tmp;
}
/**
* @brief Executes the "ra" operation.
*
* Rotates stack A upward, prints the operation
* name and increments the operation counter.
*
* @param a Stack A.
*/

void	ra(t_pile **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
	ft_count(C_RA, 1);
}
/**
* @brief Executes the "rb" operation.
*
* Rotates stack B upward, prints the operation
* name and increments the operation counter.
*
* @param b Stack B.
*/

void	rb(t_pile **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
	ft_count(C_RB, 1);
}

/**
* @brief Executes the "rr" operation.
*
* Rotates both stacks upward simultaneously,
* prints the operation name and increments
* the operation counter.
*
* @param a Stack A.
* @param b Stack B.
*/

void	rr(t_pile **a, t_pile **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
	ft_count(C_RR, 1);
}
