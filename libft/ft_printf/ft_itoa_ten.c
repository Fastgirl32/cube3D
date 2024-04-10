/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:18:15 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 13:16:04 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	whatis_index(unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (n != 0)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

char	*ft_itoa_ten(unsigned int n)
{
	int		index;
	char	*rv;

	index = whatis_index(n);
	rv = ft_calloc(sizeof(char), (index + 1));
	if (rv == NULL)
		return (NULL);
	while (n != 0)
	{
		rv[index - 1] = n % 10 + 48;
		n = n / 10;
		index--;
	}
	return (rv);
}
/* ft_itoa_ten converts the argument given as parameter into a string.
Allocated memory for that string and returns it.
*/
