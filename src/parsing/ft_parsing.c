/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parsing.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 13:18:15 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:17:50 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Parses a single integer token.
*
* Reads an optional sign followed by one or more
* decimal digits, validates the resulting value
* against integer limits and advances the string
* pointer to the end of the token.
*
* @param s Pointer to the current position in the string.
* @param out Pointer receiving the parsed integer.
*
* @return 1 on success, 0 on invalid input or overflow.
*/

static int	parse_token(char **s, int *out)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	if (**s < '0' || **s > '9')
		return (0);
	while (**s >= '0' && **s <= '9')
	{
		n = n * 10 + (**s - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		(*s)++;
	}
	*out = (int)(n * sign);
	return (**s == '\0' || **s == ' ');
}
/**
* @brief Parses all numbers contained in a single argument.
*
* Splits a space-separated argument into individual
* integers, creates the corresponding stack nodes
* and appends them to stack A.
*
* @param a Stack being constructed.
* @param s Argument string to parse.
*
* @return 1 on success, 0 on invalid input or allocation failure.
*/

static int	parse_arg(t_pile **a, char *s)
{
	int		value;
	int		found;
	t_pile	*node;

	found = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (!*s)
			break ;
		if (!parse_token(&s, &value))
			return (0);
		node = ft_pilenew(value);
		if (!node)
			return (0);
		ft_pileadd_back(a, node);
		found = 1;
	}
	return (found);
}
/**
* @brief Parses command-line arguments into stack A.
*
* Processes every argument, extracts integer values,
* creates the corresponding stack nodes and verifies
* that no duplicate values are present.
*
* @param a Stack to populate.
* @param argc Number of arguments.
* @param argv Argument array.
*
* @return 1 on success, 0 on invalid input or duplicates.
*/

int	ft_parse(t_pile **a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_arg(a, argv[i]))
			return (0);
		i++;
	}
	return (!ft_has_dup(*a));
}
