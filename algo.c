/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:09 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 08:50:57 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	if (ft_list_size(a) == 1)
		return (0);
	while (a)
	{
		if (a->next && a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	search_for_index(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack && stack->index != index)
	{
		i++;
		stack = stack->next;
	}
	if (i < ft_list_size(stack) / 2)
		return (0);
	return (1);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	pv1;
	int	pv2;

	pv2 = 0;
	while (ft_list_size(*a) > 3)
	{
		pv1 = (ft_list_size(*a) / 6) + pv2;
		pv2 += ft_list_size(*a) / 3;
		while (ft_list_size(*b) < pv2 && ft_list_size(*a) > 3)
		{
			if (*b && (*a)->index >= pv2 && (*b)->index < pv1)
				rr(a, b);
			else if (*b && (*b)->index < pv1)
				rb(b, 1);
			if ((*a)->index < pv2)
				pb(a, b);
			else if ((*a)->index >= pv2)
				ra(a, 1);
		}
	}
	sort_3(a);
}

void	push_sort_to_a(t_stack **a, t_stack **b)
{
	int	max;

	max = ft_lstlast(*a)->index;
	while (ft_list_size(*b) > 0)
	{
		if ((*b)->index == (*a)->index - 1)
			pa(a, b);
		else if (ft_lstlast(*b)->index == (*a)->index - 1)
		{
			rrb(b, 1);
			pa(a, b);
		}
		else if (ft_lstlast(*a)->index == max)
		{
			pa(a, b);
			ra(a, 1);
		}
		else if (*b && ft_lstlast(*a)->index < (*b)->index)
		{
			pa(a, b);
			ra(a, 1);
		}
		else if (*b && ft_lstlast(*a)->index < ft_lstlast(*b)->index)
		{
			rrb(b, 1);
			pa(a, b);
			ra(a, 1);
		}
		else if (ft_lstlast(*a)->index == (*a)->index - 1)
			rra(a, 1);
		else if (*b && search_for_index(*b, (*a)->index - 1))
			rrb(b, 1);
		else
			rb(b, 1);
	}
}