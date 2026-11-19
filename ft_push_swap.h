/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:10:20 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/19 19:05:09 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include "ft_printf/ft_printf.h"

typedef struct	s_pile_swap
{
	int	value;
	struct s_pile_swap *next;
}	t_pile;

int		ft_atoi(const char *nptr);
int		*convert_argc(char **argv, int argc);
void	ft_swap(t_pile **a);
void	ft_push(t_pile **a, t_pile **b);
void	ft_rotate(t_pile **a);
void	ft_reverse_rotate(t_pile **a);

#endif
