/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:00:00 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/19 19:37:47 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "small_sort.h"
#include "main_operations.h"

static int	find_index_of_value(const t_stack *s, int val)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->items[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

static void	move_index_to_top(t_stack *a, int idx)
{
	int	ra_count;
	int	rra_count;
	int	i;

	if (idx < 0)
		return ;
	ra_count = a->top - idx;
	rra_count = idx + 1;
	if (ra_count <= rra_count)
	{
		i = 0;
		while (i++ < ra_count)
			rotate(a, "ra\n");
	}
	else
	{
		i = 0;
		while (i++ < rra_count)
			reverse_rotate(a, "rra\n");
	}
}

void	sort_three(t_stack *a)
{
	int	i;
	int	max_pos;

	if (is_sorted(a))
		return ;
	max_pos = 0;
	i = 1;
	while (i <= a->top)
		if (a->items[i++] > a->items[max_pos])
			max_pos = i - 1;
	if (max_pos == a->top)
		rotate(a, "ra\n");
	else if (max_pos == a->top - 1)
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	if (!is_sorted(a) && a->items[a->top - 1] < a->items[a->top])
		swap(a, "sa\n");
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	idx;

	idx = find_index_of_value(a, 0);
	move_index_to_top(a, idx);
	push_pop(b, a, "pb\n");
	idx = find_index_of_value(a, 1);
	move_index_to_top(a, idx);
	push_pop(b, a, "pb\n");
	sort_three(a);
	push_pop(a, b, "pa\n");
	push_pop(a, b, "pa\n");
}
