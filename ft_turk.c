/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:38:22 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 12:38:45 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_three(t_pile **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->rank;
	y = (*a)->next->rank;
	z = (*a)->next->next->rank;
	if (x > y && x > z)
		ra(a);
	else if (y > x && y > z)
		rra(a);
	if ((*a)->rank > (*a)->next->rank)
		sa(a);
}

void	push_cheapest(t_pile **a, t_pile **b)
{
	int	rank;

	rank = ft_cheapest_a(*a, *b);
	ft_align(a, b, ft_pos(*a, rank), ft_pos(*b, ft_target_b(*b, rank)));
	pb(a, b);
}

void	push_back(t_pile **a, t_pile **b)
{
	int	target;

	target = ft_target_a(*a, (*b)->rank);
	ft_rot_a(a, ft_signed(ft_pos(*a, target), ft_pilelen(*a)));
	pa(a, b);
}

void	ft_turk(t_pile **a, t_pile **b)
{
	pb(a, b);
	if (ft_pilelen(*a) > 3)
		pb(a, b);
	while (ft_pilelen(*a) > 3)
		push_cheapest(a, b);
	ft_sort_three(a);
	ft_rot_b(b, ft_signed(ft_pos(*b, ft_max_rank(*b)), ft_pilelen(*b)));
	while (*b)
		push_back(a, b);
	ft_rot_a(a, ft_signed(ft_pos(*a, ft_min_rank(*a)), ft_pilelen(*a)));
}
