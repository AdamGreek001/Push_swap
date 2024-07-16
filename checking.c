/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 23:38:42 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/16 08:59:00 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long long	r;
	int			sign;
	size_t		i;

	r = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if ((r > 2147483647 && sign == 1) || (r > 2147483648 && sign == -1))
			return (2147483648);
		i++;
	}
	return (r * sign);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i++] = s2[j];
		j++;
	}
	res[i] = '\0';
	return (res);
}

int	is_valid(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!i && (s[i] == '+' || s[i] == '-') && !(s[i + 1] >= '0' && s[i
					+ 1] <= '9'))
			return (0);
		else if (i != 0 && (s[i] == '+' || s[i] == '-'))
			return (0);
		else if (!(s[i] >= '0' && s[i] <= '9') && (s[i] != '+' && s[i] != '-'))
			return (0);
	}
	return (1);
}

int	is_dup(t_stack *a, int n)
{
	while (a)
	{
		if (a->n == n)
			return (0);
		a = a->next;
	}
	return (1);
}

char	*ft_strjoin_av(int ac, char **str, t_stack **a)
{
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (str[i][0] == '\0')
			return (my_exit(a, 1), NULL);
		tmp = ft_split(str[i], ' ');
		if (!tmp || !(*tmp))
			return (my_exit(a, 1), NULL);
		j = -1;
		while (tmp[++j])
		{
			if (!is_valid(tmp[j]) || !ft_lstadd_back(a,
					ft_lstnew(ft_atoi(tmp[j]))))
				return (free_2d(tmp), my_exit(a, 1), NULL);
		}
		free_2d(tmp);
		i++;
	}
	return (*str);
}
