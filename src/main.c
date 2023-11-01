/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/11/01 16:02:03 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2)
		ft_error(BAD_PARAMETERS, "bad parameters");
	if (!ft_good_extension(av[1]))
		ft_error(BAD_EXTENSION, "bad file extension");
	win = ft_parsing_manager(av[1]);
	mlx_loop_hook(win->mlx, &ft_draw_window, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, \
	StructureNotifyMask, &ft_close_win, win);
	mlx_loop(win->mlx);
	return (ft_free_garbe(), EXIT_SUCCESS);
}
