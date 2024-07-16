/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:25:16 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 09:27:10 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_list_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*b;
	t_stack	*a;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!ft_strjoin_av(ac, av, &a))
		return (1);
	if (is_sorted(a))
		return (0);
	if (ft_list_size(a) <= 5)
		push_swap(&a, &b);
	else
	{
		index_stack(&a);
		push_to_b(&a, &b);
		push_sort_to_a(&a, &b);
		while (!is_sorted(a))
			rra(&a, 1);
	}
	free_stack(&a);
	return (0);
}
