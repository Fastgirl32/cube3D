/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:10 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:11 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	consecutive_nl(char *info, int i, t_game *game)
{
	if (info[i] == '\n' && info[i + 1] && info[i + 1] == '\n')
		error("Error\nInvalid Map\n", game);
	return (1);
}

int	count_height(char *info, int i, t_game *game)
{
	int	count;
	int	count_newl;

	count = 0;
	count_newl = 0;
	while (info[i])
	{
		while (info[i] && info[i] != '\n')
		{
			count++;
			i++;
		}
		count_newl++;
		if (count > game->count2)
			game->count2 = count;
		count = 0;
		if (!info[i] && consecutive_nl(info, i, game))
			return (count_newl);
		i++;
	}
	return (count_newl);
}

char	*calloc_secure2(t_game *game)
{
	char	*str;

	str = ft_calloc(game->count2 + 1, sizeof(char));
	if (!str)
		error("Error\nMalloc failed!\n", game);
	return (str);
}

char	**calloc_secure(t_game *game, int height)
{
	char	**str;

	str = ft_calloc(height + 1, sizeof(char *));
	if (!str)
		error("Error\nMalloc failed!\n", game);
	return (str);
}

void	cut_map(t_game *game, int i, char *info)
{
	int	k;
	int	j;
	int	height;

	j = 0;
	k = 0;
	while (info[i] && info[i] == '\n')
		i++;
	height = count_height(info, i, game);
	game->map->map = calloc_secure(game, height);
	while (info[i])
	{
		game->map->map[k] = calloc_secure2(game);
		j = 0;
		while (info[i] && info[i] != '\n')
		{
			game->map->map[k][j] = info[i++];
			j++;
		}
		if (!info[i] && consecutive_nl(info, i, game))
			break ;
		k++;
		i++;
	}
}
