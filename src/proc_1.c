/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/19 14:23:32 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_process_c(va_list ap, t_flags arg)
{
	int	c;
	int	len;
	int	n;

	len = 0;
	c = va_arg(ap, int);
	if (arg.min)
	{
		len = arg.min - 1;
		if (len > 0)
		{
			n = len;
			if (arg.minus)
				ft_putchar(c);
			while (n--)
				ft_putchar(' ');
		}
	}
	if (!arg.min || (arg.min && len > 0 && !arg.minus) || \
		(arg.min && len <= 0))
		ft_putchar(c);
}

void	ft_process_s(va_list ap, t_flags arg)
{
	char	*s;
	int		len;
	int		n;

	len = 0;
	s = va_arg(ap, char *);
	if (arg.dot && !arg.width)
		return ;
	if (!arg.dot && arg.width)
	{
		len = arg.width - ft_strlen(s);
		if (len > 0)
		{
			n = len;
			if (arg.minus)
				ft_putstr(s);
			while (n--)
				ft_putchar(' ');
		}
	}
	if (arg.dot && arg.width)
		ft_putnstr(s, arg.width);
	else if (!arg.width || (arg.width && len > 0 && !arg.minus) || \
			(arg.width && len <= 0))
		ft_putstr(s);
}

void	ft_process_p(va_list ap, t_flags arg)
{
	va_list	cp;
	size_t	h;
	int		len;
	int		n;

	len = 0;
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
		return ;
	}
	if (arg.width)
	{
		len = arg.width - ft_baselen(h, 16) - 2;
		if (len > 0)
		{
			n = len;
			if (arg.minus)
				ft_print_p(h);
			while (n--)
				ft_putchar(' ');
		}
	}
	if (!arg.width || (arg.width && len > 0 && !arg.minus) || \
		(arg.width && len <= 0))
		ft_print_p(h);
}

void	ft_process_di(va_list ap, t_flags arg)
{
	int		n;
	long	l;
	int		c;
	int		len;
	char	*s;

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
				s = ft_ltoa(INT_MAX + 1L);
				ft_putstr(s);
				if (s)
					free(s);
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
	int				c;
	int				len;

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
