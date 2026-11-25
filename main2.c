/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:20:34 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/25 15:18:08 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	int		algo;
	int		bench;
	int		used;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	bench = 0;
	used = 0;
	algo = 0:
	if(!ft_flags(argv, &algo, &bench))
		return (1);
	if (!ft_parse(&a, argc, argv))
	{
		ft_pileclear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	ft_rank(a);
	if (bench)
		ft_print_rate(a, ft_pilelen(a));
	if (!ft_is_sorted(a))
		used = ft_strat(algo, &a, &b);
	if (bench)
		ft_bench(algo, used);
	ft_pileclear(&a);
	ft_pileclear(&b);
	return (0);
}
