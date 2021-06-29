/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_of_pointers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:23:09 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/06/27 01:20:25 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array_of_pointers(char **array_of_pointers, size_t arr_size)
{
	size_t	pointer;

	pointer = 0;
	while (pointer < arr_size)
	{
		free(array_of_pointers[pointer]);
		++pointer;
	}
	free(array_of_pointers);
	array_of_pointers = NULL;
}
