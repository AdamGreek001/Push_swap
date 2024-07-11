/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:37:29 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 23:30:19 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//************* sorting functions *************//

static void   sort_3(t_stack **a)
{
      if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
         sa(a, NULL);
      else if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
      {
         sa(a, NULL);
         rra(a, NULL);
      }
      else if ((*a)->n < (*a)->next->n && (*a)->n > (*a)->next->next->n)
         ra(a, NULL);
      else if ((*a)->n < (*a)->next->n && (*a)->n < (*a)->next->next->n)
      {
         sa(a, NULL);
         ra(a, NULL);
      }
}

static void   sort_4(t_stack **a, t_stack **b)
{
   int   i;
   int   min;
   int   max;

   i = 0;
   while (i < 2)
   {
      min = get_min(*a);
      max = get_max(*a);
      while ((*a)->n != min && (*a)->n != max)
         ra(a, NULL);
      if ((*a)->n == min)
         pb(a, b);
      else
      {
         pb(a, b);
         sa(a, NULL);
      }
      i++;
   }
   sort_3(a);
   pa(a, b);
   ra(a, NULL);
}

static void   sort_5(t_stack **a, t_stack **b)
{
   int   i;
   int   min;
   int   max;

   i = 0;
   while (i < 2)
   {
      min = get_min(*a);
      max = get_max(*a);
      while ((*a)->n != min && (*a)->n != max)
         ra(a, NULL);
      if ((*a)->n == min)
         pb(a, b);
      else
      {
         pb(a, b);
         sa(a, NULL);
      }
      i++;
   }
   sort_3(a);
   pa(a, b);
   pa(a, b);
}
