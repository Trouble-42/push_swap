/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:39:00 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/25 12:32:56 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_algo_name(int algo)
{
	if (algo == 0)
		return ("Adaptive");
	if (algo == 1)
		return ("Simple");
	if (algo == 2)
		return ("Medium");
	if (algo == 3)
		return ("Complex");
	if (algo == 4)
		return ("Excellent");
	return ("Error");
}

char *ft_form_name(int used)
{
	if (used == 1)
	   return ("O(n²)");
	if (used == 2)
		return ("0(n√n)");
	if (used == 3)
		return ("0(n log n)");
	return ("Error");
}

void	ft_print_strat(int algo, int used)
{
	ft_printf("[bench] strategy: %s / %s\n", ft_algo_name(algo), ft_form_name(used));
}
