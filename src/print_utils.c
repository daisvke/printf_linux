/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/19 16:13:35 by dtanigaw         ###   ########.fr       */
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

void	ft_read_minus(t_flags *arg)
{
	while (*(arg->s) == '-')
	{
		arg->minus = true;
		arg->len++;
		arg->s++;
	}
}

bool	ft_read_dot(t_flags *arg)
{
	if (*(arg->s) == '.' && *(arg->s + 1) != '.')
	{
		arg->dot = true;
		arg->len++;
		arg->s++;
	}
	else if (*(arg->s) == '.' && *(arg->s + 1) == '.')
	{
		ft_bzero(&arg, sizeof(arg));
		return (0);
	}
	return (1);
}

void	ft_read_nbr(t_flags *arg)
{
	if (*(arg->s) == '0' && !ft_isdigit(*(arg->s - 1)))
		arg.zero = true;
	n = 0;
	while (ft_isdigit(*s))
	{
		if (arg.star)
			return (arg);
		n *= 10;
		n += *s - '0';
		arg->len++;
		arg->s++;
	}
	arg.width = n;
}

t_flags	ft_set_flags(char *s)
{
	int		n;
	int		i;
	t_flags	arg;

	ft_bzero(arg, sizeof(arg));
	i = 1;
	arg.s = s++;
	ft_read_minus(&arg);
	if (!ft_read_dot(&arg))
		return (arg);
	if (*s == '*')
	{
		arg.star = true;
		i++;
		s++;
	}
	ft_read_nbr(arg);
	if (ft_strchr(SP_LIST, *s))
	{
		arg.sp = *s;
		i++;
	}
	else
	{
		ft_bzero(&arg, sizeof(arg));
		return (arg);
	}
	arg.len = i;
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
			arg = ft_set_flags(s);
			if (arg.sp)
			{/*
				printf("\n\n=======================\n");
				printf("minus:\t%d\n", arg.minus);
				printf("zero:\t%d\n", arg.zero);
				printf("dot:\t%d\n", arg.dot);
				printf("w:\t%d\n", arg.width);
				printf("sp:\t%c\n", arg.sp);
				printf("len:\t%d\n", arg.len);
				printf("=======================\n\n");*/
				ft_redirect_sp(ap, arg);
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
