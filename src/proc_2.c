/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:01:27 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/16 04:03:15 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_process_x(va_list ap)
{
	size_t	h;

	h = va_arg(ap, size_t);
	ft_print_hex(h, "0123456789abcdef");
}

void	ft_process_x2(va_list ap)
{
	size_t	h;

	h = va_arg(ap, size_t);
	ft_print_hex(h, "0123456789ABCDEF");
}

void	ft_process_per(void)
{
	ft_putchar('%');
}

