/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:43:24 by jose              #+#    #+#             */
/*   Updated: 2023/06/12 17:47:14 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_win(t_win *window)
{
	return (ft_free_window(window), EXIT_SUCCESS);
}

int	ft_event_manager(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		return (ft_close_win(win));
	/*ft_move_manager(win, keycode);
	(ft_put_image_manager((t_win *)win), mlx_do_sync(((t_win *)win)->mlx));*/
	return (EXIT_SUCCESS);
}