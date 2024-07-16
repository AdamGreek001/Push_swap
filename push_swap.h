/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:23:00 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 08:51:10 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				n;
	int				index;
	struct s_stack	*next;
}					t_stack;

char				**ft_split(char const *s, char c);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_front(t_stack **alst, t_stack *new);
t_stack				*ft_lstnew(long n);
int					ft_lstadd_back(t_stack **alst, t_stack *new);
size_t				ft_strlen(const char *s);
int					is_valid(char *s);
int					is_dup(t_stack *a, int n);
void				index_stack(t_stack **a);
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				sa(t_stack **a, int p);
void				sb(t_stack **b, int p);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a, int p);
void				rb(t_stack **b, int p);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int p);
void				rrb(t_stack **b, int p);
void				rrr(t_stack **a, t_stack **b);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);
void				rotate(t_stack **a);
void				rev_rotate(t_stack **a);
int					ft_list_size(t_stack *lst);
void				push(t_stack **dst, t_stack **src);
void				free_stack(t_stack **a);
void				error(t_stack **a, t_stack **b);
void				my_exit(t_stack **a, int n);
void				free_2d(char **s);
int					find_min(t_stack *a);
char				ft_putstr_fd(char *s, int fd);
int					ft_list_size(t_stack *lst);
char				*ft_strjoin_av(int ac, char **str, t_stack **a);
void	*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	push_to_b(t_stack **a, t_stack **b);
void	push_sort_to_a(t_stack **a, t_stack **b);
int	is_sorted(t_stack *a);

#endif