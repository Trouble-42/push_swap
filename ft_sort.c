/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_sort.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 13:06:32 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 13:13:33 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort(t_pile **a, t_pile **b)
{
	int	size;
	int	d;

	size = ft_pilelen(*a);
	d = ft_disorder(*a, size);
	if (d == 0)
		return ;
	if (size == 2)
		sa(a);
	else if (size <= 5 || d < DISORDER_LOW)
		ft_select(a, b);
	else if (d < DISORDER_HIGH)
		ft_chunk(a, b);
	else
		ft_turk(a, b);
}
