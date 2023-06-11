/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/06/11 04:35:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_win	*win;

	(void)win;
	if (ac != 2)
		ft_error(BAD_PARAMETERS, "bad parameters", NULL);
	if (!ft_good_extension(av[1]))
		ft_error(BAD_EXTENSION, "bad file extension", NULL);
	win = ft_parsing_manager(av[1]);
	ft_printf("c bon");
	
	
	/*
	mlx_loop_hook(win->mlx, &ft_draw_map, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, StructureNotifyMask, &ft_close_win, win);
	mlx_loop(win->mlx);
	*/
	mlx_destroy_display(win->mlx);
	(free(win->mlx), free(win));
	return (EXIT_SUCCESS);
}
