/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:50:57 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 12:38:38 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_cs(int cs)
{
	if (cs == 'c' || cs == 's' || cs == 'p' || cs == 'd' || cs == 'i' || \
	cs == 'u' || cs == 'x' || cs == 'X' || cs == '%')
		return (1);
	else
		return (0);
}

int	ft_check_format(const char *string, va_list arguments)
{
	int	rv;
	int	index;

	index = 0;
	rv = 0;
	while (string[index])
	{
		if (string[index] != '%')
			rv += ft_putchar(string[index]);
		else if ((string[index] == '%') && string[index + 1])
		{
			index ++;
			if (ft_is_cs(string[index]))
				rv += ft_convert(arguments, string[index]);
			else if (string[index])
				rv += ft_putchar(string[index]);
		}
		index ++;
	}
	return (rv);
}
/* In this function we are printing the string up until the '%' inside the
string. Here we check with the function ft_is_cs if what follows the '%' is
indeed a valid conversion specifier. If it is we call the function ft_convert
which will choose the right function to print that argument. If it isn't valid
we keep printing the sting. Each funtion that prints the arguments also returns
a count of how many character were printed and adds them to rv.
The function which prints the string itself also returns a counter of how many
character were printed. At the end all is added together so we can return the
total amount of character printed.
*/
