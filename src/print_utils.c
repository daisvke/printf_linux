/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/30 03:40:30 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_redirect_sp(va_list ap, t_flags arg)	
{
	if (arg.sp == 'c')
		ft_process_c(ap, arg);
	else if (arg.sp == 's')
		ft_process_s(ap, arg);
	else if (arg.sp == 'p')
		ft_process_p(ap, arg);
	else if (arg.sp == 'd' || arg.sp == 'i')
		ft_process_di(ap, arg);
	else if (arg.sp == 'u')
		ft_process_u(ap, arg);
	else if (arg.sp == 'x')
		ft_process_x(ap, arg);
	else if (arg.sp == 'X')
		ft_process_x2(ap, arg);
	else if (arg.sp == '%')
		ft_process_per();
}

t_flags	ft_set_flags(char *s, va_list ap)
{
	t_flags	arg;

	ft_bzero(&arg, sizeof(arg));
	arg.len = 1;
	s++;
	arg.s = s;
	ft_read_zero(&arg);
	ft_read_minus(&arg);
	ft_read_zero(&arg);
	ft_read_whitespace(&arg);
	if (!ft_read_wc(&arg, ap) || !ft_read_nbr(&arg) || \
		!ft_read_dot(&arg) || !ft_read_wc(&arg, ap) || \
		!ft_read_nbr(&arg) || !ft_read_sp(&arg))
	{
		ft_bzero(&arg, sizeof(arg));
		return (arg);
	}
	return (arg);
}

void	ft_read_fmt(va_list ap, char *s)
{
	t_flags	arg;

	while (*s)
	{
		ft_bzero(&arg, sizeof(arg));
		if (*s == '%')
		{
			arg = ft_set_flags(s, ap);
			if (arg.sp)
			{
				ft_redirect_sp(ap, arg);
				s += arg.len;
			}
			else
				ft_putchar(*s++);
		}
		else
			ft_putchar(*s++);
	}
}
