/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:52:40 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 12:48:52 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_string(char *string)
{
	int	index;

	index = 0;
	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[index])
	{
		ft_putchar(string[index]);
		index ++;
	}
	return (index);
}
/* This function prints out a string given as argument and returns a counter of
how many characters have been printed. If the string doesn't exist it prints
(null) and returns a copunter of 6.
*/
