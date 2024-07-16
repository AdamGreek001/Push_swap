/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:14:28 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 08:56:42 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstlast(*a)->next = tmp;
}

void	ra(t_stack **a, int p)
{
	rotate(a);
	if (p == 1 && ft_list_size(*a) >= 2)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int p)
{
	rotate(b);
	if (p == 1 && ft_list_size(*b) >= 2)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr_fd("rr\n", 1);
}
