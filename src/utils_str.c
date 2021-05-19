/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:42:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/03 20:03:14 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putstr_res(t_flags *arg, char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, &*str++, 1);
			arg->res++;
		}
	}
}

void	ft_putnstr(t_flags *arg, char *s, int n)
{
	while (*s && n--)
	{
		ft_putchar(*s++);
		arg->res++;
	}
}

void	ft_putnchar(t_flags *arg, int c, size_t n)
{
	arg->res += n;
	while (n--)
		ft_putchar(c);
}
