/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:11:34 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/17 16:29:40 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	if (!s)
		return (NULL);
	new_string = ft_strdup(s);
	if (!new_string)
		return (NULL);
	index = 0;
	while (new_string[index])
	{
		new_string[index] = f(index, new_string[index]);
		index ++;
	}
	return (new_string);
}
