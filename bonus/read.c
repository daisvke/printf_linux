/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:52:39 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/24 01:50:46 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


bool	ft_read_lm(t_flags *arg)
{
	if (*(arg->s) == 'h')
	{
		if (*(arg->s + 1) == 'h')
		{
			arg->s += 2;
			arg->len += 2;
		}
		else
		{
			arg->len++;
			arg->s++;
		}
	}
	return (true);
}

bool	ft_read_shp(t_flags *arg)
{
	if (*(arg->s) == '#')
	{
		arg->sharp = true;
		while (*(arg->s) == '#')
		{
			arg->len++;
			arg->s++;
		}
	}
	return (true);
}
