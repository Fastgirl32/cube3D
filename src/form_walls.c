/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secker <secker@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:00:23 by secker            #+#    #+#             */
/*   Updated: 2023/12/03 21:00:24 by secker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pxl_put(t_game *game, int x, int y, int color)
{
	char	*pxl;

	if (((x >= 0) && (y >= 0)) && ((x < 1920) && (y < 1080)))
	{
		pxl = game->img->addr + (y * game->img->size_line + x * (32 / 8));
		*(int *)pxl = color;
	}
}

unsigned int	get_color_pixel(t_texture tex, int y, int x)
{
	unsigned int	pos;
	int				*addr;

	pos = y * tex.addr.sizeline + x * (tex.addr.bpp / 8);
	addr = (int *)tex.addr.img;
	return (*(int *)((char *)addr + pos));
}

t_texture	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 1 && ray->raydir_y < 0)
		return (&game->n);
	else if (ray->side == 1 && ray->raydir_y > 0)
		return (&game->s);
	else if (ray->side == 0 && ray->raydir_x < 0)
		return (&game->w);
	else
		return (&game->e);
}

void	form_texture(t_game *game, t_ray *ray, int x)
{
	int	y;

	if (ray->side == 0)
		ray->wallx = ray->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		ray->wallx = ray->pos_x + ray->perpwalldist * ray->raydir_x;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)game->textwidth);
	if ((ray->side == 0 && ray->raydir_x > 0) || (ray->side == 1
			&& ray->raydir_y < 0))
		ray->texx = game->textwidth - ray->texx - 1;
	ray->step = 1.0 * game->textheight / ray->lineheight;
	ray->texpos = (ray->drawstart - game->screen_height / 2 + ray->lineheight
			/ 2) * ray->step;
	y = ray->drawstart - 1;
	while (++y < ray->drawend + 1)
	{
		ray->texy = (int)ray->texpos & (game->textheight - 1);
		ray->texpos += ray->step;
		ray->color = get_color_pixel(*select_texture(game, ray), ray->texy,
				ray->texx);
		img_pxl_put(game, x, y, ray->color);
	}
}
