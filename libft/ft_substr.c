/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:43 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 20:25:43 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_string;
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen(s);
	if (start >= j)
	{
		sub_string = (char *)malloc(sizeof(char));
		*sub_string = '\0';
		return (sub_string);
	}
	if ((j - start) < len)
		len = j - start;
	sub_string = (char *)malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_string[i] = s[start + i];
		i ++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
// if (ft_strlen(s + start) < len) and if (ft_strlen(s) < start) is there to
// prevent copying garbage values from memory
// use ft_strlcpy instead of ft_memcpy to copy over the null termination
/*int	main(void)
{
	const char test [7] = "Gabriel";
	printf("This is the string: %s\n", test);
	printf("This is the substring: %s", ft_substr(test, 9, 9));
}*/
