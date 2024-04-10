/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:38 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:39 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(int x, t_ray *ray, t_player *player, t_game *game)
{
	ray->pos_x = player->pos_x + 0.5;
	ray->pos_y = player->pos_y + 0.5;
	ray->camera = 2 * x / (double)game->screen_width - 1;
	ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera;
	ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera;
	ray->mapx = (int)ray->pos_x;
	ray->mapy = (int)ray->pos_y;
	if (ray->raydir_x == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}
