/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:41:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 01:22:26 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_iter(char **split, char *s, char c)
{
	int		i;
	char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s != c && *s)
			s++;
		split[i] = ft_strsdup(start, s - start);
		if (!split[i])
		{
			ft_free_array_of_pointers(split, i);
			return (-1);
		}
		i++;
	}
	split[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		res;
	char	**split;

	if (!s)
		return (malloc(0));
	split = (char **)malloc(sizeof(*split) * (ft_wordcount((char *)s, c) + 1));
	if (!split)
		return (NULL);
	res = ft_split_iter(split, (char *)s, c);
	if (res < 0)
		return (NULL);
	return (split);
}
