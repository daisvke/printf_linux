/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:41:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/03 20:17:54 by dtanigaw         ###   ########.fr       */
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
	ft_putchar(base[nb % 16]);
	arg->res++;
}

void	ft_print_oct(t_flags *arg, size_t nb)
{
	if (nb >= 8)
		ft_print_oct(arg, nb / 8);
	ft_putchar("012345678"[nb % 8]);
	arg->res++;
}

void	ft_print_p(t_flags *arg, size_t nb)
{
	if (!nb)
	{	
		ft_putstr("(nil)");
		arg->res += 5;
	}
	else
	{
		ft_putstr_res(arg, "0x");
		ft_print_hex(arg, nb, HEX_LOWER);
	}
}

int	ft_baselen(long l, int base)
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
