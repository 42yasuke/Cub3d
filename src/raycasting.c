/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:17:57 by jose              #+#    #+#             */
/*   Updated: 2023/06/17 23:02:45 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_ray	*ft_set_ray(t_win *win, int i)
{
	t_ray		*ray;
	t_player	*pl;

	pl = win->player;
	ray = malloc(sizeof(*ray));
	if (!ray)
		ft_error(MALLOC_FAILED, M_F, win);
	ft_init_ray(ray);
	ray->camerax = 2 * i / (double)WIDTH - 1;
	ray->rayposx = pl->posx;
	ray->rayposy = pl->posy;
	ray->raydirx = pl->dirx + pl->planex * ray->camerax;
	ray->raydiry = pl->diry + pl->planey * ray->camerax;
	ray->mapx = (int)(ray->rayposx);
	ray->mapy = (int)(ray->rayposy);
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	return (ray);
}

static void	ft_calculate_step_and_initial_sidedist(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->rayposx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->rayposx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->rayposy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->rayposy) * ray->deltadisty;
	}
}

static void	ft_dda(t_ray *ray, char **map)
{
	while (!ray->hit)
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
		if (map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}

static void	ft_draw_cf(t_win *win, t_ray *ray, int x)
{
	int	y;
	int	*tab_c;
	int	color;

	y = -1;
	tab_c = win->color->ceiling;
	color = ft_bgr_into_int(tab_c[2], tab_c[1], tab_c[0]);
	while (++y < ray->drawstart)
		ft_draw_pix(win, x * 1000 + y, color);
	tab_c = win->color->floor;
	color = ft_bgr_into_int(tab_c[2], tab_c[1], tab_c[0]);
	y = ray->drawend - 1;
	while (++y < HEIGHT - 1)
		ft_draw_pix(win, x * 1000 + y, color);
}

void	ft_raycast_manager(t_win *win)
{
	int		i;
	t_ray	*ray;

	i = -1;
	while (++i < WIDTH)
	{
		ray = ft_set_ray(win, i);
		ft_calculate_step_and_initial_sidedist(ray);
		ft_dda(ray, win->map);
		ft_set_line_to_draw(ray);
		ft_tex_calc(ray);
		ft_tex_px_inc(win, ray, i);
		ft_draw_cf(win, ray, i);
		free(ray);
	}
}
