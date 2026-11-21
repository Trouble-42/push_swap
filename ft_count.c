/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:56:03 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 18:46:21 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count(int op, int inc)
{
	static int tab[11];
	if (inc)
		tab[op]++;
	return (tab[op]);
}

void	print_count(void)
{
	/*ft_printf("[bench] total_ops: */
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d \n",
			ft_count(C_SA, 0), ft_count(C_SB, 0), ft_count(C_SS, 0),
			ft_count(C_PA, 0), ft_count(C_PB, 0)); 
			
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 
			ft_count(C_RA, 0), ft_count(C_RB, 0), ft_count(C_RR, 0),
			ft_count(C_RRA, 0), ft_count(C_RRB, 0), ft_count(C_RRR, 0));
}
