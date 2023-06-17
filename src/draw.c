/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:02:25 by jose              #+#    #+#             */
/*   Updated: 2023/06/18 00:37:45 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*ft_get_img(t_data_img *lst, int id)
{
	t_data_img	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->img->id == id)
			return (tmp->img);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_put_image_manager(t_win *win)
{
	ft_raycast_manager(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->lst->img->img, 0, 0);
}

int	ft_draw_window(void *win)
{
	static int	is_time = 0;

	if (!(is_time % FPS))
		(ft_put_image_manager((t_win *)win), mlx_do_sync(((t_win *)win)->mlx));
	is_time++;
	if (is_time == INT_MAX)
		is_time = 0;
	return (EXIT_SUCCESS);
}
