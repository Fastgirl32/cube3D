/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:27:23 by phnowak           #+#    #+#             */
/*   Updated: 2023/02/20 23:50:42 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	free(s1);
	return (p);
}
/*int	main(void)
{
	const char	prefix[7] = "Hello ";
	const char	suffix[6] = "World";
	printf("This is the prefix: %s\n", prefix);
	printf("This is the suffix: %s\n", suffix);
	printf("this is the new string: %s\n", ft_strjoin(prefix, suffix));
	const char	prefix1[7] = "";
	const char	suffix1[6] = "World";
	printf("This is the prefix: %s\n", prefix1);
	printf("This is the suffix: %s\n", suffix1);
	printf("this is the new string: %s\n", ft_strjoin(prefix1, suffix1));
	const char	prefix2[7] = "";
	const char	suffix2[6] = "";
	printf("This is the prefix: %s\n", prefix2);
	printf("This is the suffix: %s\n", suffix2);
	printf("this is the new string: %s\n", ft_strjoin(prefix2, suffix2));
	printf("This is the prefix: %s\n", prefix);
	printf("This is the suffix: %s\n", suffix2);
	printf("this is the new string: %s\n", ft_strjoin(prefix, suffix2));
}*/
