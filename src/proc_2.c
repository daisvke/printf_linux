/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/24 02:03:35 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_sharp	ft_print_o_shp(t_flags *arg, unsigned int o)
{
	int		len;
	t_sharp	shp;

	ft_bzero(&shp, sizeof(shp));
	ft_check_arg(arg, o);
	len = ft_baselen(o, 8);
	shp.len = len;
	shp.zero = ft_count_zero(arg, len);
	if (arg->sharp && !shp.zero)
		ft_putnchar(arg, '0', 1);
	return (shp);
}

void	ft_process_o(va_list ap, t_flags *arg)
{
	unsigned int	o;
	t_sharp			shp;

	o = va_arg(ap, unsigned int);
	shp = ft_print_o_shp(arg, o);
	if (arg->minus)
	{
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_oct(arg, o);
		ft_print_space(arg, shp.zero + shp.len);
	}
	else
	{
		ft_print_space(arg, shp.zero + shp.len);
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_oct(arg, o);
	}
}

void	ft_process_p(va_list ap, t_flags *arg)
{
	size_t	h;
	int		zero;
	int		len;

	h = va_arg(ap, size_t);
	ft_check_arg(arg, h);
	if (h)
		len = ft_baselen(h, 16) + 2;
	else
		len = 5;
	zero = ft_count_zero(arg, len);
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_p(arg, h);
		ft_print_space(arg, zero + len);
	}
	else
	{
		ft_print_space(arg, zero + len);
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_p(arg, h);
	}
}
#include <stdio.h>

t_sharp	ft_print_hex_shp(t_flags *arg, unsigned int h, char *prefix)
{
	t_sharp	shp;

	ft_bzero(&shp, sizeof(shp));
	ft_check_arg(arg, h);
	shp.zero = ft_count_zero(arg, ft_baselen(h, 16));
	if (arg->sharp && h != 0)
		ft_putstr_res(arg, prefix);
	return (shp);
}

void	ft_process_x(va_list ap, t_flags *arg)
{
	unsigned int	h;
	t_sharp			shp;

	h = va_arg(ap, unsigned int);
	shp = ft_print_hex_shp(arg, h, "0x");
	if (arg->minus)
	{
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
	}
}

void	ft_process_x2(va_list ap, t_flags *arg)
{
	unsigned int	h;
	t_sharp			shp;

	h = va_arg(ap, unsigned int);
	shp = ft_print_hex_shp(arg, h, "0X");
	if (arg->minus)
	{
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_UPPER);
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, shp.zero + ft_baselen(h, 16));
		ft_print_zero(arg, shp.zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_UPPER);
	}
}

void	ft_process_per(t_flags *arg)
{
	ft_putchar('%');
	arg->res++;
}
