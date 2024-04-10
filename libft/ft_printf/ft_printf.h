/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnowak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:53:00 by phnowak           #+#    #+#             */
/*   Updated: 2022/10/28 14:28:09 by phnowak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_check_format(const char *string, va_list arguments);
int		ft_putchar(char c);
int		ft_convert(va_list arguments, int conv_specifier);
int		ft_output_char(int c);
int		ft_output_string(char *string);
int		ft_output_pointer(void *pointer);
char	*ft_itoa_hex(unsigned long long n);
int		ft_output_decimal(int number);
char	*ft_itoa_ten(unsigned int n);
int		ft_output_unsigned(unsigned int n);
int		ft_output_hex(unsigned int n, const char cs);
int		ft_put_percent(void);

#endif
