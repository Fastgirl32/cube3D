/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:01:08 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:01:09 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_exist(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map->map || !game->map->map[i])
		error("Error\nMap Error!\n", game);
	while (game->map->map[i])
	{
		if (game->map->map[i][0] == '\0')
			error("Error\nMap Error!\n", game);
		i++;
	}
}

void	set_defaults(t_game *game)
{
	game->map->north = NULL;
	game->map->east = NULL;
	game->map->south = NULL;
	game->map->west = NULL;
	game->map->ceiling = NULL;
	game->map->floor = NULL;
}

void	check_contain_info(t_game *game)
{
	char	*input;
	size_t	len;

	input = game->map->info;
	len = ft_strlen(input);
	if (!ft_strnstr(input, "NO ", len) || !ft_strnstr(input, "SO ", len)
		|| !ft_strnstr(input, "WE ", len) || !ft_strnstr(input, "EA ", len)
		|| !ft_strnstr(input, "C ", len) || !ft_strnstr(input, "F ", len)
		|| !ft_strchr(input, '1') || !ft_strchr(input, '0'))
		error("Error\ncheck_contain failed\n", game);
}

void	split_info(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	game->screen_width = 1920;
	game->screen_height = 1080;
	game->textwidth = 64;
	game->textheight = 64;
	check_contain_info(game);
	set_defaults(game);
	process_cub(game, game->map->info, &i);
	check_map_exist(game);
	check_color(game);
	while (game->map->map[k])
		k++;
	game->height = k;
	if (check_map(game) == false)
		error("Error\n Invalid map\n", game);
	check_access(game);
}
