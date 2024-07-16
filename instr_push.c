/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:13:35 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 09:00:51 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	if (a && *a)
		ft_putstr_fd("pb\n", 1);
	push(b, a);
}

void	pa(t_stack **a, t_stack **b)
{
	if (b && *b)
		ft_putstr_fd("pa\n", 1);
	push(a, b);
}
