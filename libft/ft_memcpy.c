/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:16:34 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 13:57:42 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dest;
	size_t	i;

	c_src = (char *)src;
	c_dest = (char *)dest;
	i = 0;
	if (!c_src && !c_dest)
		return (NULL);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
// Typecasting | converting void pointers into char pointers.
// Copy the content of src[i] to dest[i].
// Leads to problems when source and destination adresses overlap,
// memcpy only copies data one by one from one location to anouther.
/*int	main(void)
{
	char test_src[10] = "Gabriel";
	char test_dest[10] = "*******";
	printf("test_src before ft_memcpy is: %s \n", test_src);
	printf("test_dest before ft_memcpy is: %s \n", test_dest);
	ft_memcpy(test_dest, test_src, 3);
	printf("test_dest after ft_memcpy is %s \n", test_dest);
	char test_src2[10] = "Gabriel";
	char test_dest2[10] = "*******";
	printf("test_src before memcpy is: %s \n", test_src2);
	printf("test_dest before memcpy is: %s \n", test_dest2);
	memcpy(test_dest2, test_src2, 3);
	printf("test_dest2 after memcpy is %s \n", test_dest2);
	char test_src3[] = "Start stop";	
	printf("test_src3 before ft_memcpy is: %s \n", test_src3);
	ft_memcpy(test_src3, test_src3 + 2, 3);
	printf("test_src3 after ft_memcpy is: %s \n", test_src3);
	char test_src4[] = "Start stop";	
	printf("test_src4 before memcpy is: %s \n", test_src4);
	memcpy(test_src4, test_src4 + 2, 3);
	printf("test_src4 after memcpy is: %s \n", test_src4);
}*/
