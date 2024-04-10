/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <phnowak@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:09:42 by phnowak           #+#    #+#             */
/*   Updated: 2023/08/14 19:10:37 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
/*int	main(void)
{
	const char	test1[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int	i_test;
	i_test = ' ';
	printf("This is test 1 with ft_strchr :%s\n", ft_strchr(test1, i_test));
	printf("This is test 1 with strchr :%s\n", strchr(test1, i_test));
	printf("This is test 2 with ft_strchr :%s\n", ft_strchr(test1, 'P'));
	printf("This is test 2 with strchr :%s\n", strchr(test1, 'P'));
}*/
