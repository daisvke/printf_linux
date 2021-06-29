/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:07:29 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/04/16 20:05:23 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_usebase(int nbr, char *base, int size)
{
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)size)
		ft_usebase(n / size, base, size);
	write(1, &base[n % size], 1);
}

static int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == base[i + 1] || base[i] == '-' \
			|| base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	if (ft_checkbase(base))
	{
		size = 0;
		while (base[size])
			size++;
		ft_usebase(nbr, base, size);
	}
}
