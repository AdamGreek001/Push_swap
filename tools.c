/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:25:33 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 06:56:46 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	my_exit(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*cur;

	tmp = *a;
	while (tmp)
	{
		cur = tmp->next;
		free(tmp);
		tmp = cur;
	}
	exit(n);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*cur;

	tmp = *a;
	while (tmp)
	{
		cur = tmp->next;
		free(tmp);
		tmp = cur;
	}
}

void	error(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
