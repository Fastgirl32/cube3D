/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:44:50 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/04 11:24:43 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char test[10] = "Gabriel";
	printf("This is test before memset: %s \n", test);
	ft_memset(test, '*', 3);
	printf("This is test after ft_memset: %s \n", test);
	memset(test, '*', 3);
	printf("This is test after memset: %s \n", test);
}*/
