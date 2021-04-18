/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:41:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/18 02:12:05 by dtanigaw         ###   ########.fr       */
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

char	*ft_ltoa(long n)
{
	char	*res;
	int		len;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	res[len] = 0;
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		res[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
