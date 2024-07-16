/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:16:18 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 07:47:24 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_w(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	*fill_table(char const *s, char c, int *i_ptr)
{
	int		a;
	int		hold;
	char	*str;

	while (s[*i_ptr] && s[*i_ptr] == c)
		(*i_ptr)++;
	a = 0;
	if (s[*i_ptr] && s[*i_ptr] != c)
		hold = *i_ptr;
	while (s[*i_ptr] && s[*i_ptr] != c)
	{
		(*i_ptr)++;
		a++;
	}
	str = ft_substr(s, hold, a);
	if (!str)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		counter;

	if (!s)
		return (NULL);
	i = 0;
	j = count_w(s, c);
	str = ft_calloc(sizeof(char *), (j + 1));
	if (!str)
		return (NULL);
	counter = -1;
	while (s[i] && ++counter < j)
	{
		str[counter] = fill_table(s, c, &i);
		if (!str[counter])
		{
			while (counter--)
				free(str[counter]);
			free(str);
			return (NULL);
		}
	}
	return (str);
}
