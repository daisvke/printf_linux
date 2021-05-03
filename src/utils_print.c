/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/03 04:17:46 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_redirect_sp(va_list ap, t_flags *arg)	
{
	if (arg->sp == 'c')
		ft_process_c(ap, arg);
	else if (arg->sp == 's')
		ft_process_s(ap, arg);
	else if (arg->sp == 'p')
		ft_process_p(ap, arg);
	else if (arg->sp == 'd' || arg->sp == 'i')
		ft_process_di(ap, arg);
	else if (arg->sp == 'u')
		ft_process_u(ap, arg);
	else if (arg->sp == 'x')
		ft_process_x(ap, arg);
	else if (arg->sp == 'X')
		ft_process_x2(ap, arg);
	else if (arg->sp == '%')
		ft_process_per(arg);
}

int	ft_set_flags(t_flags *arg, char *s, va_list ap)
{
	arg->len = 1;
	s++;
	arg->s = s;
	ft_read_zero_minus(arg);
	ft_read_whitespace(arg);
	if (!ft_read_wc(arg, ap) || !ft_read_nbr(arg) || \
		!ft_read_dot(arg) || !ft_read_wc(arg, ap) || \
		!ft_read_nbr(arg) || !ft_read_sp(arg))
		ft_init_arg(arg);
	return (arg->res);
}

void	ft_putchar_res(t_flags *arg, char c)
{
	ft_putchar(c);
	arg->res++;
}

void	ft_read_fmt(t_flags *arg, va_list ap, char *s)
{
	arg->res = 0;
	while (*s)
	{
		ft_init_arg(arg);
		if (*s == '%')
		{
			ft_set_flags(arg, s, ap);
			if (arg->sp)
			{
				ft_redirect_sp(ap, arg);
				s += arg->len;
			}
			else
				ft_putchar_res(arg, *s++);
		}
		else
			ft_putchar_res(arg, *s++);
	}
}
