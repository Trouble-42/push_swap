/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:10:20 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 15:22:34 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

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

#endif
