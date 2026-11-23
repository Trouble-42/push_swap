/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk_move.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:42:08 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 12:48:55 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rot_both(t_pile **a, t_pile **b, int *ma, int *mb)
{
	while (*ma > 0 && *mb > 0)
	{
		rr(a, b);
		(*ma)--;
		(*mb)--;
	}
	while (*ma < 0 && *mb < 0)
	{
		rrr(a, b);
		(*ma)++;
		(*mb)++;
	}
}

void	ft_rot_a(t_pile **a, int m)
{
	while (m > 0)
	{
		ra(a);
		m--;
	}
	while (m < 0)
	{
		rra(a);
		m++;
	}
}

void	ft_rot_b(t_pile **b, int m)
{
	while (m > 0)
	{
		rb(b);
		m--;
	}
	while (m < 0)
	{
		rrb(b);
		m++;
	}
}

void	ft_align(t_pile **a, t_pile **b, int i, int j)
{
	int	ma;
	int	mb;

	ma = ft_signed(i, ft_pilelen(*a));
	mb = ft_signed(j, ft_pilelen(*b));
	rot_both(a, b, &ma, &mb);
	ft_rot_a(a, ma);
	ft_rot_b(b, mb);
}
