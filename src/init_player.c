/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:04:03 by jose              #+#    #+#             */
/*   Updated: 2023/06/17 22:01:34 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_get_x_player(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S')
				return ((double)i - 0.5); //not done
			if (map[i][j] == 'E' || map[i][j] == 'W')
				return ((double)i - 0.5);
		}
	}
	return (-1);
}

double	ft_get_y_player(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S')
				return ((double)j - 0.5);
			if (map[i][j] == 'E' || map[i][j] == 'W')
				return ((double)j - 0.5);
		}
	}
	return (-1);
}

int	ft_get_angle_player(char **file)
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
			player->planeX = FOV / 100.0;
		else
			player->planeX = -1 * FOV / 100.0;
	}
	else
	{
		player->planeX = 0;
		if (player->dirX > 0)
			player->planeY = FOV / 100.0;
		else
			player->planeY = -1 * FOV / 100.0;
	}
}
