/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_argc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 10:05:26 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/19 11:47:54 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push-swap.h"

int	*convert_argc(char **argv, int argc)
{
	int *a;
	int i = 0;
	while (i < argc - 1)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (a);
}
