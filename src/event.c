/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:43:24 by jose              #+#    #+#             */
/*   Updated: 2023/06/18 00:52:33 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_win(t_win *window)
{
	return (ft_free_window(window), EXIT_SUCCESS);
}

static void	ft_move_manager(t_win *win, int keycode)
{
	if (keycode == KEY_Z)
		ft_move_forward(win->player, win->map);
	if (keycode == KEY_Q)
		ft_move_left(win->player, win->map);
	if (keycode == KEY_D)
		ft_move_right(win->player, win->map);
	if (keycode == KEY_S)
		ft_move_back(win->player, win->map);
	if (keycode == KEY_LEFT)
		ft_turn(win->player, -1 * ROTSPEED);
	if (keycode == KEY_RIGHT)
		ft_turn(win->player, ROTSPEED);
}

int	ft_event_manager(int keycode, t_win *win)
{
	if (keycode == KEY_ESC)
		return (ft_close_win(win));
	ft_move_manager(win, keycode);
	(ft_put_image_manager((t_win *)win), mlx_do_sync(((t_win *)win)->mlx));
	return (EXIT_SUCCESS);
}
