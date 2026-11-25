/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_atoi.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/07 07:51:44 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 23:02:01 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Checks whether a character is a decimal digit.
*
* @param str Character to test.
* @return 1 if the character is a digit, 0 otherwise.
*/

static int	str_digit(const char str)
{
	return (str >= '0' && str <= '9');
}
/**
* @brief Checks whether a character is not a whitespace.
*
* Whitespace characters include space, tab,
* newline, carriage return, form feed and
* vertical tab.
*
* @param str Character to test.
* @return 0 if the character is whitespace, 1 otherwise.
*/

static int	str_space(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n' || str == '\r' || str == '\t' || str == '\v')
		return (0);
	else
		return (1);
}
/**
* @brief Converts a string to an integer.
*
* Skips leading whitespace characters, handles
* an optional sign, and converts consecutive
* decimal digits into an integer value.
*
* @param nptr String to convert.
* @return Converted integer value.
*/

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while (!str_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	while (nptr[i] != '\0' && str_digit(nptr[i]))
	{
		r = r * 10 + nptr[i] - '0';
		i++;
	}
	r = r * s;
	return (r);
}

/*#include <stdio.h>

int	main(void)
{
char str[] = " +-1234ab567";
int r;
r = ft_atoi(str);
printf("%d", r);
return(0);
}*/
