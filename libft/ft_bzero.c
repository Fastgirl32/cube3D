/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:03:51 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/04 09:16:14 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char test[10] = "Gabriel";
	printf("this is before bzero: %s \n", test);
	ft_bzero(test, 3);
	printf("this is after ft_bzero: %s \n", test);
	bzero(test, 3);
	printf("this is after bzero: %s \n", test);	
}*/
