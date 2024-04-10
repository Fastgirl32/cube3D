/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:08:23 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 17:46:09 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	while ((p_s1[i] != '\0' || p_s2[i] != '\0') && i < n)
	{
		if (p_s1[i] > p_s2[i])
			return (p_s1[i] - p_s2[i]);
		else if (p_s1[i] < p_s2[i])
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	origin1[10] = "Gabriel";
	const char	tocompare1[10] = "Gabriel";
	printf("This is origin1: %s\n", origin1);
	printf("This is tocompare1: %s\n", tocompare1);
	printf("Are the strings the same with ft_strncmp? : %d\n",
			ft_strncmp(origin1, tocompare1, 10));
	printf("Are the strings the same with strncmp? : %d\n", strncmp(origin1,
				tocompare1, 10));
	const char	origin2[30] = "HelloWorld";
	const char	tocompare2[30] = "HelloKerbin";
	printf("This is origin2: %s\n", origin2);
	printf("This is tocompare2: %s\n", tocompare2);
	printf("Are the strings the same with ft_strncmp? : %d\n",
			ft_strncmp(origin2, tocompare2, 10));
	printf("Are the strings the same with strncmp? : %d\n", strncmp(origin2,
				tocompare2, 10));
	printf("Are the strings the same with ft_strncmp up to 5 bytes? : %d\n",
			ft_strncmp(origin2, tocompare2, 5));
	printf("Are the strings the same with strncmp up to 5 bytes? : %d\n",
			strncmp(origin2, tocompare2, 5));
	printf("Are the strings the same with ft_strncmp up to 7 bytes? : %d\n",
			ft_strncmp(origin2, tocompare2, 7));
	printf("Are the strings the same with strncmp up to 7 bytes? : %d\n",
			strncmp(origin2, tocompare2, 7));
}*/
