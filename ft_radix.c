/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:02:24 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 15:24:26 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_radix(t_pile **a, t_pile **b)
{
	int	n;
	int	div;
	int	size;

	div = 1;
	size = ft_pilelen(*a);
	while (div <= size - 1)
	{
		n = size;
		while (n > 0)
		{
			if (((*a)->rank / div % 2) == 0)
				pb(a, b);
			else
				ra(a);
			n--;
		}
		while (*b != NULL)
			pa(b, a);
		div *= 2;
	}
}
