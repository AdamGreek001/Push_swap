/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:14:28 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 23:15:37 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   rotate(t_stack **a)
{
   t_stack *tmp;
   t_stack *last;

   if (!a || !*a || !(*a)->next)
      return ;
   tmp = *a;
   last = *a;
   while (last->next)
      last = last->next;
   *a = tmp->next;
   tmp->next = NULL;
   last->next = tmp;
}

void   ra(t_stack **a, t_stack **b)
{
   rotate(a);
   if (a)
      ft_putstr_fd("ra\n", 1);
}

void   rb(t_stack **a, t_stack **b)
{
   rotate(b);
   if (b)
      ft_putstr_fd("rb\n", 1);
}

void   rr(t_stack **a, t_stack **b)
{
   rotate(a);
   rotate(b);
   if (a && b)
      ft_putstr_fd("rr\n", 1);
}
