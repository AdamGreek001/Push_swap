/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:15:22 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 23:15:27 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   rev_rotate(t_stack **a)
{
   t_stack *tmp;
   t_stack *last;

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

void   rra(t_stack **a, t_stack **b)
{
   rev_rotate(a);
   if (a)
      ft_putstr_fd("rra\n", 1);
}

void   rrb(t_stack **a, t_stack **b)
{
   rev_rotate(b);
   if (b)
      ft_putstr_fd("rrb\n", 1);
}

void   rrr(t_stack **a, t_stack **b)
{
   rev_rotate(a);
   rev_rotate(b);
   if (a && b)
      ft_putstr_fd("rrr\n", 1);
} 
