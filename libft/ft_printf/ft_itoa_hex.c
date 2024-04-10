/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:32:47 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 13:25:53 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	whatis_index(unsigned long long n)
{
	long	index;

	index = 1;
	while (n >= 16)
	{
		n = n / 16;
		index++;
	}
	return (index);
}

char	*ft_itoa_hex(unsigned long long n)
{
	char				*number;
	unsigned long long	index;

	index = whatis_index(n);
	number = ft_calloc(sizeof(char), (index + 1));
	if (number == NULL)
		return (NULL);
	while (index--)
	{
		number[index] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	return (number);
}

/*int	main(void)
{
	long	test1;

	test1 = 4242;
	printf("this is the long: %d\n", test1);
	printf("this is the long converted to the String in hexadecimal: %s\n\n",
			ft_itoa_hex(test1));
}*/
/* ft_itoa_hex converts the parameter given as argument to string we allocated
memory for, to its hexadecimal value and returns that string.
*/
