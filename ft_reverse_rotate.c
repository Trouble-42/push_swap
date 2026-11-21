/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:06:13 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 18:04:24 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	rra(t_pile **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
	ft_count(C_RRA, 1);
}

void	rrb(t_pile **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
	ft_count(C_RRB, 1);
}

void	rrr(t_pile **a, t_pile **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
	ft_count(C_RRR, 1);
}
