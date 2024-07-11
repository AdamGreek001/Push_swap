/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:16:18 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 23:10:06 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t_size;
	void	*p;

	if ((int)count < 0 || (int)size < 0)
		return (NULL);
	else
		t_size = count * size;
	p = malloc(t_size);
	if (p)
		ft_memset(p, 0, t_size);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	s_size;

	s_size = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_size)
		start = s_size;
	if (len > s_size - start)
		len = s_size - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}

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