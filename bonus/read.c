/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:52:39 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/24 06:53:45 by dtanigaw         ###   ########.fr       */
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

void	ft_read_space(t_flags *arg)
{
	if (!arg->plus)
		arg->space = true;
	arg->minus = false;
	arg->len++;
	arg->s++;
}

void	ft_read_plus(t_flags *arg)
{
	arg->space = false;
	arg->plus = true;
	arg->len++;
	arg->s++;
}
