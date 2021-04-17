/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:00:40 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/17 03:18:43 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../inc/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*s;
	
	if (!fmt)
		return (ERROR);
	s = ft_strdup(fmt);
	va_start(ap, fmt);
	ft_read_fmt(ap, s);//ret nb of char printed
	va_end(ap);
	free(s);
	return (EMPTY_FMT);
}

// 
