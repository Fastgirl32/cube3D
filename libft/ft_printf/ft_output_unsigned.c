/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:31:39 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/28 14:55:20 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_unsigned(unsigned int n)
{
	char	*number;
	int		rv;

	rv = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		rv = 1;
		return (rv);
	}
	else
	{
		number = ft_itoa_ten(n);
		rv += ft_output_string(number);
	}
	free(number);
	return (rv);
}
