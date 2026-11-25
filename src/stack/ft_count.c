/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_count.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 17:56:03 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:02:48 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Updates or retrieves an operation counter.
*
* Stores the number of times each push_swap operation
* has been executed using a static array of counters.
*
* @param op Operation identifier.
* @param inc If non-zero, increments the counter.
*
* @return Current value of the selected counter.
*/

int	ft_count(int op, int inc)
{
	static int	tab[11];

	if (inc)
		tab[op]++;
	return (tab[op]);
}
/**
* @brief Prints benchmark operation statistics.
*
* Displays the total number of operations executed
* and a detailed breakdown for each push_swap
* instruction.
*/

void	print_count(void)
{
	ft_printf("[bench] total_ops: %d\n", (ft_count(C_SA, 0) + ft_count(C_SB, 0) + ft_count(C_SS, 0) + ft_count(C_PA, 0) + ft_count(C_PB, 0) + ft_count(C_RA, 0) + ft_count(C_RB, 0) + ft_count(C_RR, 0) + ft_count(C_RRA, 0) + ft_count(C_RRB, 0) + ft_count(C_RRR, 0)));
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d \n", ft_count(C_SA, 0), ft_count(C_SB, 0), ft_count(C_SS, 0), ft_count(C_PA, 0), ft_count(C_PB, 0));
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", ft_count(C_RA, 0), ft_count(C_RB, 0), ft_count(C_RR, 0),
		ft_count(C_RRA, 0), ft_count(C_RRB, 0), ft_count(C_RRR, 0));
}
