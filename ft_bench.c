/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_bench.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 12:17:08 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 13:03:02 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_bench(t_pile *a, int nb, int algo, int used)
{
	ft_print_rate(a, nb);
	ft_print_strat(algo, used);
	print_count();
}
