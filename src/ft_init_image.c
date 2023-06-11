/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:35 by jose              #+#    #+#             */
/*   Updated: 2023/06/11 16:18:09 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_add_image(t_win *win, char *path, int id)
{
	t_data_img	*tmp;

	tmp = win->lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(*tmp));
	if (!tmp->next)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed", win));
	tmp = tmp->next;
	tmp->next = NULL;
	tmp->img = malloc(sizeof(*(tmp->img)));
	if (!tmp->img)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed", win));
	tmp->img->img = mlx_xpm_file_to_image(win->mlx, path, \
	&tmp->img->width, &tmp->img->height);
	tmp->img->id = id;
	tmp->img->screened = 0;
	tmp->img->addr = NULL;
	if (!tmp->img->img)
		(ft_free_window(win), ft_error(IMAGE_NOT_F, "image_not_found", win));
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, \
	&tmp->img->size_line, &tmp->img->endian);
}

void	ft_add_all_image(t_win *win)
{
	if (!win->lst)
		ft_add_background(win);
	ft_add_image(win, "image/asteroid_sf.xpm", OBSTACLE);
	ft_add_image(win, "image/it1.xpm", ITEM);
	ft_add_image(win, "image/it2.xpm", ITEM);
	ft_add_image(win, "image/it3.xpm", ITEM);
	ft_add_image(win, "image/it4.xpm", ITEM);
	ft_add_image(win, "image/it5.xpm", ITEM);
	ft_add_image(win, "image/it6.xpm", ITEM);
	ft_add_image(win, "image/exit_sf.xpm", EXIT);
	ft_add_image(win, "image/fusee_sf.xpm", SPACIALSHIP);
	ft_add_image(win, "image/ennemi_sf.xpm", ENEMY);
	ft_remove_all_backgroud(win);
}

void	ft_add_background(t_win *win)
{
	win->lst = malloc(sizeof(*(win->lst)));
	if (!win->lst)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed", win));
	win->lst->next = NULL;
	win->lst->img = malloc(sizeof(*(win->lst->img)));
	if (!win->lst->img)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed", win));
	win->lst->img->img = mlx_xpm_file_to_image(win->mlx, \
	"image/noir.xpm", &win->lst->img->width, &win->lst->img->height);
	if (!win->lst->img->img)
		(ft_free_window(win), ft_error(IMAGE_NOT_F, "image_not_found", win));
	win->lst->img->addr = mlx_get_data_addr(win->lst->img->img, \
	&win->lst->img->bpp, &win->lst->img->size_line, &win->lst->img->endian);
	win->lst->img->id = BACKGROUND;
	win->lst->img->screened = 0;
}
