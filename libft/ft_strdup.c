/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:41 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/10 12:52:07 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*new_string;

	new_string = malloc(ft_strlen(s) + 1);
	if (new_string == NULL)
		return (NULL);
	new_string = ft_memcpy(new_string, s, ft_strlen(s) + 1);
	return ((char *)new_string);
}

/*int	main(void)
{
	const char test1[7] = "Gabriel";
	printf("This is the original string: %s\n", test1);
	printf("This is the duplicated string with strdup(): %s\n", strdup(test1));
	printf("This is the duplicated string with ft_strdup(): %s\n",
			ft_strdup(test1));
}*/
