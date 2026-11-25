/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 08:41:40 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/25 12:15:05 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_flags(char *argv, int *algo, int *bench)
{
	if (!ft_strcmp(argv[i], "--bench"))
		*bench = 1;
	if (!ft_strcmp(argv[i], "--adaptative"))
		*algo = 0;
	else if (!ft_strcmp(argv[i], "--simple"))
		*algo = 1;
	else if (!ft_strcmp(argv[i], "--medium"))
		*algo = 2;
	else if (!ft_strcmp(argv[i], "--complex"))
		*algo = 3;
	else if (!ft_strcmp(argv[i], "--excellent"))
		*algo = 4;
	i++;
	return (algo);
}

int	ft_strat(int algo, t_pile **a, t_pile **b)
{
	if (algo == 0)
		ft_adaptative(a, b);
	if (algo == 1)
		ft_select(a, b);
	if (algo == 2)
		ft_chunk(a, b);
	if (algo == 3)
		ft_radix(a, b);
	if (algo == 4)
		ft_turk(a, b);
	return (algo);
}
