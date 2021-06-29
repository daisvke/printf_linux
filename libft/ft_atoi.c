/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:45:47 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/11 16:30:02 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long_maxmin(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				s_count;
	unsigned long	res;

	while (ft_isws(*str))
		str++;
	sign = 1;
	s_count = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		s_count++;
	}
	if (s_count > 1)
		return (0);
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - 48;
	if (res > 9223372036854775807)
		return (ft_long_maxmin(sign));
	return (res * sign);
}
