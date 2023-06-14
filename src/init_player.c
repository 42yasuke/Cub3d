/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:04:03 by jose              #+#    #+#             */
/*   Updated: 2023/06/14 23:35:47 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_get_x_player(char **file)
{
	int		i;
	int		j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == 'N' || file[i][j] == 'E' || \
			file[i][j] == 'S' || file[i][j] == 'W')
				return ((double)i * SQ + SQ / 2);
		}
	}
	return (-1);
}

double	ft_get_y_player(char **file)
{
	int		i;
	int		j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == 'N' || file[i][j] == 'E' || \
			file[i][j] == 'S' || file[i][j] == 'W')
				return ((double)j * SQ + SQ / 2);
		}
	}
	return (-1);
}

double	ft_get_angle_player(char **file)
{
	int		i;
	int		j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == 'N')
				return (01);
			else if (file[i][j] == 'E')
				return (10);
			else if (file[i][j] == 'W')
				return (-10);
			else if (file[i][j] == 'S')
				return (-01);
		}
	}
	return (-1);
}

void	ft_get_plane(t_player *player)
{
	if (!player->dirX)
	{
		player->planeY = 0;
		if (player->dirY > 0)
			player->planeX = -1;
		else
			player->planeX = 1;
	}
	else
	{
		player->planeX = 0;
		if (player->dirX > 0)
			player->planeY = -1;
		else
			player->planeY = 1;
	}
}
