/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_chunk.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: rkraan <ruben.kraan@learner.42.tech>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/21 15:16:08 by rkraan           #+#    #+#              */
/*   Updated: 2026/11/21 15:50:17 by ajeudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	stack_size(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}*/

void	print_stack(char *name, t_stack *s)
{
	printf("\n%s:\n", name);
	while (s)
	{
		printf("[%d|%d] ", s->value, s->index);
		s = s->next;
	}
	printf("\n");
}

/* OPERATIONS */

/*void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rb(t_stack **b)
{
	ra(b);
}

void	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_stack **b)
{
	rra(b);
}*/

/* CHUNK SORT */

int	find_chunk_pos(t_stack *a, int limit)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index <= limit)
			return (pos);
		a = a->next;
		pos++;
	}
	return (0);
}

void	move_chunk_top(t_stack **a, int pos)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	chunk;
	int	pushed;
	int	pos;

	chunk = 3;
	pushed = 0;
	while (*a)
	{
		pos = find_chunk_pos(*a, pushed + chunk);
		move_chunk_top(a, pos);
		if ((*a)->index <= pushed)
		{
			pb(a, b);
			rb(b);
		}
		else
			pb(a, b);
		pushed++;
	}
}

int	find_max_pos(t_stack *b)
{
	int	max;
	int	max_pos;
	int	pos;

	max = b->index;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

void	move_max_top(t_stack **b)
{
	int	pos;
	int	size;

	size = stack_size(*b);
	pos = find_max_pos(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(b);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		move_max_top(b);
		pa(a, b);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}

/*int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}*/

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	add_back(&a, new_node(42, 4));
	add_back(&a, new_node(3, 1));
	add_back(&a, new_node(99, 7));
	add_back(&a, new_node(1, 0));
	add_back(&a, new_node(50, 5));
	add_back(&a, new_node(25, 3));
	add_back(&a, new_node(75, 6));
	add_back(&a, new_node(12, 2));
	print_stack("A BEFORE", a);
	sort_big(&a, &b);
	print_stack("A AFTER", a);
	if (is_sorted(a))
		printf("\nOK: STACK SORTED\n");
	else
		printf("\nKO: STACK NOT SORTED\n");
	return (0);
}
