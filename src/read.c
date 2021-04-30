/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:08:07 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/30 03:13:10 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
		return (false);
	}
	return (true);
}

void	ft_read_zero(t_flags *arg)
{
	while (*(arg->s) == '0')
	{
		if (!arg->minus)
				arg->zero = true;
		arg->len++;
		arg->s++;
	}
}

bool	ft_read_nbr(t_flags *arg)
{
	int	n;

	n = 0;
	while (ft_isdigit(*(arg->s)))
	{
		n *= 10;
		n += *(arg->s) - '0';
		if (arg->dot)
			arg->max = n;
		else
			arg->min = n;
		arg->len++;
		arg->s++;
	}
	return (true);
}

bool	ft_read_wc(t_flags *arg, va_list ap)
{
	while (*(arg->s) == '*')
	{
		if (*(arg->s - 1) == '*')
			return (false);
		arg->wc = true;
		arg->len++;
		arg->s++;
		if (!arg->dot && arg->wc)
		{
			arg->min = va_arg(ap, int);
			if (arg->min < 0)
			{
				arg->minus = true;
				arg->zero = false;
				arg->min = -(arg->min);
			}

		}
		else if (arg->dot && arg->wc)
			arg->max = va_arg(ap, int);
	}
	return (true);
}

bool	ft_read_sp(t_flags *arg)
{
	if (ft_strchr(SP_LIST, *(arg->s)))
	{
		arg->sp = *(arg->s);
		arg->len++;
		arg->s++;
	}
	return (true);
}

void	ft_read_whitespace(t_flags *arg)
{
	while (*(arg->s) == ' ')
	{
		ft_putchar(' ');
		arg->len++;
		arg->s++;
	}
}
