/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:41:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/30 02:05:21 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_hex(size_t nb, char *base)
{
	if (nb >= 16)
		ft_print_hex(nb / 16, base);
	ft_putchar(base[nb % 16]);
}

void	ft_print_p(size_t nb)
{
	ft_putstr("0x");
	ft_print_hex(nb, HEX_LOWER);
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
/*
void	ft_ltoa(long n)
{
	int		len;
	long	tmp;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	if (nb < 0)
		nb = -nb;
	if (n < 0)
		ft_putchar('-');
	while (len--)
	{
		tmp = nb / (10^len);
		printf("======%ld=====\n", tmp);
		ft_putchar(tmp % 10 + '0');
	}
}*/

void	ft_ltoa(long n)
{
	int		len;
	int		len_tmp;
	long	digit;
	long	tmp;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	if (nb < 0)
		nb = -nb;
	if (n < 0)
		ft_putchar('-');
	len_tmp = len - 1;
	digit = 1;
	while (len_tmp--)
		digit *= 10; 
	while (len--)
	{
		tmp = nb / digit;
		digit /= 10;
		ft_putchar(tmp % 10 + '0');
	}
}
