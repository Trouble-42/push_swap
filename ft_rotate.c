/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:13:27 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/19 16:45:15 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate(t_pile **a)
{
	t_pile *rotate;
	t_pile *tmp;

	if (!*a || !(*a)->next)
		return ;
	rotate = *a;
	tmp = (*a)->next;
	while (rotate->next != NULL)
		rotate = rotate->next;
	rotate->next = *a;
	(*a)->next = NULL;
	*a = tmp;
}
