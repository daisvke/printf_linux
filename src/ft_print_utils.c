/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:20:33 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/16 04:04:51 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_hex(size_t nb, char *base)
{
	if (nb >= 16)
		ft_print_hex(nb / 16, base);
	ft_putchar(base[nb % 16]);
}

void	ft_print_u(unsigned int nb)
{
	if (nb >= 10)
		ft_print_u(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_baselen(long l, int base)
{
	int len;

	len = 0;
	while (l >= base)
	{
		l /= base;
		++len;
	}
	++len;
	return (len);
}

void	ft_putnstr(char *s, int n)
{
	while (*s && n--)
		ft_putchar(*s++);
}

void	ft_redirect_sp(va_list ap, t_flags arg)	
{
	if (arg.sp == 'c')
		ft_process_c(ap, arg);
	else if (arg.sp == 's')
		ft_process_s(ap, arg);
	else if (arg.sp == 'p')
		ft_process_p(ap, arg);
	else if (arg.sp == 'd' || arg.sp == 'i')
		ft_process_di(ap);
	else if (arg.sp == 'u')
		ft_process_u(ap);
	else if (arg.sp == 'x')
		ft_process_x(ap); 
	else if (arg.sp == 'X')
		ft_process_x2(ap);
	else if (arg.sp == '%')
		ft_process_per();
}

t_flags	ft_set_flags(char *s)
{
	int		n;
	int		i;
	t_flags	arg;

	ft_bzero(&arg, sizeof(arg));
	i = 1;
	s++;
	while (*s == '-')
	{
		arg.minus = true;
		i++;
		s++;
	}
	while (*s == '0')
	{
		if (!arg.minus)
			arg.zero = true;
		i++;
		s++;
	}
	if (*s == '.' && *(s + 1) != '.')
	{
		arg.dot = true;
		i++;
		s++;
	}
	else if (*s == '.' && *(s + 1) == '.')
	{
		ft_bzero(&arg, sizeof(arg));
		return (arg);
	}
	if (*s == '*')
	{
		arg.star = true;
		i++;
		s++;
	}
	n = 0;
	while (ft_isdigit(*s))
	{
		if (arg.star)
			return (arg);
		n *= 10;
		n += *s - '0';
		i++;
		s++;
	}
	arg.width = n;
	if (*s == 'c' || *s == 's' || *s == 'p' || \
		*s == 'd' || *s == 'i' || *s == 'u' || \
		*s == 'x' || *s == 'X' || *s == '%')
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
