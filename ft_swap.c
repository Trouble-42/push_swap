/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:27:13 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 18:05:56 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_pile **a)
{
	int	tmp;

	if (!*a || !a)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
}

void	sa(t_pile **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
	ft_count(C_SA, 1);
}

void	sb(t_pile **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
	ft_count(C_SB, 1);
}

void	ss(t_pile **a, t_pile **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
	ft_count(C_SS, 1);
}
