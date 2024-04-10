/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:52:21 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 13:04:29 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_decimal(int number)
{
	char	*nbr;
	int		rv;

	nbr = ft_itoa(number);
	rv = ft_output_string(nbr);
	free(nbr);
	return (rv);
}
/* This function converts the int given as argument into a string, prints it,
we free the memory for the string and return a counter of how many characters
were printed.
*/
