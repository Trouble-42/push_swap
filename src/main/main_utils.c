/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 18:27:42 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 22:37:31 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/**
* @brief Prints the contents of a stack.
*
* Displays both the values and ranks of every node
* in the stack from top to bottom.
*
* @param pile Stack to display.
*/

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
/**
* @brief Prints a stack and its sorting status.
*
* Displays a title, the stack contents, and whether
* the stack is currently sorted.
*
* @param a Stack to inspect.
* @param title Title displayed above the stack.
*/

void	ft_print_status(t_pile *a, char *title)
{
	ft_printf("=== %s ===\n", title);
	ft_print_pile(a);
	if (ft_is_sorted(a))
		ft_printf("Sorted: YES\n\n");
	else
		ft_printf("Sorted: NO\n\n");
}
/**
* @brief Parses command-line flags.
*
* Updates algorithm and benchmark settings, then
* adjusts argc and argv so only number arguments
* remain available to the parser.
*
* @param algo Pointer to the selected algorithm.
* @param bench Pointer to benchmark mode flag.
* @param argc Pointer to the number of arguments.
* @param argv Pointer to the argument array.
*
* @return 1 on success, 0 on invalid flags.
*/

int	handle_flags(int *algo, int *bench, int *argc, char ***argv)
{
	int	offset;

	offset = ft_flags(*argv + 1, algo, bench);
	if (offset == -1)
		return (0);
	*argv += offset;
	*argc -= offset;
	return (1);
}
/**
* @brief Initializes and validates stack A.
*
* Parses command-line arguments, checks for errors,
* assigns ranks to nodes and prepares the stack for
* sorting.
*
* @param a Pointer to stack A.
* @param argc Number of arguments.
* @param argv Argument array.
*
* @return 1 on success, 0 on failure.
*/

int	init_stack(t_pile **a, int argc, char **argv)
{
	if (!ft_parse(a, argc, argv))
	{
		ft_pileclear(a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (!*a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_rank(*a);
	return (1);
}
/**
* @brief Executes the selected sorting algorithm.
*
* Optionally displays benchmark information before
* and after sorting. If the stack is already sorted,
* no algorithm is executed.
*
* @param a Pointer to stack A.
* @param b Pointer to stack B.
* @param algo Selected algorithm identifier.
* @param bench Benchmark mode flag.
*/

void	run_algo(t_pile **a, t_pile **b, int algo, int bench)
{
	int	used;

	used = 0;
	if (bench)
		ft_print_rate(*a, ft_pilelen(*a));
	if (!ft_is_sorted(*a))
		used = ft_strat(algo, a, b);
	if (bench)
		ft_bench(algo, used);
}
