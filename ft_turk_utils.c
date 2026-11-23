/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk_utils.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:42:34 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 12:42:34 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_pos(t_pile *p, int rank)
{
	int	i;

	i = 0;
	while (p)
	{
		if (p->rank == rank)
			return (i);
		p = p->next;
		i++;
	}
	return (0);
}

int	ft_min_rank(t_pile *p)
{
	int	min;

	min = p->rank;
	while (p)
	{
		if (p->rank < min)
			min = p->rank;
		p = p->next;
	}
	return (min);
}

int	ft_max_rank(t_pile *p)
{
	int	max;

	max = p->rank;
	while (p)
	{
		if (p->rank > max)
			max = p->rank;
		p = p->next;
	}
	return (max);
}

int	ft_target_a(t_pile *a, int rank)
{
	t_pile	*cur;
	int		target;

	cur = a;
	target = -1;
	while (cur)
	{
		if (cur->rank > rank && (target < 0 || cur->rank < target))
			target = cur->rank;
		cur = cur->next;
	}
	if (target < 0)
		return (ft_min_rank(a));
	return (target);
}

int	ft_target_b(t_pile *b, int rank)
{
	t_pile	*cur;
	int		target;

	cur = b;
	target = -1;
	while (cur)
	{
		if (cur->rank < rank && cur->rank > target)
			target = cur->rank;
		cur = cur->next;
	}
	if (target < 0)
		return (ft_max_rank(b));
	return (target);
}
