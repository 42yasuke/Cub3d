/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/06/07 16:08:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	//t_win	*win;

	if (ac != 2)
		ft_error(BAD_PARAMETERS, "bad parameters", NULL);
	if (!ft_good_extension(av[1]))
		ft_error(BAD_EXTENSION, "bad file extension", NULL);
	ft_printf("c bon");
	/*win = ft_initial_window(av[1]);
	mlx_loop_hook(win->mlx, &ft_draw_map, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, StructureNotifyMask, \
	&ft_close_win, win);
	mlx_loop(win->mlx);
	mlx_destroy_display(win->mlx);
	(free(win->mlx), free(win));*/
	return (EXIT_SUCCESS);
}
