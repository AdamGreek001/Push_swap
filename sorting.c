/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:37:29 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 09:24:38 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//************* sorting functions *************//
int	find_min(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		if (a->n < tmp->n)
			tmp = a;
		a = a->next;
	}
	return (tmp->n);
}

int	is_up(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (a && a->n != n)
		(1) && (i++, a = a->next);
	if (i < ft_list_size(a) / 2)
		return (1);
	return (0);
}

void	sort_3(t_stack **a)
{
	if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
		sa(a, 1);
	else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
	{
		ra(a, 1);
		if ((*a)->n > (*a)->next->n)
			sa(a, 1);
	}
	else if ((*a)->n < (*a)->next->n && (*a)->n > (*a)->next->next->n)
		rra(a, 1);
	else if ((*a)->n < (*a)->next->n && (*a)->n < (*a)->next->next->n
		&& (*a)->next->n > (*a)->next->next->n)
	{
		sa(a, 1);
		ra(a, 1);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->n != min)
	{
		if (is_up(*a, min))
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

// void	sort_5(t_stack **a, t_stack **b)
// {
// 	int	i;
// 	int	min;

// 	i = -1;
// 	while (++i < 2)
// 	{
// 		min = find_min(*a);
// 		while ((*a)->n != min && i < 2)
// 		{
// 			if ((*a)->index == 1 && ++i)
// 				pb(a, b);
// 			if (is_up(*a, min))
// 				ra(a, 1);
// 			else
// 				rra(a, 1);
// 		}
// 		pb(a, b);
// 	}
// 	if ((*b)->index == 0)
// 		sb(b, 1);
// 	sort_3(a);
// 	pa(a, b);
// 	pa(a, b);
// }
void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_list_size(*b) != 2)
	{
		if ((*a)->index < 2)
			pb(a, b);
		else if (ft_lstlast(*a)->index < 2)
		{
			rra(a, 1);
			pb(a, b);
		}
		else
			rra(a, 1);
	}
	if ((*b)->index == 0)
		sb(b, 1);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}