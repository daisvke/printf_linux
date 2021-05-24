/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:41:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/24 22:21:23 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_numlen(t_flags *arg, long long int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_numlen(arg, n) + 1;
	}
	else
	{
		while (n > 0)
		{
			len += 1;
			n = n / 10;
		}
	}
	return (len);
}

void	ft_check_arg(t_flags *arg, long nb)
{
	if (arg->dot && !arg->max)
		arg->zero = false;
	if (nb != 0 && arg->dot && !arg->max)
		arg->dot = false;
}

void	ft_print_di_l(t_flags *arg, int n, long l)
{
	if (n == INT_MIN)
		ft_putnbr_res(arg, INT_MAX + 1L);
	else
		ft_putnbr_res(arg, l);
}

void	ft_putnbr_res(t_flags *arg, long long int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb > 9)
	{
		ft_putnbr_res(arg, nb / 10);
		ft_putnbr(nb % 10);
	}
	arg->res++;
}

void	ft_process_pos_nbr_u(t_flags *arg, long n)
{
	int	zero;

	ft_check_arg(arg, n);
	zero = ft_count_zero(arg, ft_numlen(arg, n));
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_u(arg, n);
		ft_print_space(arg, zero + ft_numlen(arg, n));
	}
	else
	{
		ft_print_space(arg, zero + ft_numlen(arg, n));
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_print_u(arg, n);
	}
}

void	ft_process_pos_nbr_umax(t_flags *arg)
{
	int	zero;

	ft_check_arg(arg, 1);
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
