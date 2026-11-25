/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_push.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 12:51:05 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:39:34 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Pushes the top node from one stack to another.
*
* Removes the first node from stack B and places it
* at the top of stack A. If stack B is empty, nothing
* is done.
*
* @param a Destination stack.
* @param b Source stack.
*/

void	ft_push(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}
/**
* @brief Executes the "pa" operation.
*
* Pushes the top element of stack B onto stack A,
* prints the operation name and updates operation
* statistics.
*
* @param a Stack A.
* @param b Stack B.
*/

void	pa(t_pile **a, t_pile **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
	ft_count(C_PA, 1);
}
/**
* @brief Executes the "pb" operation.
*
* Pushes the top element of stack A onto stack B,
* prints the operation name and updates operation
* statistics.
*
* @param a Stack A.
* @param b Stack B.
*/

void	pb(t_pile **a, t_pile **b)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
	ft_count(C_PB, 1);
}
