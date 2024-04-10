/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:53:55 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/06 11:03:42 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
		return (c);
	}
	return (c);
}

/*int	main(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;
	test1 = 97;
	test2 = 122;
	test3 = 65;
	test4 = 90;
	printf("This is test1 before ft_tolower :%d\n", test1);
	printf("This is test1 after ft_tolower :%d\n", ft_tolower(test1));
	printf("This is test2 before ft_tolower :%d\n", test2);
	printf("This is test2 after ft_tolower :%d\n", ft_tolower(test2));
	printf("This is test3 before ft_tolower :%d\n", test3);
	printf("This is test3 after ft_tolower :%d\n", ft_tolower(test3));
	printf("This is test4 before ft_tolower :%d\n", test4);
	printf("This is test4 after ft_tolower :%d\n", ft_tolower(test4));
	printf("This is test1 before tolower :%d\n", test1);
	printf("This is test1 after tolower :%d\n", tolower(test1));
	printf("This is test2 before tolower :%d\n", test2);
	printf("This is test2 after tolower :%d\n", tolower(test2));
	printf("This is test3 before tolower :%d\n", test3);
	printf("This is test3 after tolower :%d\n", tolower(test3));
	printf("This is test4 before tolower :%d\n", test4);
	printf("This is test4 after tolower :%d\n", tolower(test4));

}*/
