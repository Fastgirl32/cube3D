/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:13 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:14 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *error, t_game *game)
{
	ft_putstr_fd(error, STDERR_FILENO);
	free_all(game);
}

char	**free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (NULL);
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	free_all2(t_game *game)
{
	if (game->map->north)
		free(game->map->north);
	if (game->map->south)
		free(game->map->south);
	if (game->map->east)
		free(game->map->east);
	if (game->map->west)
		free(game->map->west);
	if (game->map->map)
		free_str_arr(game->map->map);
	if (game->map->floor)
		free_str_arr(game->map->floor);
	if (game->map->ceiling)
		free_str_arr(game->map->ceiling);
	if (game->map)
		free(game->map);
	if (game->ray)
		free(game->ray);
	if (game->img)
		free(game->img);
	if (game->player)
		free(game->player);
	if (game)
		free(game);
}

void	free_all(t_game *game)
{
	if (game->n.img)
		mlx_destroy_image(game->mlx_ptr, game->n.img);
	if (game->s.img)
		mlx_destroy_image(game->mlx_ptr, game->s.img);
	if (game->e.img)
		mlx_destroy_image(game->mlx_ptr, game->e.img);
	if (game->w.img)
		mlx_destroy_image(game->mlx_ptr, game->w.img);
	if (game->img->img)
		mlx_destroy_image(game->mlx_ptr, game->img->img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	if (game->map->info)
		free(game->map->info);
	free_all2(game);
	exit(1);
}
