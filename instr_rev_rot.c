/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:15:22 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 08:56:21 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
}

void	rra(t_stack **a, int p)
{
	rev_rotate(a);
	if (p == 1 && ft_list_size(*a) >= 2)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int p)
{
	rev_rotate(b);
	if (p == 1 && ft_list_size(*b) >= 2)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
