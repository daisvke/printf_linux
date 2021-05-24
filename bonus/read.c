/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:52:39 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/24 05:57:06 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_read_lm(t_flags *arg)
{
	if (*(arg->s + 1) == 'h')
	{
		arg->len += 2;
		arg->s += 2;
	}
	else
	{
		arg->len++;
		arg->s++;
	}
}

void	ft_read_shp(t_flags *arg)
{
	arg->sharp = true;
	while (*(arg->s) == '#')
	{
		arg->len++;
		arg->s++;
	}
}
