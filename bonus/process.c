/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:29:59 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/05/23 22:38:18 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

bool	ft_process_n(va_list ap, t_flags *arg)
{
	int	*n;

	n = va_arg(ap, void *);
	*n = arg->res;
	return (true);
}
