/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrctions_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:35:58 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 23:15:00 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//******** ft_putstr_fd *******//

char     ft_putstr_fd(char *s, int fd)
{
    return (write(fd, s, ft_strlen(s)));
}

//******* swap moves *******//
static void   swap(t_stack **a)
{
   t_stack *tmp;

   if (!a || !*a || !(*a)->next)
      return ;
   tmp = (*a)->next;
   (*a)->next = tmp->next;
   tmp->next = *a;
   *a = tmp;
}

void   sb(t_stack **a, t_stack **b)
{
   swap(b);
   if (b)
      ft_putstr_fd("sb\n", 1);
}

void   sa(t_stack **a, t_stack **b)
{
   swap(a);
   if (a)
      ft_putstr_fd("sa\n", 1);
}
 
void  ss(t_stack **a, t_stack **b)
{
   swap(a);
   swap(b);
   if (a && b)
      ft_putstr_fd("ss\n", 1);
}

//******* push moves *******//



//******* rotate moves *******//



//******* reverse rotate moves *******//

 
