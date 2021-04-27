/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/27 14:19:20 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	ft_check_p(va_list ap)
{
	int		n;
	size_t	h;
	va_list	cp;

	n = -1;
	while (n < 0 && ap)
	{
		va_copy(cp, ap);
		n = va_arg(cp, int);
		h = va_arg(ap, size_t);
	}
	va_end(cp);
	if (!h)
	{
		ft_putstr("(nil)");
		return (0);
	}
	return (h);
}

void	ft_process_p(va_list ap, t_flags arg)
{
	size_t	h;
	int		len;
	int		n;

	len = 0;
	h = ft_check_p(ap);
	if (!h)
		return ;
	if (arg.min)
	{
		len = arg.min - ft_baselen(h, 16) - 2;
		if (len > 0)
		{
			n = len;
			if (arg.minus)
				ft_print_p(h);
			while (n--)
				ft_putchar(' ');
		}
	}
	if (!arg.min || (arg.min && len > 0 && !arg.minus) || \
		(arg.min && len <= 0))
		ft_print_p(h);
}

void	ft_process_x(va_list ap, t_flags arg)
{
	size_t	h;
	int		zero;

	h = va_arg(ap, size_t);

	zero = ft_count_zero(arg, ft_baselen(h, 16));
	if (arg.minus)
	{
		ft_print_zero(zero);
		if (!(arg.dot && arg.max == 0))
			ft_print_hex(h, HEX_LOWER);
		ft_print_space(arg, zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, zero + ft_baselen(h, 16));
		ft_print_zero(zero);
		if (!(arg.dot && arg.max == 0))
			ft_print_hex(h, HEX_LOWER);
	}
}

void	ft_process_x2(va_list ap, t_flags arg)
{
	size_t	h;
	int		zero;

	h = va_arg(ap, size_t);

	zero = ft_count_zero(arg, ft_baselen(h, 16));
	if (arg.minus)
	{
		ft_print_zero(zero);
		if (!(arg.dot && arg.max == 0))
			ft_print_hex(h, HEX_UPPER);
		ft_print_space(arg, zero + ft_baselen(h, 16));
	}
	else
	{
		ft_print_space(arg, zero + ft_baselen(h, 16));
		ft_print_zero(zero);
		if (!(arg.dot && arg.max == 0))
			ft_print_hex(h, HEX_UPPER);
	}
}

void	ft_process_per(void)
{
	ft_putchar('%');
}
