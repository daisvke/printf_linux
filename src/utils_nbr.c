/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:41:20 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/16 19:49:48 by dtanigaw         ###   ########.fr       */
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
