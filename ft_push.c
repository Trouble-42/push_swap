/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 12:51:05 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/20 15:22:00 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push(t_pile **a, t_pile **b)
{
	t_pile *tmp;
	if (!*b || !b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pa(t_pile **b, t_pile **a)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_pile **a, t_pile **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
