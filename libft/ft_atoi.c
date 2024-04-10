/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:54:08 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 16:17:15 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || \
		c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			minus;
	long int	number;

	i = 0;
	minus = 1;
	number = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		minus = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		if (number < 0 && minus == -1 && number)
			return (0);
		if (number < 0 && minus == 1)
			return (-1);
		i++;
	}
	return (number * minus);
}

//while isspace returns 1 we iterate i. isspace checks for whitespaces.
//while the current postion of the string is '-' or '+' we iterate i.
//If its a '-' we count how often they are in the string.
//while the Character at the current position of the string
//is between 0 and 9,
//we convert them into their Int value.
//If the number of minus is odd we multiplicate by -1.
//At the end we return the the number as an int value.

/*int	main(void)
{
	const char test1[15] = " +-+--42AB420ab";
	printf("Test1 before ft_atoi: %s\n", test1);
	printf("Test1 after ft_atoi: %d\n", ft_atoi(test1));
	printf("Test1 after atoi: %d\n", atoi(test1));
	const char test2[15] = "		-42AB420ab";
	printf("Test2 before ft_atoi: %s\n", test2);
	printf("Test2 after ft_atoi: %d\n", ft_atoi(test2));
	printf("Test2 after atoi: %d\n", atoi(test2));
}*/
