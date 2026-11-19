/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:06:13 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/19 16:48:15 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_reverse_rotate(t_pile **a)
{
	t_pile	*rotate;
	t_pile	*tmp;

	if (!*a || !(*a)->next)
		return ;
	rotate = *a;
	while (rotate->next->next != NULL)
		rotate = rotate->next;
	tmp = rotate->next;
	rotate->next = NULL;
	tmp->next = *a;
	*a = tmp;
}
