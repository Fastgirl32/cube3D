/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:03:16 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 12:58:07 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_pointer(void *pointer)
{
	long	address;
	char	*str_address;
	int		rv;

	if (pointer == NULL)
	{
		write(1, "(nil)", 5);
		rv = 5;
		return (rv);
	}
	address = (unsigned long long)pointer;
	write(1, "0x", 2);
	rv = 2;
	str_address = ft_itoa_hex(address);
	rv += ft_output_string(str_address);
	free(str_address);
	return (rv);
}
/* This function prints out the memory address of the variable pointed to in
hexadecimal value. We add a prefix "0x".
We allocate memory for a new string and give it the value
of the converted address. We print that string and free it after.
At the end we return a counter of how many characters were printed.
*/
