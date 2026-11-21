/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeudy <ajeudy@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:18:14 by ajeudy            #+#    #+#             */
/*   Updated: 2026/11/21 12:18:49 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	t_pile *ptr;

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

int	main(int argc, char **argv)
{
	t_pile *a;
	t_pile *b;
	t_pile *ptr;
	int	i;

	a = NULL;
	b = NULL;
	i = 1;
	while (i < argc)
	{
		ft_pileadd_back(&a, ft_pilenew(ft_atoi(argv[i])));
		i++;
	}
	ft_rank(a);
	ptr = a;
	while (ptr)
	{
		ft_printf("%d | %d\n", ptr->value, ptr->rank);
		ptr = ptr->next;
	}
	ft_printf("--\n");
	ft_radix(&a, &b);
	ptr = a;
	while (ptr)
	{
		ft_printf("%d | %d\n", ptr->value, ptr->rank);
		ptr = ptr->next;
	}
	ft_printf("--\n");
	ptr = b;
	while (ptr)
	{
		ft_printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
	return (0);
}
