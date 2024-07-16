/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrctions_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:35:58 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 08:57:47 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//******** ft_putstr_fd *******//

char	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

//******* swap moves *******//
void	swap(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*stack = tmp2;
}

void	sb(t_stack **b, int p)
{
	swap(b);
	if (p == 1 && ft_list_size(*b) >= 2)
		ft_putstr_fd("sb\n", 1);
}

void	sa(t_stack **a, int p)
{
	swap(a);
	if (p == 1 && ft_list_size(*a) >= 2)
		ft_putstr_fd("sa\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}
