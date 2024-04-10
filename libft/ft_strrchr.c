/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:04:16 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 13:38:57 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	test1[30] = "ABCDEFGHIJKLMNOAPQRSTUVWXYZ";
	int	i_test;
	i_test = 'A';
	printf("This is test 1 with ft_strchr :%s\n", ft_strrchr(test1, i_test));
	printf("This is test 1 with strchr :%s\n", strrchr(test1, i_test));
	printf("This is test 2 with ft_strchr :%s\n", ft_strrchr(test1, ' '));
	printf("This is test 2 with strchr :%s\n", strrchr(test1, ' '));
}*/
