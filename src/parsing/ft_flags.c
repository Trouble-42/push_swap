/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_flags.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 08:41:40 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:07:22 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Compares two strings lexicographically.
*
* Compares the strings character by character until
* a difference is found or the end of a string is
* reached.
*
* @param s1 First string.
* @param s2 Second string.
* @return Difference between the first differing characters.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/**
* @brief Parses command-line flags.
*
* Processes all leading arguments beginning with "--"
* and updates the selected algorithm and benchmark
* settings accordingly.
*
* Supported flags:
* - --bench
* - --adaptative
* - --simple
* - --medium
* - --complex
* - --bonus
*
* @param argv Argument array.
* @param algo Selected algorithm identifier.
* @param bench Benchmark mode flag.
*
* @return Number of parsed flags, or -1 on error.
*/

int	ft_flags(char **argv, int *algo, int *bench)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strcmp(argv[i], "--bench"))
			*bench = 1;
		else if (!ft_strcmp(argv[i], "--adaptative"))
			*algo = 0;
		else if (!ft_strcmp(argv[i], "--simple"))
			*algo = 1;
		else if (!ft_strcmp(argv[i], "--medium"))
			*algo = 2;
		else if (!ft_strcmp(argv[i], "--complex"))
			*algo = 3;
		else if (!ft_strcmp(argv[i], "--bonus"))
			*algo = 4;
		else
			return (-1);
		i++;
	}
	return (i);
}
/**
* @brief Executes the selected sorting strategy.
*
* Dispatches execution to the sorting algorithm
* associated with the specified identifier.
*
* Algorithm mapping:
* - 0 : Adaptative
* - 1 : Select
* - 2 : Chunk
* - 3 : Turk
* - 4 : Radix
*
* @param algo Algorithm identifier.
* @param a Stack A.
* @param b Stack B.
*
* @return Identifier of the algorithm used.
*/

int	ft_strat(int algo, t_pile **a, t_pile **b)
{
	if (algo == 0)
		return (ft_adaptative(a, b));
	if (algo == 1)
		ft_select(a, b);
	else if (algo == 2)
		ft_chunk(a, b);
	else if (algo == 3)
		ft_turk(a, b);
	else if (algo == 4)
		ft_radix(a, b);
	return (algo);
}
