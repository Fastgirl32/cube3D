/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:12:45 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/13 12:07:45 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if ((nmemb == SIZE_MAX && size > 1) || (size == SIZE_MAX && nmemb > 1))
		return (pointer = NULL);
	pointer = malloc(nmemb * size);
	if (pointer)
		ft_bzero(pointer, nmemb * size);
	return (pointer);
}
/* if (pointer == NULL) illustrates that the pointervalue is NULL
and the memory has not been created succesfully and returns the pointer.*/

/*int	main(void)
{
	char *pointer = ft_calloc(8000000000, sizeof(char));
	char *pointer2 = ft_calloc(0, sizeof(char));
	ft_memset(pointer, 'A', 8000000000);
	ft_memset(pointer2, 'A', 4);
	printf("das ist adresse: %p\n", pointer);
	printf("das ist adresse2: %p\n", pointer2);
	printf("das ist string: %s\n", pointer);
	printf("das ist string: %s\n", pointer2);

}*/
