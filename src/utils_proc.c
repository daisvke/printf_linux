/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:03:40 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/04 02:48:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_zero(t_flags *arg, int len)
{
	if (len > 0)
		ft_putnchar(arg, '0', len);
}

int	ft_count_zero(t_flags *arg, int len)
{
	int	zero;

	zero = 0;
	if (arg->max > len || arg->min > len)
	{
		if (arg->zero && arg->min && !arg->max)
			zero = arg->min - len ;
		else if ((arg->zero && arg->max) || (arg->dot && arg->max))
			zero = arg->max - len;
	}
	if (arg->max < 0 && arg->zero)
		zero = arg->min - len;
	if (zero < 0)
		zero = 0;
	return (zero);
}

void	ft_print_space(t_flags *arg, int len)
{
	int	space;

	if (arg->sp == 's')
	{
		if (arg->max > len)
			space =  arg->min - len;
		else
			space = arg->min - arg->max;
	}
	else 
	{
		if (arg->sp != 'c' && arg->max > len)
			space = arg->min - arg->max;
		else
			space = arg->min - len;
	}
	if (!arg->max)
		space = arg->min - len;
	if (arg->dot && !arg->max)
		space = arg->min;
	if (space > 0)
		ft_putnchar(arg, ' ', space);
}

void	ft_process_pos_nbr(t_flags *arg, long n)
{
	int	zero;

	ft_check_arg(arg, n);
	zero = ft_count_zero(arg, ft_nbrlen(n));
	if (arg->minus)
	{
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_putnbr_res(arg, n);
		ft_print_space(arg, zero + ft_nbrlen(n));
	}
	else
	{
		ft_print_space(arg, zero + ft_nbrlen(n));
		ft_print_zero(arg, zero);
		if (!(arg->dot && arg->max == 0))
			ft_putnbr_res(arg, n);
	}
}

void	ft_process_neg_nbr(t_flags *arg, int n, long l)
{
	int	zero;

	ft_check_arg(arg, 1);
	if (arg->min && n != INT_MIN)
		arg->min--;
	zero = ft_count_zero(arg, ft_nbrlen(l));
	if (arg->minus)
	{
		ft_putnchar(arg, '-', 1);
		ft_print_zero(arg, zero);
		ft_print_di_l(arg, n, l);
		ft_print_space(arg, zero + ft_nbrlen(l));
	}
	else
	{
		ft_print_space(arg, zero + ft_nbrlen(l));
		ft_putnchar(arg, '-', 1);
		ft_print_zero(arg, zero);
		ft_print_di_l(arg, n, l);
	}
}
