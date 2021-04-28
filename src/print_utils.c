/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/29 00:29:10 by dtanigaw         ###   ########.fr       */
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
	/*	
				printf("\n\n=======================\n");
				printf("minus:\t%d\n", arg.minus);
				printf("zero:\t%d\n", arg.zero);
				printf("dot:\t%d\n", arg.dot);
				printf("min:\t%d\n", arg.min);
				printf("max:\t%d\n", arg.max);
				printf("wc:\t%d\n", arg.wc);
				printf("sp:\t%c\n", arg.sp);
				printf("len:\t%d\n", arg.len);
				printf("=======================\n\n");*/
				s += arg.len;
			}
			else
			{
				ft_putchar(*s);
				++s;
			}
		}
		else
		{
			ft_putchar(*s);
			++s;
		}
	}
}
