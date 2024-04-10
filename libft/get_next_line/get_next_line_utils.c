/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:58:57 by phnowak           #+#    #+#             */
/*   Updated: 2023/09/21 15:50:02 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new_string = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (new_string == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new_string[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	free(s1);
	return (new_string);
}

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	gnl_strlcpy(char *dest, char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (*src == '\0')
		return (0);
	while (src[len])
		len++;
	if (n != 0)
	{
		while (src[i] != '\0' && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char			*sub_string;
	unsigned int	i;
	unsigned int	j;

	j = gnl_strlen(s);
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
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
