/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_turk_cost.c                                     :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 12:39:31 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/24 17:13:43 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_signed(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	ft_pair_cost(int ma, int mb)
{
	if ((ma >= 0) == (mb >= 0))
	{
		if (ft_abs(ma) > ft_abs(mb))
			return (ft_abs(ma));
		return (ft_abs(mb));
	}
	return (ft_abs(ma) + ft_abs(mb));
}

int	node_cost(t_pile *a, t_pile *b, int i, int rank)
{
	int	j;

	j = ft_pos(b, ft_target_b(b, rank));
	return (ft_pair_cost(ft_signed(i, ft_pilelen(a)),
			ft_signed(j, ft_pilelen(b))));
}

int	ft_cheapest_a(t_pile *a, t_pile *b)
{
	t_pile	*cur;
	int		i;
	int		best;
	int		min;
	int		cost;

	cur = a;
	i = 0;
	best = 0;
	min = -1;
	while (cur)
	{
		cost = node_cost(a, b, i, cur->rank);
		if (min < 0 || cost < min)
		{
			min = cost;
			best = cur->rank;
		}
		cur = cur->next;
		i++;
	}
	return (best);
}
