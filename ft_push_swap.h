/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_push_swap.h                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 11:10:20 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/25 13:09:15 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define C_SA 0
# define C_SB 1
# define C_SS 2
# define C_PA 3
# define C_PB 4
# define C_RA 5
# define C_RB 6
# define C_RR 7
# define C_RRA 8
# define C_RRB 9
# define C_RRR 10
# define DISORDER_LOW 2000
# define DISORDER_HIGH 5000

typedef struct s_pile_swap
{
	int					value;
	int					rank;
	struct s_pile_swap	*next;
}	t_pile;

int		ft_atoi(const char *nptr);
int		ft_pilelen(t_pile *a);
void	ft_swap(t_pile **a);
void	sa(t_pile **a);
void	sb(t_pile **b);
void	ss(t_pile **a, t_pile **b);
void	ft_push(t_pile **a, t_pile **b);
void	pa(t_pile **b, t_pile **a);
void	pb(t_pile **a, t_pile **b);
void	ft_rotate(t_pile **a);
void	ra(t_pile **a);
void	rb(t_pile **b);
void	rr(t_pile **a, t_pile **b);
void	ft_reverse_rotate(t_pile **a);
void	rra(t_pile **a);
void	rrb(t_pile **b);
void	rrr(t_pile **a, t_pile **b);
int		ft_is_sorted(t_pile *a);
void	ft_rank(t_pile *a);
int		ft_pos_select(t_pile *a, int i);
void	ft_select(t_pile **a, t_pile **b);
void	ft_radix(t_pile **a, t_pile **b);
long	ft_disorder(t_pile *a, int nb);
void	ft_print_rate(t_pile *a, int nb);
int		ft_count(int op, int inc);
void	print_count(void);
void	ft_chunk(t_pile **a, t_pile **b);
void	push_to_a(t_pile **a, t_pile **b);
void	push_to_b(t_pile **a, t_pile **b);
int		get_chunk_size(int size);
int		find_chunk_pos(t_pile *a, int limit);
void	move_chunk_top(t_pile **a, int pos);
int		find_max_pos(t_pile *b);
void	move_max_top(t_pile **b);
void	ft_sort_three(t_pile **a);
void	push_cheapest(t_pile **a, t_pile **b);
void	push_back(t_pile **a, t_pile **b);
void	ft_turk(t_pile **a, t_pile **b);
int		ft_pos(t_pile *p, int rank);
int		ft_min_rank(t_pile *p);
int		ft_max_rank(t_pile *p);
int		ft_target_a(t_pile *a, int rank);
int		ft_target_b(t_pile *b, int rank);
void	rot_both(t_pile **a, t_pile **b, int *ma, int *mb);
void	ft_rot_a(t_pile **a, int m);
void	ft_rot_b(t_pile **b, int m);
void	ft_align(t_pile **a, t_pile **b, int i, int j);
int		node_cost(t_pile *a, t_pile *b, int i, int rank);
int		ft_pair_cost(int ma, int mb);
int		ft_signed(int pos, int size);
int		ft_abs(int n);
int		node_cost(t_pile *a, t_pile *b, int i, int rank);
int		ft_cheapest_a(t_pile *a, t_pile *b);
t_pile	*ft_pilenew(int value);
void	ft_pileadd_back(t_pile **a, t_pile *new);
void	ft_pileclear(t_pile **p);
int		ft_has_dup(t_pile *a);
int		ft_parse(t_pile **a, int argc, char **argv);
void	ft_sort(t_pile **a, t_pile **b);
int		ft_strcmp(char *s1, char *s2);
int		*ft_flags(char **argv, int *algo, int *bench);
int		ft_strat(int algo, t_pile **a, t_pile **b);
int		ft_adaptative(t_pile **a, t_pile **b);
void	ft_bench(t_pile *a, int nb, int algo, int used);
int		ft_adaptative(t_pile **a, t_pile **b);
char	*ft_algo_name(int algo);
char	*ft_form_name(int used);
void	ft_print_strat(int algo, int used);

#endif
