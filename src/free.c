/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 06:19:06 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 06:19:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all_str(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_free_all_image(void *mlx, t_data_img *lst)
{
	t_data_img	*tmp;

	if (!lst || !mlx)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->img->img)
			mlx_destroy_image(mlx, lst->img->img);
		free(lst->img);
		free(lst);
		lst = tmp;
	}
}

void	ft_free_window(t_win *window)
{
	if (!window)
		return ;
	ft_free_all_str(window->map);
	ft_free_color(window->color);
	free(window->player);
	if (window->mlx)
	{
		ft_free_all_image(window->mlx, window->lst);
		if (window->mlx_win)
			mlx_destroy_window(window->mlx, window->mlx_win);
		mlx_loop_end(window->mlx);
	}
}

void	ft_free_color(t_color *color)
{
	if (!color)
		return ;
	free(color->ceiling);
	free(color->floor);
	free(color);
	color = NULL;
}
