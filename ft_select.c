/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:37:00 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 16:13:52 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_pos_select(t_pile *a, int i)
{
	int	n;

	n = 0;
	while (a)
	{
		if (a->rank == i)
			return (n);
		a = a->next;
		n++;
	}
	return (-1);
}

void	ft_select(t_pile **a, t_pile **b)
{
	int	i;
	int	n;
	int	z;

	i = 0;
	n = ft_pilelen(*a);
	while (i < n - 1)
	{
		z = ft_pos_select(*a, i);
		while ((*a)->rank != i)
		{
			if (z < ft_pilelen(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
	while (*b)
		pa(b, a);
}
