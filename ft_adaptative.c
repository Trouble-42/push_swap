/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 09:35:42 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/25 11:24:06 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_adaptative(t_pile **a, t_pile **b)
{
	long	order_rate;
	int		start;

	start = 0;
	order_rate = ft_disorder(*a, ft_pilelen(*a));
	if (order_rate > 0 && order_rate < 2000)
	{
		ft_select(a, b);
		start = 1;
	}
	else if (order_rate >= 2000 && order_rate < 5000)
	{
		ft_chunk(a, b);
		start = 2;
	}
	else if (order_rate >= 5000 && order_rate <= 10000)
	{
		ft_radix(a, b);
		start = 3;
	}
	return (start);
}
