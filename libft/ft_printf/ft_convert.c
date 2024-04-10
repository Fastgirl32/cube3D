/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:51:54 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 12:44:16 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list arguments, int conv_specifier)
{
	int	rv;

	rv = 0;
	if (conv_specifier == 'c')
		rv += ft_output_char(va_arg(arguments, int));
	else if (conv_specifier == 's')
		rv += ft_output_string(va_arg(arguments, char *));
	else if (conv_specifier == 'p')
		rv += ft_output_pointer(va_arg(arguments, void *));
	else if (conv_specifier == 'i')
		rv += ft_output_decimal(va_arg(arguments, int));
	else if (conv_specifier == 'd')
		rv += ft_output_decimal(va_arg(arguments, int));
	else if (conv_specifier == 'u')
		rv += ft_output_unsigned(va_arg(arguments, unsigned int));
	else if (conv_specifier == 'x')
		rv += ft_output_hex(va_arg(arguments, unsigned int), conv_specifier);
	else if (conv_specifier == 'X')
		rv += ft_output_hex(va_arg(arguments, unsigned int), conv_specifier);
	else if (conv_specifier == '%')
		rv += ft_put_percent();
	return (rv);
}
/* ft_convert checks what follows after each '%' to assign the correct function
for that conversion specifier. Each function prints out the value of that
variable and returns a counter of how many character were printed.
At the end we return that counter.
*/
