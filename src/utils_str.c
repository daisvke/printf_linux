/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:42:22 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/25 03:01:41 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putnstr(char *s, int n)
{
	while (*s && n--)
		ft_putchar(*s++);
}

void	ft_putnchar(int c, size_t n)
{
	while (n--)
		ft_putchar(c);
}
