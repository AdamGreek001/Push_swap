/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:23:00 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 07:13:31 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int			n;
	int			index;
	struct s_stack	*next;
} t_stack;

char		**ft_split(char const *s, char c);
t_stack	*ft_lstlsat(t_stack *lst);
void     ft_lstadd_front(t_stack **alst, t_stack *new);
t_stack  *ft_lstnew(long n);
int		ft_lstadd_back(t_stack **alst, t_stack *new);
size_t	ft_strlen(const char *s);
int	is_valid(char *s);
int	is_dup(t_stack *a, int n);
void	index_stack(t_stack **a);


#endif