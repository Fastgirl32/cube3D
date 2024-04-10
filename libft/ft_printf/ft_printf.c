/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:50:23 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 13:25:15 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		arguments;
	int			index;

	va_start(arguments, s);
	index = ft_check_format(s, arguments);
	va_end(arguments);
	return (index);
}
/* We're making use of variadic funtions. These can take a variable number
of arguments. We need to include stdarg.h (included in ft_printf.h)
We need one fixed argument (in this case the const char *s) and then ... as the
last argument. 

We create a va_list variable called arguments, the variable type is defined in
stdarg.h

We need va_start(arguments, s) with the variable name of our va_list and
then the variable name of our last fixed variable. This enables acces to
variadic function arguments. 

At the end we need va_end to end our acces to the variadic funtion arguments.
We return index. index is a counter for how many characters have been printed.
*/
