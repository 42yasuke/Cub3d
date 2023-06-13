/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:02:25 by jose              #+#    #+#             */
/*   Updated: 2023/06/12 19:21:42 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*ft_get_img(t_data_img *lst, int id)
{
	t_data_img	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->img->id == id)
			return (tmp->img->img);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	ft_put_image_manager(t_win *win)
{
	int		i;
	int		j;
	void	*res;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		if (!i && !j)
			mlx_put_image_to_window(win->mlx, win->mlx_win, \
			win->lst->img->img, j * SQ, i * SQ);
		while (win->map[i][j])
		{
			res = ft_get_img(win->lst, win->map[i][j]);
			if (win->map[i][j] != '0' && res)
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				res, j * SQ, i * SQ);
			j++;
		}
		i++;
	}
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
