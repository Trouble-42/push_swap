/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_sum_total.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/22 06:48:58 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:06:10 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Computes the total number of operations.
*
* Sums all operation counters maintained by
* ft_count() and returns the overall number
* of executed instructions.
*
* @return Total operation count.
*/

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
/**
* @brief Prints the total operation count.
*
* Displays the total number of instructions
* executed during the current benchmark.
*/

void	ft_print_sum(void)
{
	ft_printf("[bench] total_ops: %d\n", ft_sum_total());
}
