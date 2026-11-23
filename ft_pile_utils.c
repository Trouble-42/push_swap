/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_pile_utils.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 13:19:04 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/23 13:19:04 by rkraan          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_pile	*ft_pilenew(int value)
{
	t_pile	*start;

	start = malloc(sizeof(t_pile));
	if (!start)
		return (NULL);
	start->value = value;
	start->rank = 0;
	start->next = NULL;
	return (start);
}

void	ft_pileadd_back(t_pile **a, t_pile *new)
{
	t_pile	*ptr;

	if (!a || !new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	ptr = *a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

void	ft_pileclear(t_pile **p)
{
	t_pile	*next;

	while (p && *p)
	{
		next = (*p)->next;
		free(*p);
		*p = next;
	}
}

int	ft_has_dup(t_pile *a)
{
	t_pile	*cur;

	while (a)
	{
		cur = a->next;
		while (cur)
		{
			if (cur->value == a->value)
				return (1);
			cur = cur->next;
		}
		a = a->next;
	}
	return (0);
}
