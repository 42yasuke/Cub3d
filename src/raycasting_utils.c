/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:03:28 by jose              #+#    #+#             */
/*   Updated: 2023/11/01 17:13:41 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_line_to_draw(t_ray *ray)
{
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->drawstart = -1 * ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
}

void	ft_tex_calc(t_ray *ray)
{
	if (ray->side == 0)
		ray->wallx = ray->rayposy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = ray->rayposx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor((ray->wallx));
	ray->texx = (int)((ray->wallx) * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->raydirx > 0)
		ray->texx = TEX_WIDTH - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = TEX_WIDTH - ray->texx - 1;
}

void	ft_draw_pix(t_win *win, int coord, int color)
{
	char	*addr;
	t_image	*img;

	img = win->lst->img;
	addr = img->addr;
	addr[(coord / 1000) * (img->bpp / 8) + (coord % 1000) \
	* img->size_line + 0] = ft_nbr_blue(color);
	addr[(coord / 1000) * (img->bpp / 8) + (coord % 1000) \
	* img->size_line + 1] = ft_nbr_green(color);
	addr[(coord / 1000) * (img->bpp / 8) + (coord % 1000) \
	* img->size_line + 2] = ft_nbr_red(color);
	addr[(coord / 1000) * (img->bpp / 8) + (coord % 1000) \
	* img->size_line + 3] = 0;
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

	ray->step = 1.0 * TEX_HEIGHT / (ray->lineheight);
	ray->tex_pos = (ray->drawstart - HEIGHT / 2 \
	+ ray->lineheight / 2) * ray->step;
	y = ray->drawstart - 1;
	while (++y < ray->drawend)
	{
		ray->texy = (int)(ray->tex_pos) & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		if (ray->side == 1 && ray->raydiry < 0)
			ft_draw_pix(win, x * M + y, \
			ft_px_ext(win, NORTH, ray->texx, ray->texy));
		else if (ray->side == 0 && ray->raydirx > 0)
			ft_draw_pix(win, x * M + y, \
			ft_px_ext(win, SOUTH, ray->texx, ray->texy));
		else if (ray->side == 1 && ray->raydiry > 0)
			ft_draw_pix(win, x * M + y, \
			ft_px_ext(win, EAST, ray->texx, ray->texy));
		else if (ray->side == 0 && ray->raydirx < 0)
			ft_draw_pix(win, x * M + y, \
			ft_px_ext(win, WEST, ray->texx, ray->texy));
	}
}
