/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/02 02:26:23 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_process_c(va_list ap, t_flags *arg)
{
	int	c;

	c = va_arg(ap, int);
	if (arg->minus)
		ft_putchar(c);
	ft_print_space(arg, 1);
	if (!arg->min || (arg->min && !arg->minus))
		ft_putchar(c);
	arg->res++;
}

void	ft_process_s(va_list ap, t_flags *arg)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		if ((arg->dot && arg->max >= 6) || (!arg->dot && !arg->max) || arg->max < 0)
			s = NULL_S;
		else if (arg->max < 6)
			s = "";
	}
	if (arg->max < 0)
		arg->max = ft_strlen(s);
	if (arg->minus && arg->min)
		ft_putnstr(arg, s, arg->max);
	if (arg->minus && !arg->dot && !arg->max)
		ft_putstr_res(arg, s);
	if (arg->min)
		ft_print_space(arg, ft_strlen(s));
	if (!arg->minus && arg->dot && arg->min)
		ft_putnstr(arg, s, arg->max);
	if (!arg->minus && !arg->dot && !arg->max)
		ft_putstr_res(arg, s);
	if (!arg->min && arg->dot && arg->max)
		ft_putnstr(arg, s, arg->max);
}

void	ft_print_di_l(t_flags *arg, int n, long l)
{
	if (n == INT_MIN)
	{
		ft_putnbr_res(arg, INT_MAX + 1L);
	}
	else
		ft_putnbr_res(arg, l);
}

void	ft_process_di(va_list ap, t_flags *arg)
{
	int		n;
	long	l;

	l = 0;
	n = va_arg(ap, int);
	if (n < 0)
		l = -n;
	if (l)
		ft_process_neg_nbr(arg, n, l);
	else
		ft_process_pos_nbr(arg, n);
}

void    ft_print_u(t_flags *arg, unsigned int nb)
{
	if (nb >= 10)
			ft_print_u(arg, nb / 10);
	ft_putchar(nb % 10 + '0');
	arg->res++;
}

void	ft_process_pos_nbr_u(t_flags *arg, long n)
{
	int	zero;

	if (n != 0 && arg->dot && !arg->max)
		arg->dot = 0;
	zero = ft_count_zero(arg, ft_nbrlen(n));
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_u(arg, n);
		ft_print_space(arg, zero + ft_nbrlen(n));
	}
	else
	{
		ft_print_space(arg, zero + ft_nbrlen(n));
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_u(arg, n);
	}
}

void	ft_process_pos_nbr_umax(t_flags *arg)
{
	int	zero;

	zero = ft_count_zero(arg, 10);
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_putnbr_res(arg, UINT_MAX);
		ft_print_space(arg, zero + 10);
	}
	else
	{
		ft_print_space(arg, zero + 10);
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_putnbr_res(arg, UINT_MAX);
	}
}

void	ft_process_u(va_list ap, t_flags *arg)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	if (u == UINT_MAX)
		ft_process_pos_nbr_umax(arg);
	else
		ft_process_pos_nbr_u(arg, u);
}
