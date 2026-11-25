/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 11:18:14 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:34:24 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/**
* @brief Entry point of the push_swap program.
*
* Initializes the stacks, parses command-line arguments,
* handles optional flags, executes the selected sorting
* strategy, and frees allocated memory before exiting.
*
* @param argc Number of command-line arguments.
* @param argv Array of command-line arguments.
* @return 0 on success, 1 on error.
*/
#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	int		algo;
	int		bench;

	a = NULL;
	b = NULL;
	algo = 0;
	bench = 0;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == '-')
		if (!handle_flags(&algo, &bench, &argc, &argv))
		return (write(2, "Error\n", 6), 1);
	if (!init_stack(&a, argc, argv))
		return (1);
	run_algo(&a, &b, algo, bench);
	ft_pileclear(&a);
	ft_pileclear(&b);
	return (0);
}
