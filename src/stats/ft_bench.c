/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_bench.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 12:17:08 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:06:32 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Prints benchmark information.
*
* Displays the selected sorting strategy and
* detailed operation statistics collected during
* execution.
*
* @param algo Requested algorithm identifier.
* @param used Actual algorithm used.
*/

void	ft_bench(int algo, int used)
{
	ft_print_strat(algo, used);
	print_count();
}
