/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:41 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:42 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_check(int ac, char *av)
{
	size_t	i;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d <filename>.cub\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = ft_strlen(av);
	if (i < 5 || !(av[i - 4] == '.' && av[i - 3] == 'c' && av[i - 2] == 'u'
			&& av[i - 1] == 'b'))
	{
		ft_putstr_fd("Error\nWrong fileformat\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
