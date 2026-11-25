/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_swap.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 11:27:13 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:57:01 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Swaps the first two elements of a stack.
*
* Exchanges the value and rank of the top two nodes.
* No action is performed if the stack contains fewer
* than two nodes.
*
* @param a Stack to modify.
*/

void	ft_swap(t_pile **a)
{
	int	tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->rank;
	(*a)->rank = (*a)->next->rank;
	(*a)->next->rank = tmp;
}
/**
* @brief Executes the "sa" operation.
*
* Swaps the first two elements of stack A,
* prints the operation name and increments
* the operation counter.
*
* @param a Stack A.
*/

void	sa(t_pile **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
	ft_count(C_SA, 1);
}
/**
* @brief Executes the "sb" operation.
*
* Swaps the first two elements of stack B,
* prints the operation name and increments
* the operation counter.
*
* @param b Stack B.
*/

void	sb(t_pile **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
	ft_count(C_SB, 1);
}
/**
* @brief Executes the "ss" operation.
*
* Swaps the first two elements of both stacks
* simultaneously, prints the operation name
* and increments the operation counter.
*
* @param a Stack A.
* @param b Stack B.
*/

void	ss(t_pile **a, t_pile **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
	ft_count(C_SS, 1);
}
