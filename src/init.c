/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:31:27 by jose              #+#    #+#             */
/*   Updated: 2023/06/11 17:19:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_init_map(char **file)
{
	char	**map;
	int		i;

	i = ft_get_map(file);
	while (file[i])
		i++;
	map = malloc(sizeof(*map) * (i + 1));
	if (!map)
		return (NULL);
	while (i > -1)
		map[i--] = NULL;
	i = ft_get_map(file) - 1;
	while (file[++i])
		map[i] = ft_strdup(file[i]);
	return (map);
}

static t_color	*ft_init_color(char **file)
{
	int		i;
	t_color	*color;

	i = -1;
	color = malloc(sizeof(*color));
	if (!color)
		return (NULL);
	color->ceiling = malloc(sizeof(int) * 3);
	if (!color->ceiling)
		return (free(color), NULL);
	color->floor = malloc(sizeof(int) * 3);
	if (!color->floor)
		return (free(color->ceiling), free(color), NULL);
	while (file[++i] && i < 2)
		ft_get_ceilling_and_floor_color(file[i], color);
	return (color);
	
}

static t_player	*ft_init_player(char **file)
{
	t_player	*player;
	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->x = ft_get_x_player(file, player);
	player->y = ft_get_y_player(file, player);
	player->angle = ft_get_angle_player(file, player);
	return (player);
}

void	ft_init_all(t_win *win, char **file)
{
	win->lst = NULL;
	win->mlx = NULL;
	win->mlx_win = NULL;
	win->map = ft_init_map(file);
	if (!win->map)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, "m_fail", win));
	win->color = ft_init_color(file);
	if (!win->color)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, "m_fail", win));
	win->player = ft_init_player(file);
	if (!win->player)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, "m_fail", win));
}
