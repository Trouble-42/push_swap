/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 09:07:00 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 15:23:10 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rank(t_pile *a)
{
	t_pile	*ptr;
	t_pile	*tmp;

	ptr = a;
	while (ptr)
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->value < ptr->value)
				ptr->rank += 1;
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
