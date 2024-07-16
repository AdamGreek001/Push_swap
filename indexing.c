/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:35:55 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/13 06:47:10 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		min;
	int		index;
	t_stack	*hold;

	(1) && (tmp1 = *a, index = 0);
	while (tmp1)
	{
		(1) && (tmp2 = *a, hold = NULL, min = 2147483647);
		while (tmp2)
		{
			if (tmp2->n <= min && tmp2->index == -1)
			{
				min = tmp2->n;
				hold = tmp2;
			}
			tmp2 = tmp2->next;
		}
		(hold) && (hold->index = index);
		index++;
		tmp1 = tmp1->next;
	}
}
