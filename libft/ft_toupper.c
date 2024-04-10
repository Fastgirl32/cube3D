/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:45:35 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/06 10:53:11 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
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
	printf("This is test1 before ft_toupper :%d\n", test1);
	printf("This is test1 after ft_toupper :%d\n", ft_toupper(test1));
	printf("This is test2 before ft_toupper :%d\n", test2);
	printf("This is test2 after ft_toupper :%d\n", ft_toupper(test2));
	printf("This is test3 before ft_toupper :%d\n", test3);
	printf("This is test3 after ft_toupper :%d\n", ft_toupper(test3));
	printf("This is test4 before ft_toupper :%d\n", test4);
	printf("This is test4 after ft_toupper :%d\n", ft_toupper(test4));
	printf("This is test1 before toupper :%d\n", test1);
	printf("This is test1 after toupper :%d\n", toupper(test1));
	printf("This is test2 before toupper :%d\n", test2);
	printf("This is test2 after toupper :%d\n", toupper(test2));
	printf("This is test3 before toupper :%d\n", test3);
	printf("This is test3 after toupper :%d\n", toupper(test3));
	printf("This is test4 before toupper :%d\n", test4);
	printf("This is test4 after toupper :%d\n", toupper(test4));

}*/
