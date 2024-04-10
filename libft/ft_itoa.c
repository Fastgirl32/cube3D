/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:45:22 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 16:13:29 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// index is always atleast 1 can't get less than one digit.. makes sense right?
static int	whatis_index(int n)
{
	int	index;

	index = 0;
	while (n)
	{
		n = n / 10;
		index ++;
	}
	return (index);
}

static char	*ft_iszero(void)
{
	char	*number;

	number = malloc(2);
	number[0] = '0';
	number[1] = '\0';
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		index;
	long	nbr;

	nbr = n;
	index = whatis_index(n);
	if (n == 0)
		return (ft_iszero ());
	if (n < 0)
	{
		nbr = -nbr;
		index ++;
	}
	number = malloc((index + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[index] = '\0';
	while (index-- && nbr > 0)
	{
		number[index] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	if (nbr == 0 && index == 0)
		number[index] = 45;
	return (number);
}

/*int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = 4242;
	printf("this is the Integer: %d\n", test1);
	printf("this is the Integer converted to the String: %s\n\n",
			ft_itoa(test1));
	test2 = -4242;
	printf("this is the Integer: %d\n", test2);
	printf("this is the Integer converted to the String: %s\n\n",
			ft_itoa(test2));
	test3 = -2147483648;
	printf("this is the Integer: %d\n", test3);
	printf("this is the Integer converted to the String: %s\n\n",
			ft_itoa(test3));
	test4 = 2147483647;
	printf("this is the Integer: %d\n", test4);
	printf("this is the Integer converted to the String: %s\n", ft_itoa(test4));
}*/
