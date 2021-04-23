/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/22 01:31:33 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_space_zero(t_flags arg, int len, long nb)
{
	int	minlen;
	int	maxlen;

	if (arg.max > len || arg.max < len)
		maxlen = arg.max;
	if ((!arg.max && arg.zero) || arg.max == len)
		maxlen = len;
	if (arg.dot && !arg.max && (arg.min < len || arg.min > len))
		maxlen = 0;
	if (arg.min && !arg.max && !arg.dot)
		maxlen = 0;
	if (arg.dot)
		maxlen = arg.max - len; 
	if (maxlen > 0)
		minlen = arg.min - arg.max;
	else
		minlen = arg.min - len;
//	printf("max=====%d====\n", maxlen);
//	printf("min=====%d====\n", minlen);
	if (!arg.zero && minlen > 0)
		while (minlen--)
			ft_putchar(' ');
	if (nb < 0 && !arg.minus)
		ft_putchar('-');
	if (maxlen > 0)
		while (maxlen--)
			ft_putchar('0');
	else if (minlen > 0 && !arg.max && arg.min && arg.zero)
		while (minlen--)
			ft_putchar('0');
}

void	ft_print_space(t_flags arg, size_t nb)
{
	int	minlen;
	int	maxlen;

	if (arg.max > (int)nb)
		maxlen = nb;
	if ((int)nb > arg.max)
		maxlen = arg.max;
	if (!arg.max || arg.max == (int)nb)
		maxlen = nb;
	if (arg.dot && !arg.max && (arg.min < (int)nb || arg.min > (int)nb))
		maxlen = 0;
	minlen = arg.min - maxlen;
	if (minlen > 0)
		while (minlen--)
			ft_putchar(' ');
}

void	ft_process_c(va_list ap, t_flags arg)
{
	int	c;

	c = va_arg(ap, int);
	if (arg.minus)
		ft_putchar(c);
	ft_print_space(arg, 1);
	if (!arg.min || (arg.min && !arg.minus))
		ft_putchar(c);
}

void	ft_process_s(va_list ap, t_flags arg)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		if ((arg.dot && arg.max >= 6) || (!arg.dot && !arg.max) || \
			arg.max < 0)
			s = ft_strdup("(null)"); 
		else if (arg.max < 6)
			s = "";
	}
	if (arg.minus && arg.min)
		ft_putnstr(s, arg.max);
	if (arg.minus && !arg.dot && !arg.max)
		ft_putstr(s);
	if (arg.min)
		ft_print_space(arg, ft_strlen(s));
	if (!arg.minus && arg.dot && arg.min)
		ft_putnstr(s, arg.max);
	if (!arg.minus && !arg.dot && !arg.max)
		ft_putstr(s);
	if (!arg.min && arg.dot && arg.max)
		ft_putnstr(s, arg.max);
}

void	ft_print_di_l(t_flags arg, int n, long l)
{
	char	*s;

	if (!arg.min || !arg.minus)
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
}

void	ft_process_di(va_list ap, t_flags arg)
{
	int		n;
	long	l;

	l = 0;
	n = va_arg(ap, int);
	if ((arg.zero || !arg.minus) && n < 0)
		l = -n;
	if (l)
	{
		if (arg.min)
			arg.min--;
		if (arg.minus)
		{
			ft_putchar('-');
			ft_print_space_zero(arg, ft_intlen(l), n);
			ft_print_di_l(arg, n, l);
		}
		else
			ft_print_space_zero(arg, ft_intlen(l), n);
		if (!arg.minus)
		{
			ft_print_di_l(arg, n, l);
		}
	}
	else
	{	
		if (arg.minus)
		{
			ft_print_space_zero(arg, ft_intlen(n), n);
			ft_putnbr(n);
		}
		else
			ft_print_space_zero(arg, ft_intlen(n), n);
		if (!arg.minus)
			ft_putnbr(n);
	}
}

void	ft_process_u(va_list ap, t_flags arg)
{
	unsigned int	u;
	int				c;
	int				len;

	u = va_arg(ap, unsigned int);
	ft_print_space_zero(arg, ft_intlen(u), u);
	if (arg.min)
	{
		if (arg.zero)
			c = '0';
		else
			c = ' ';
		len = arg.min - ft_intlen(u);
		if (len > 0)
		{
			if (arg.minus)
				ft_print_u(u);
			while (len--)
				ft_putchar(c);
		}
	}
	if (!arg.min || !arg.minus)
		ft_print_u(u);
}
