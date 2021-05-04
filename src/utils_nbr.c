/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:41:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/04 02:24:07 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

void	ft_print_hex(t_flags *arg, size_t nb, char *base)
{
	if (nb >= 16)
		ft_print_hex(arg, nb / 16, base);
	ft_putnchar(arg, base[nb % 16], 1);
}

void	ft_print_oct(t_flags *arg, unsigned int nb)
{
	if (nb >= 8)
		ft_print_oct(arg, nb / 8);
	ft_putnchar(arg, "012345678"[nb % 8], 1);
}

void	ft_print_p(t_flags *arg, size_t nb)
{
	if (!nb)
		ft_putstr_res(arg, "(nil)");
	else
	{
		ft_putstr_res(arg, "0x");
		ft_print_hex(arg, nb, HEX_LOWER);
	}
}

int	ft_baselen(size_t l, size_t base)
{
	int	len;

	len = 0;
	while (l >= base)
	{
		l /= base;
		++len;
	}
	++len;
	return (len);
}
