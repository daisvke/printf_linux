/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/16 04:07:37 by dtanigaw         ###   ########.fr       */
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
	int		n;

	n = 0;
	if (arg.dot && arg.star && !arg.width)
		n = va_arg(ap, int);
	s = va_arg(ap, char *);
	if (arg.dot && arg.star && !arg.width)
		ft_putnstr(s, n);
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
	{
		printf("=======%s========\n", s);
		ft_putstr(s);
	}
//	if (!arg.width || !arg.dot || !arg.minus || arg.star)
//		ft_putstr(s);
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
				ft_print_hex(h, "0123456789abcdef");
			}
			while (len--)
				ft_putchar(' ');
		}
	}
	if (!arg.width || !arg.minus)
	{
		ft_putstr("0x");
		ft_print_hex(h, "0123456789abcdef");
	}
}

void	ft_process_di(va_list ap)
{
	int	n;

	n = va_arg(ap, int);	
	ft_putnbr(n);
}

void	ft_process_u(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_print_u(u);
}
