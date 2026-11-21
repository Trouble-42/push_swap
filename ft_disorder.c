/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:26:41 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 17:34:16 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_disorder(t_pile *a, int nb)
{
	t_pile	*ptr;
	t_pile	*tmp;
	long	i;
	long	n;

	if (nb < 2)
		return (0);
	i = 0;
	ptr = a;
	n = nb * (nb - 1) / 2;
	while (ptr)
	{
		tmp = ptr->next;
		while (tmp)
		{
			if (ptr->rank > tmp->rank)
				i++;
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
	i = i * 10000 / n;
	return (i);
}

void	ft_print_rate(t_pile *a, int nb)
{
	int	i;

	i = (int)ft_disorder(a, nb);
	ft_printf("[bench] disorder: ");
	ft_printf("%d.%d%d%%\n", i / 100, (i % 100) / 10, i % 10);
}
