/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:17:57 by jose              #+#    #+#             */
/*   Updated: 2023/06/15 15:36:46 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_ray(t_ray *ray)
{
	ray->cameraX = 0;
	ray->rayPosX = 0;
	ray->rayPosY = 0;
	ray->rayDirX = 0;
	ray->rayDirY = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->deltaDistX = 0;
	ray->deltaDistY = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perpWallDist = 0;
}

static t_ray	*ft_set_ray(t_win *win, int i)
{
	t_ray		*ray;
	t_player	*pl;

	pl = win->player;
	ray = malloc(sizeof(*ray));
	if (!ray)
		ft_error(MALLOC_FAILED, M_F, win);
	ft_init_ray(ray);
	ray->cameraX = (2 * i / WIDTH) - 1;
	ray->rayPosX = pl->posX;
	ray->rayPosY = pl->posY;
	ray->rayDirX = pl->dirX + pl->planeX * ray->cameraX;
	ray->rayDirY = pl->dirY + pl->planeY * ray->cameraX;
	ray->mapX = (int)(ray->rayPosX);
	ray->mapY = (int)(ray->rayPosY);
	ray->deltaDistX = sqrt(1 + pow(ray->rayDirY, 2) / pow(ray->rayDirX, 2));
	ray->deltaDistY = sqrt(1 + pow(ray->rayDirX, 2) / pow(ray->rayDirY, 2));
	return (ray);
}

static void	ft_calculate_step_and_initial_sideDist(t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->rayPosX - ray->mapX) * ray->deltaDistX;
	} 
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->rayPosX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->rayPosY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->rayPosY) * ray->deltaDistY;
	}
}

static void	ft_dda(t_ray *ray, char **map)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map[ray->mapX][ray->mapY] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
}

void	ft_raycast_manager(t_win *win)
{
	int		i;
	t_ray	*ray;

	i = -1;
	while (++i < WIDTH)
	{
		ray = ft_set_ray(win, i);
		ft_calculate_step_and_initial_sideDist(ray);
		ft_dda(ray, win->map);
		free(ray);
	}
}