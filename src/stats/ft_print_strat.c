/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_strat.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 11:39:00 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:08:01 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Returns the name of a sorting strategy.
*
* Converts an algorithm identifier into a
* human-readable strategy name.
*
* @param algo Algorithm identifier.
*
* @return Strategy name corresponding to the identifier.
*/

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
/**
* @brief Returns the complexity label of a strategy.
*
* Converts a strategy identifier into its expected
* asymptotic complexity representation.
*
* @param used Strategy identifier.
*
* @return Complexity string associated with the strategy.
*/

char	*ft_form_name(int used)
{
	if (used == 1)
		return ("O(n²)");
	if (used == 2)
		return ("0(n√n)");
	if (used == 3)
		return ("0(n log n)");
	return ("Error");
}
/**
* @brief Prints benchmark strategy information.
*
* Displays the selected strategy together with
* the complexity category of the algorithm that
* was ultimately executed.
*
* @param algo Requested algorithm identifier.
* @param used Actual strategy used.
*/

void	ft_print_strat(int algo, int used)
{
	ft_printf("[bench] strategy: %s / %s\n", ft_algo_name(algo), ft_form_name(used));
}
