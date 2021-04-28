/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:03:40 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/28 23:47:41 by dtanigaw         ###   ########.fr       */
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
	if (zero < 0)
		zero = 0;
	return (zero);
}

void	ft_print_space(t_flags arg, int len)
{
	int	space;

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

void	ft_process_pos_nbr(t_flags arg, long n)
{
	int	zero;

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

void	ft_process_neg_nbr(t_flags arg, int n, long l)
{
	int	zero;

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
