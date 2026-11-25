/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_disorder.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 16:26:41 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/26 00:07:09 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Computes the disorder rate of a stack.
*
* Counts the number of inversions present in the
* stack and expresses the result as a percentage
* of the maximum possible number of inversions.
*
* The returned value is scaled by 100:
* - 0     = 0.00%
* - 5000  = 50.00%
* - 10000 = 100.00%
*
* @param a Stack to analyze.
* @param nb Number of elements in the stack.
*
* @return Disorder rate scaled to the range [0, 10000].
*/

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
/**
* @brief Prints the disorder rate of a stack.
*
* Displays the percentage of disorder computed
* by ft_disorder() using a fixed-point format
* with two decimal places.
*
* @param a Stack to analyze.
* @param nb Number of elements in the stack.
*/

void	ft_print_rate(t_pile *a, int nb)
{
	int	i;

	i = (int) ft_disorder(a, nb);
	ft_printf("[bench] disorder: ");
	ft_printf("%d.%d%d%%\n", i / 100, (i % 100) / 10, i % 10);
}
