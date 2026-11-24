/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_total.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 06:48:58 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/22 06:55:35 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sum_total(void)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 11)
	{
		sum += ft_count(i, 0);
		i++;
	}
	return (sum);
}

void	ft_print_sum(void)
{
	ft_printf("[bench] total_ops: %d\n", ft_sum_total());
}
