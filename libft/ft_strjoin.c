/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:34:49 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/21 01:09:07 by alien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*joined;

	if (!s1 || !s2)
		return (malloc(0));
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(*joined) * (len + 1));
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, ft_strlen(s1));
	ft_memcpy(&joined[ft_strlen(s1)], s2, ft_strlen(s2));
	joined[len] = '\0';
	return (joined);
}
