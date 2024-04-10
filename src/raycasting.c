/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:59 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:01:00 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_possible_wall(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->pos_x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->pos_x) * ray->deltadistx;
	}
	if (ray->raydir_y < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->pos_y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->pos_y) * ray->deltadisty;
	}
}

void	calc_wallform(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = ray->sidedistx - ray->deltadistx;
	else
		ray->perpwalldist = ray->sidedisty - ray->deltadisty;
	if (ray->perpwalldist == 0)
		ray->lineheight = game->screen_height;
	else
		ray->lineheight = (int)(game->screen_height / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + game->screen_height / 2;
	ray->drawend = ray->lineheight / 2 + game->screen_height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend > game->screen_height)
		ray->drawend = game->screen_height - 1;
}

void	next_wall(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray->mapy <= 0 || ray->mapy >= game->height || ray->mapx < 0)
			ray->hit = 1;
		else if (game->map->map[ray->mapy][ray->mapx] == '1'
			|| game->map->map[ray->mapy][ray->mapx] == 0)
			ray->hit = 1;
	}
}

void	ray_casting(t_game *game)
{
	int	x;

	create_bg(game);
	x = 0;
	while (x < game->screen_width)
	{
		init_raycast(x, game->ray, game->player, game);
		next_possible_wall(game->ray);
		next_wall(game, game->ray);
		calc_wallform(game, game->ray);
		form_texture(game, game->ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img, 0, 0);
}
