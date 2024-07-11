/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:25:49 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 07:01:50 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack     *ft_lstlsat(t_stack *lst)
{
   while (lst->next)
      lst = lst->next;
   return (lst);
}

int   ft_list_size(t_stack *lst)
{
   if (!lst)
      return (0);
   return (1 + ft_list_size(lst->next));
}


void     ft_lstadd_front(t_stack **alst, t_stack *new)
{
   if (!alst || !new)
      return ;
   if (alst)
   {
      if (*alst)
         new->next = *alst;
      *alst = new;
   }
}



t_stack  *ft_lstnew(long n)
{
   t_stack	*new;

   if (n == 2147483648)
      return (NULL);
   new = (t_stack *)malloc(sizeof(t_stack));
   if (!new)
      return (NULL);
   new->n = (int)n;
   new->index = -1;
   new->next = NULL;
   return (new);
}


int	ft_lstadd_back(t_stack **alst, t_stack *new)
{
   // t_stack	*last;

   if (!alst || !new)
      return (0);
   if (!*alst)
   {
      *alst = new;
      return (1);
   }
   else
   {
      if (!is_dup(*alst, new->n))
         return (0);
      ft_lstlsat(*alst)->next = new;
   }
   return (1);
}