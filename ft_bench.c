/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 12:17:08 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/25 12:25:12 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bench(t_pile *a, int nb, int algo, int used)
{
	ft_print_rate(a, nb);
	ft_print_start(algo, used);
	print_count();
}

