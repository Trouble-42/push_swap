/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 13:18:15 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 13:18:15 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_push_swap.h"

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
