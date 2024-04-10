/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:21:41 by phnowak           #+#    #+#             */
/*   Updated: 2023/09/20 20:17:44 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (*dest == '\0' && *src == '\0')
		return (0);
	while (src[len])
		len++;
	if (n != 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

/*int	main(void)
{
	char	testsrc[7] = "Gabriel";
	char	testdest[100];
	printf("this is testdest before ft_strlcpy: %s \n", testdest);
	ft_strlcpy(testdest, testsrc, 8);	
	printf("this is testdest after ft_strlcpy: %s \n", testdest);
	char	testsrc2[7] = "Gabriel";
	char	testdest2[100];
	printf("this is testdest2 before strlcpy: %s \n", testdest);
	strlcpy(testdest2, testsrc2, 3);
	printf("this is testdest2 after strlcpy: %s \n", testdest);
}*/
