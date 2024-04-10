/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:35:22 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 16:39:02 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*helperfunc(char *ptr_start, char *ptr_end, char *trimed_string)
{
	unsigned int	i;

	i = 0;
	while (ptr_start <= ptr_end)
	{
		trimed_string[i] = *ptr_start;
		i++;
		ptr_start++;
	}
	trimed_string[i] = '\0';
	return (trimed_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_string;
	char	*ptr_start;
	char	*ptr_end;

	if (!s1)
		return (NULL);
	ptr_start = (char *)s1;
	ptr_end = (char *)s1;
	while (*ptr_end++)
		;
	ptr_end--;
	ptr_end--;
	while (*ptr_start && in_set(*ptr_start, set))
		ptr_start++;
	while (ptr_end > ptr_start && in_set(*ptr_end, set))
		ptr_end--;
	trimed_string = malloc(sizeof(char) * (ptr_end - ptr_start + 2));
	if (trimed_string == NULL)
		return (NULL);
	return (helperfunc(ptr_start, ptr_end, trimed_string));
}

/*int	main(void)
{
	char const	test[25] = "Hi my name is slim shady";
	char const	set[25] = "Hy";

	printf("this is test before ft_strtrim(): %s\n", test);
	printf("this is the refrence set of characters to trim: %s\n", set);
	printf("this is test after ft_strtrim(): %s\n", ft_strtrim(test, set));
}*/
