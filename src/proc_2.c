/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/03 00:59:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_check_p(va_list ap)
{
	size_t	h;

	h = va_arg(ap, size_t);
	return (h);
}

void	ft_process_p(va_list ap, t_flags *arg)
{
	/*
	size_t	h;
	int		len;
	int		n;

	len = 0;
	h = ft_check_p(ap);
	if (arg->min)
	{
		if (h)
			len = arg->min - ft_baselen(h, 16) - 2;
		else
			len = arg->min - 5;
		if (len > 0)
		{
			n = len;
			if (arg->minus)
				ft_print_p(arg, h);
			while (n--)
				ft_putchar(' ');
		}
	}
	if (!arg->min || (arg->min && len > 0 && !arg->minus) || \
		(arg->min && len <= 0))
		ft_print_p(arg, h);
*/


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

void	ft_process_x(va_list ap, t_flags *arg)
{
	size_t	h;
	int		zero;

	h = va_arg(ap, size_t);
	ft_check_arg(arg, h);
	zero = ft_count_zero(arg, ft_baselen(h, 16));
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
		ft_print_space(arg, zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, zero + ft_baselen(h, 16));
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_LOWER);
	}
}

void	ft_process_x2(va_list ap, t_flags *arg)
{
	size_t	h;
	int		zero;

	h = va_arg(ap, size_t);
	ft_check_arg(arg, h);
	zero = ft_count_zero(arg, ft_baselen(h, 16));
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_UPPER);
		ft_print_space(arg, zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, zero + ft_baselen(h, 16));
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_hex(arg, h, HEX_UPPER);
	}
}

void	ft_process_per(t_flags *arg)
{
	ft_putchar('%');
	arg->res++;
}
