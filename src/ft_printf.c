/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 00:00:40 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/16 04:09:58 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../inc/ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*s;
	
	if (!*fmt)
		return (-1);
	s = ft_strdup(fmt);
	va_start(ap, fmt);
	ft_read_fmt(ap, s);//ret nb of char printed
	va_end(ap);
	return (0);
}

#include <stdio.h>

int	main()
{
	int		n = -10063;
	int 	n2 = -2147483648;

//	float	f = -340282346638528859811704183484516925440.0000000000000000;
	char	c = 'F';
	char	s[] = "abcdefghijklmnopqtstuvwxyz";
	void	*p = 0;
	void	*p2 = &p;
//	unsigned int	n3 = 4294967295;

	printf("true xX:\t%x %X\n", n, n);
	ft_printf("my xX:\t\t%x %X\n", n, n);

	printf("true u:\t%u\n", n);
	ft_printf("my u:\t%u\n", n);

	printf("true int max:\t%d\n", n2);
	ft_printf("my int max:\t%d\n", n2);

	printf("true perc:\t%%\n");
	ft_printf("my perc:\t%%\n");

	printf("true p:\t%p\n", p);
	ft_printf("my p:\t%p\n", p);
	printf("true p:\t|%-43p|\n", p2);
	ft_printf("my p:\t|%-43p|\n", p2, p2, p2);

	printf("true c:\t|%-6c|\n", c);
	ft_printf("my c:\t|%-6c|\n", c);

	printf("true s:\t|%.*s|\n", 20, s);
	ft_printf("my s:\t|%.*s|\n", 20, s);

	printf("true:\tabcde%.dfghik\n", n);
	ft_printf("my:\tabcde%.dfghik\n", n);
//	ft_putfloat(-12.456);
	return (0);
}
