/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 12:51:05 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 11:47:18 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	pa(t_pile **a, t_pile **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
	ft_count(C_PA, 1);
}

void	pb(t_pile **a, t_pile **b)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
	ft_count(C_PB, 1);
}
