/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:52:08 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/31 12:45:52 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output_char(int c)
{
	ft_putchar(c);
	return (1);
}
/*this function prints out the character given as argument and returns a counter
of 1.
*/
