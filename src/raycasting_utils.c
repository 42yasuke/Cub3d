/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:03:28 by jose              #+#    #+#             */
/*   Updated: 2023/06/16 13:29:56 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_line_to_draw(t_ray *ray)
{
	ray->lineHeight = (int)(HEIGHT / ray->perpWallDist);
	ray->drawStart = -1 * ray->lineHeight / 2 + HEIGHT / 2;
	if(ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + HEIGHT / 2;
	if(ray->drawEnd >= HEIGHT)
		ray->drawEnd = HEIGHT - 1;
}

void	ft_tex_calc(t_ray *ray)
{
	if (ray->side == 0)
		ray->wallx = ray->rayPosY + ray->perpWallDist * ray->rayDirY;
	else
		ray->wallx = ray->rayPosX + ray->perpWallDist * ray->rayDirX;
	ray->wallx -= floor((ray->wallx));
	ray->texx = (int)((ray->wallx) * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->rayDirX > 0)
		ray->texx = TEX_WIDTH - (ray->texx) - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		ray->texx = TEX_WIDTH - (ray->texx) - 1;
}

void	ft_px_put(t_win *win, int x, int y, int color)
{
	char	*dst;
	t_image	*img;

	img = ft_get_img(win->lst, BACKGROUND);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static unsigned int	ft_px_ext(t_win *win, int id, int x, int y)
{
	char	*dst;
	t_image	*img;

	img = ft_get_img(win->lst, id);
	if (!img)
		return (0);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_tex_px_inc(t_win *win, t_ray *ray, int x)
{
	int	y;

	ray->step = 1.0 * TEX_HEIGHT / (ray->lineHeight);
	ray->tex_pos = ((ray->drawStart) - HEIGHT / 2 + ray->lineHeight / 2) * ray->step;
	y = ray->drawStart - 1;
	while (++y < ray->drawEnd)
	{
		ray->texy = (int)(ray->tex_pos) & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		if (ray->side == 1 && ray->rayDirY < 0)
			ft_px_put(win, x, y, ft_px_ext(win, NORTH, ray->texx, ray->texy));
		else if (ray->side == 0 && ray->rayDirX > 0)
			ft_px_put(win, x, y, ft_px_ext(win, EAST, ray->texx, ray->texy));
		else if (ray->side == 1 && ray->rayDirY > 0)
			ft_px_put(win, x, y, ft_px_ext(win, SOUTH, ray->texx, ray->texy));
		else if (ray->side == 0 && ray->rayDirX < 0)
			ft_px_put(win, x, y, ft_px_ext(win, WEST, ray->texx, ray->texy));
	}
}
