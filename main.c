/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 11:18:14 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 13:22:32 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!ft_parse(&a, argc, argv))
	{
		ft_pileclear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	ft_rank(a);
	ft_sort(&a, &b);
	ft_pileclear(&a);
	ft_pileclear(&b);
	return (0);
}
