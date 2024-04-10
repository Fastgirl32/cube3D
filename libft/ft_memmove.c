/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:06:48 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/11 17:46:43 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dest;
	size_t	i;

	c_src = (char *)src;
	c_dest = (char *)dest;
	i = n;
	if (c_dest == c_src)
		return (c_dest);
	if (c_src < c_dest)
	{
		while (i--)
			c_dest[i] = c_src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (c_dest);
}

/*int	main(void)
{
	char test_src[10] = "Gabriel";
	printf("test_src before ft_memmove is: %s \n", test_src);
	ft_memmove(test_src, test_src + 3, 4);
	printf("test_dest after ft_memmove is %s \n", test_src);
	char test_src2[10] = "Gabriel";
	printf("test_src2 before memmove is: %s \n", test_src2);
	memmove(test_src2, test_src2 + 3, 4);
	printf("test_src2 after memmove is %s \n", test_src2);
	char test_src3[] = "Start stop";
 	printf("test_src3 before ft_memmove is: %s \n", test_src3);
 	ft_memmove(test_src3 + 2, test_src3, 5);
 	printf("test_src3 after ft_memmove is: %s \n", test_src3);
 	char test_src4[] = "Start stop";
 	printf("test_src4 before memmove is: %s \n", test_src4);
	memmove(test_src4 + 2, test_src4, 5);
 	printf("test_src4 after memmove is: %s \n", test_src4);
 	char test_src5[] = "Start stop";
 	printf("test_src4 before memcpy is: %s \n", test_src4);
	memcpy(test_src4 + 2, test_src4, 5);
 	printf("test_src4 after memcpy is: %s \n", test_src4);
}*/
