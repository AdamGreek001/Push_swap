/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:13:35 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 23:15:31 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   push(t_stack **dst, t_stack **src)
{
   t_stack *tmp;

   if (!src || !*src)
      return ;
   tmp = *src;
   *src = (*src)->next;
   tmp->next = *dst;
   *dst = tmp;
}

void   pb(t_stack **a, t_stack **b)
{
   push(b, a);
   if (a)
      ft_putstr_fd("pb\n", 1);
}

void   pa(t_stack **a, t_stack **b)
{
   push(a, b);
   if (b)
      ft_putstr_fd("pa\n", 1);
}
