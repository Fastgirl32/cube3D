/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:19:12 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 14:02:26 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pointer_s1;
	unsigned char	*pointer_s2;

	pointer_s1 = (unsigned char *)s1;
	pointer_s2 = (unsigned char *)s2;
	if (pointer_s1 == pointer_s2)
		return (0);
	while (n != 0)
	{
		if (*pointer_s1 != *pointer_s2)
		{
			return (*pointer_s1 - *pointer_s2);
		}
		pointer_s1++;
		pointer_s2++;
		n --;
	}
	return (0);
}

/*int main()
{
    int ret = 0;
    int ret2 = 0;
    //If s1 and s2 equal
    ret = ft_memcmp("abc","abc",2);
    ret2 = memcmp("abc","abc",2);
    printf("ret = %d\n",ret);
    printf("ret2 = %d\n",ret2);
    //if first char of s1 is large to s2
    ret = ft_memcmp("bca","abc",2);
    ret2 = memcmp("bca","bca",2);
    printf("ret = %d\n",ret);
    printf("ret2 = %d\n",ret2);
    //if first char of s1 is small to s2
    ret = ft_memcmp("abc","bca",2);
    ret2 = memcmp("abc","bca",2);
    printf("ret = %d\n",ret);
    printf("ret2 = %d\n",ret2);
    return (0);
}*/
