/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/17 03:13:22 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_process_x(va_list ap, t_flags arg)
{
	size_t	h;
	int		c;
	int		len;

	if (arg.dot && arg.star && !arg.width)
	{
		arg.width = va_arg(ap, int);
		arg.zero = true;
	}
	h = va_arg(ap, size_t);
	if (arg.width)
	{
		if (arg.zero)
			c = '0';
		else
			c = ' ';
		len = arg.width - ft_baselen(h, 16);
		if (len > 0)
		{
			if (arg.minus)
				ft_print_hex(h, HEX_LOWER);
			while (len--)
				ft_putchar(c);
		}
	}
	if (!arg.width || !arg.minus)
		ft_print_hex(h, HEX_LOWER);
}

void	ft_process_x2(va_list ap, t_flags arg)
{
	size_t	h;
	int		c;
	int		len;

	if (arg.dot && arg.star && !arg.width)
	{
		arg.width = va_arg(ap, int);
		arg.zero = true;
	}
	h = va_arg(ap, size_t);
	if (arg.width)
	{
		if (arg.zero)
			c = '0';
		else
			c = ' ';
		len = arg.width - ft_baselen(h, 16);
		if (len > 0)
		{
			if (arg.minus)
				ft_print_hex(h, HEX_UPPER);
			while (len--)
				ft_putchar(c);
		}
	}
	if (!arg.width || !arg.minus)
		ft_print_hex(h, HEX_UPPER);
}

void	ft_process_per(void)
{
	ft_putchar('%');
}

