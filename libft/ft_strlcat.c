/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:57:41 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/10 11:59:55 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*pointer_dest;
	const char	*pointer_src;
	size_t		n;
	size_t		dest_len;

	pointer_dest = dest;
	pointer_src = src;
	n = size;
	while (n-- && *pointer_dest != '\0')
		pointer_dest++;
	dest_len = pointer_dest - dest;
	n = size - dest_len;
	if (n == 0)
		return (dest_len + ft_strlen(pointer_src));
	while (*pointer_src != '\0')
	{
		if (n != 1)
		{
			*pointer_dest++ = *pointer_src;
			n--;
		}
		pointer_src++;
	}
	*pointer_dest = '\0';
	return (dest_len + (pointer_src - src));
}

/*int	main(void)
{
	char testdest[10] = "Hello ";
	char testsrc[6] = "World";
	printf("The Source is: %s\n", testsrc);
	printf("The Destination is: %s\n", testdest);
	printf("this is the return: %ld\n",(ft_strlcat(testdest, testsrc, 11)));
	printf("This is the appended string: %s\n", testdest);
}*/
