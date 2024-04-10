/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:34:08 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 13:09:33 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	whatis_index(unsigned int n)
{
	int	index;

	index = 0;
	while (n != 0)
	{
		n = n / 16;
		index++;
	}
	return (index);
}

static void	ft_put_hex(unsigned int n, const char cs)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, cs);
		ft_put_hex(n % 16, cs);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + 48));
		else
		{
			if (cs == 'x')
				ft_putchar((n - 10 + 'a'));
			if (cs == 'X')
				ft_putchar((n - 10 + 'A'));
		}
	}
}

int	ft_output_hex(unsigned int n, const char cs)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, cs);
	return (whatis_index(n));
}
/* ft_output_hex prints converts the int given as argument into either
lowercase hexadecimal or uppercase hexadecimal depending on the argument cs.

We print out each character and at the end return the counter for how many
characters were printed.
*/
