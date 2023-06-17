/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:03:45 by jose              #+#    #+#             */
/*   Updated: 2023/06/17 23:04:13 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray(t_ray *ray)
{
	ray->camerax = 0;
	ray->rayposx = 0;
	ray->rayposy = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->texx = 0;
	ray->texy = 0;
	ray->wallx = 0;
	ray->step = 0;
	ray->tex_pos = 0;
}
