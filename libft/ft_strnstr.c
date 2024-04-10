/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:26 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/06 16:52:57 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pointer_big;
	size_t	i;
	size_t	j;

	pointer_big = (char *)big;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (pointer_big);
	while (len > i && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && len > i + j)
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}

/*char 	*strnstr(const char *s, const char *find, size_t slen)
{
	size_t	len;

	char c, sc;
	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int	main(void)
{
	char Haystack[40] = "This co is ol a cool long string!";
	char Needle[30] = "cool";
	char Haystack_2[40] = "This is a not so cool long string!";
	char Needle_2[30] = "Hello";
	char Haystack_3[30] = "random string";
	char Needle_3[30] = "";
	char Haystack_4[30] = "";
	char Needle_4[30] = "randy random";
	printf("ft_strnstr is :%s\n", ft_strnstr(Haystack, Needle, 21));
	printf("strnstr is :%s\n", strnstr(Haystack, Needle, 21));
	printf("ft_strnstr is :%s\n", ft_strnstr(Haystack_2, Needle_2, 10));
	printf("strnstr is :%s\n", strnstr(Haystack_2, Needle_2, 10));
	printf("ft_strnstr is :%s\n", ft_strnstr(Haystack_3, Needle_3,9));
	printf("strnstr is :%s\n", strnstr(Haystack_3, Needle_3, 9));
	printf("ft_strnstr is :%s\n", ft_strnstr(Haystack_4, Needle_3, 5));
	printf("strnstr is :%s\n", strnstr(Haystack_4, Needle_3, 5));
	printf("ft_strnstr is :%s\n", ft_strnstr(Haystack_4, Needle_4, 5));
	printf("strnstr is :%s\n", strnstr(Haystack_4, Needle_4, 5));
}*/
