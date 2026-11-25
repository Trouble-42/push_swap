/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 11:18:14 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 14:17:54 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_pile(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	ft_printf("Values: ");
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\nRanks : ");
	tmp = pile;
	while (tmp)
	{
		ft_printf("%d ", tmp->rank);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_print_status(t_pile *a, char *title)
{
	ft_printf("=== %s ===\n", title);
	ft_print_pile(a);
	if (ft_is_sorted(a))
		ft_printf("Sorted: YES\n\n");
	else
		ft_printf("Sorted: NO\n\n");
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	int		algo;
	int		bench;
	int		offset;

	a = NULL;
	b = NULL;
	algo = 0;
	bench = 0;
	offset = 0;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		offset = ft_flags(argv + 1, &algo, &bench);
		if (offset == -1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		argv += offset;
		argc -= offset;
	}
	if (!ft_parse(&a, argc, argv))
	{
		ft_pileclear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_rank(a);
	if (!bench)
		ft_print_status(a, "BEFORE SORT");
	ft_strat(algo, &a, &b);
	if (!bench)
		ft_print_status(a, "AFTER SORT");
	ft_pileclear(&a);
	ft_pileclear(&b);
	return (0);
}
