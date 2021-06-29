/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:46:04 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/01 02:23:22 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	if (!s)
		return (malloc(0));
	p = (char *)malloc(ft_strlen(s) + 1 * sizeof(*p));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = (*f)(i, (char)(s[i]));
		i++;
	}
	p[ft_strlen(s)] = '\0';
	return (p);
}
