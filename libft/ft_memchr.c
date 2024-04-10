/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:19:12 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/06 11:34:57 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pointer_s;
	unsigned char	cast_c;

	pointer_s = (unsigned char *)s;
	cast_c = (unsigned char)c;
	while (n != 0)
	{
		if (*pointer_s == cast_c)
			return (pointer_s);
		pointer_s++;
		n--;
	}
	return (NULL);
}
/* Both c and the bytes of the memory area
pointed to by s are interpreted as unsigned char.
The function scans the initial n bytes of the memory area
pointed to by s for the first instance of c.
Return pointer to matching byte or NULL. */

/*int	main(void)
{
	const char	test1[30] = "This is a test.";
	int	testint1 = 42;
	printf("The first Instance of testint1 in test1 if any, is : %p\n",
			ft_memchr(test1, testint1, 100));
	printf("The first Instance of testint1 in test1 if any, is : %p\n",
			memchr(test1, testint1, 100));
	printf("The first Instance of testint2 in test1 if any, is : %p\n",
			ft_memchr("ABCDE4FGH", 4, 100));
	printf("The first Instance of testint2 in test1 if any, is : %p\n",
			memchr("ABCDE4FGH", 4, 100));
	const char str[] = "http://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;

	ret = ft_memchr(str, ch, strlen(str));

	printf("String after |%c| is - |%s|\n", ch, ret);

	return(0);
}*/
