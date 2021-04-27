/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/27 05:05:55 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_zero(int len)
{
	if (len > 0)
		ft_putnchar('0', len);
}

int	ft_count_zero(t_flags arg, int len)
{
	int	zero;

	zero = 0;
	if (arg.max > len || arg.min > len)
	{
		if (arg.zero && arg.min && !arg.max)
			zero = arg.min - len ;
		else if ((arg.zero && arg.max) || (arg.dot && arg.max))
			zero = arg.max - len;
	}
	/*
	if (arg.max != len)
		maxlen = arg.max;
	if ((!arg.max && arg.zero) || arg.max == len)
		maxlen = len;
	if (!arg.max && arg.min != len)
		maxlen = 0;
	if (arg.dot)
		maxlen = arg.max - len; 
	if (maxlen > 0)
		minlen = arg.min - arg.max;
	else
		minlen = arg.min - len;
	if (nb < 0 && arg.minus)
		ft_putchar('-');
	if (minlen > 0 && !arg.minus && (!arg.zero || maxlen))
		ft_putnchar(' ', minlen);
	if (nb < 0 && !arg.minus)
		ft_putchar('-');*/
//	printf("max=====%d====\n", maxlen);
//	printf("min=====%d====\n", minlen);
/*
	if (maxlen > 0)
		ft_putnchar('0', maxlen);
	else if (minlen > 0 && !arg.max && arg.min > len && arg.zero)
		ft_putnchar('0', minlen);
	return (minlen);*/
	if (zero < 0)
		zero = 0;
	return (zero);
}

void	ft_print_space(t_flags arg, int len)
{
	int	space;
//	printf("=====%d====%d====\n\n", arg.min, len);

	if (arg.sp == 's')
	{
		if (arg.max > len)
			space =  arg.min - len;
		else
			space = arg.min - arg.max;
	}
	else 
	{
		if (arg.max > len)
			space = arg.min - arg.max;
		else
			space = arg.min - len;
	}
	if (!arg.max)
		space = arg.min - len;
	if (arg.dot && !arg.max)
		space = arg.min;
	if (space > 0)
		ft_putnchar(' ', space);

	//return (space);
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

void	ft_print_di_l(int n, long l)
{
	char	*s;

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

void	ft_process_di(va_list ap, t_flags arg)
{
	int		n;
	int		zero;
	long	l;

	l = 0;
	n = va_arg(ap, int);
	if (n < 0)
		l = -n;
	if (l)
	{
		if (arg.min)
			arg.min--;
		zero = ft_count_zero(arg, ft_intlen(l));
		if (arg.minus)
		{
			ft_putchar('-');
			ft_print_zero(zero);
			ft_print_di_l(n, l);
			ft_print_space(arg, zero + ft_intlen(l));
		}
		else
		{
			ft_print_space(arg, zero + ft_intlen(l));
			ft_putchar('-');
			ft_print_zero(zero);
			ft_print_di_l(n, l);
		}
	}
	else
	{	
		zero = ft_count_zero(arg, ft_intlen(n));
		if (arg.minus)
		{
			ft_print_zero(zero);
			if (!(arg.dot && arg.max == 0))
				ft_putnbr(n);
			ft_print_space(arg, zero + ft_intlen(n));
		}
		else
		{
			ft_print_space(arg, zero + ft_intlen(n));
			ft_print_zero(zero);
			if (!(arg.dot && arg.max == 0))
				ft_putnbr(n);
		}
	}
//	if (arg.minus && minlen > 0)
//		ft_putnchar(' ', minlen);
}

void	ft_process_u(va_list ap, t_flags arg)
{
	unsigned int	u;
	int				c;
	int				len;

	u = va_arg(ap, unsigned int);
	ft_print_space(arg, ft_intlen(u));
	ft_print_zero(ft_count_zero(arg, ft_intlen(u)));
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
