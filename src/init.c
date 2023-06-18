/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:31:27 by jose              #+#    #+#             */
/*   Updated: 2023/06/18 03:48:39 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_init_map(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = ft_get_map(file);
	while (file[i])
		i++;
	map = malloc(sizeof(*map) * (i + 1));
	if (!map)
		return (NULL);
	while (i > -1)
		map[i--] = NULL;
	i = ft_get_map(file) - 1;
	j = -1;
	while (file[++i])
		map[++j] = ft_strdup(file[i]);
	return (map);
}

static t_color	*ft_init_color(char **file)
{
	int		i;
	t_color	*color;
	int		j;

	i = -1;
	j = 0;
	color = malloc(sizeof(*color));
	if (!color)
		return (NULL);
	color->ceiling = malloc(sizeof(int) * 3);
	if (!color->ceiling)
		return (free(color), NULL);
	color->floor = malloc(sizeof(int) * 3);
	if (!color->floor)
		return (free(color->ceiling), free(color), NULL);
	while (file[++i] && j < 2)
	{
		if (!ft_strncmp("F", file[i], 1) || !ft_strncmp("C", file[i], 1))
		{
			ft_get_ceilling_and_floor_color(file[i], color);
			j++;
		}
	}
	return (color);
}

static t_player	*ft_init_all_to_zero(void)
{
	t_player	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->dirx = 0;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0;
	player->posx = 0;
	player->posy = 0;
	return (player);
}

static t_player	*ft_init_player(char **file)
{
	t_player	*player;

	player = ft_init_all_to_zero();
	if (!player)
		return (NULL);
	player->posx = ft_get_x_player(file);
	player->posy = ft_get_y_player(file);
	player->dirx = ft_get_angle_player(file) / 10;
	player->diry = ft_get_angle_player(file) % 10;
	ft_get_plane(player);
	return (player);
}

void	ft_init_all(t_win *win, char **file)
{
	win->lst = NULL;
	win->mlx = NULL;
	win->mlx_win = NULL;
	win->color = ft_init_color(file);
	if (!win->color)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, "m_fail", win));
	win->map = ft_init_map(file);
	if (!win->map)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, "m_fail", win));
	win->player = ft_init_player(win->map);
	if (!win->player)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, "m_fail", win));
	win->map[(int)(win->player->posx)][(int)(win->player->posy)] = '0';
}
