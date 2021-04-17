/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/17 15:22:15 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_process_c(va_list ap, t_flags arg)
{
	int	c;
	int	len;

	c = va_arg(ap, int);
	if (arg.width)
	{
		len = arg.width - 1;
		if (len > 0)
		{
			if (arg.minus)
				ft_putchar(c);
			while (len--)
				ft_putchar(' ');
		}
	}
	if (!arg.width || !arg.minus)
		ft_putchar(c);
}

void	ft_process_s(va_list ap, t_flags arg)
{
	char	*s;
	int		len;

	if (arg.dot && arg.star && !arg.width)
		arg.width = va_arg(ap, int);
	s = va_arg(ap, char *);
	if (arg.dot && !arg.width)
		return ;
	if (!arg.dot && arg.width)
	{
		len = arg.width - ft_strlen(s);
		if (len > 0)
		{
			if (arg.minus)
				ft_putstr(s);
			while (len--)
				ft_putchar(' ');
		}
		if (!arg.minus)
			ft_putstr(s);
	}
	else if (arg.dot && arg.width)
		ft_putnstr(s, arg.width);
	else
		ft_putstr(s);
}

void	ft_process_p(va_list ap, t_flags arg)
{
	size_t	h;
	int		len;

	h = va_arg(ap, size_t);
	if (!h)
	{
		ft_putstr("(nil)");
		return ;
	}
	if (arg.width)
	{
		len = arg.width - ft_baselen(h, 16) - 2;
		if (len > 0)
		{
			if (arg.minus)
			{
				ft_putstr("0x");
				ft_print_hex(h, HEX_LOWER);
			}
			while (len--)
				ft_putchar(' ');
		}
	}
	if (!arg.width || !arg.minus)
	{
		ft_putstr("0x");
		ft_print_hex(h, HEX_LOWER);
	}
}

void	ft_process_di(va_list ap, t_flags arg)
{
	int		n;
	long	l;
	int		c;
	int		len;

	if (arg.dot && arg.star && !arg.width)
	{
		arg.width = va_arg(ap, int);
		arg.zero = true;
	}
	n = va_arg(ap, int);
	l = 0;
	if (arg.zero && n < 0)
		l = -n;
	if (arg.width)
	{
		if (l)
			ft_putchar('-');
		if (arg.zero)
			c = '0';
		else
			c = ' ';
		len = arg.width - ft_intlen(n);
		if (len > 0)
		{
			if (arg.minus)
				ft_putnbr(n);
			while (len--)
				ft_putchar(c);
		}
	}
	if (!arg.width || !arg.minus)
	{
		if (l)
		{
			if (n == INT_MIN)
			{
				ft_putstr(INT_MAX_PLUS_1);
				free(INT_MAX_PLUS_1);
			}
			else
				ft_putnbr(l);
		}
		else
			ft_putnbr(n);
	}
}

void	ft_process_u(va_list ap, t_flags arg)
{
	unsigned int	u;
	int		c;
	int		len;

	if (arg.dot && arg.star && !arg.width)
	{
		arg.width = va_arg(ap, int);
		arg.zero = true;
	}
	u = va_arg(ap, unsigned int);
	if (arg.width)
	{
		if (arg.zero)
			c = '0';
		else
			c = ' ';
		len = arg.width - ft_intlen(u);
		if (len > 0)
		{
			if (arg.minus)
				ft_print_u(u);
			while (len--)
				ft_putchar(c);
		}
	}
	if (!arg.width || !arg.minus)
		ft_print_u(u);
}
