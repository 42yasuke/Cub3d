/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:35 by jose              #+#    #+#             */
/*   Updated: 2023/06/12 14:41:04 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_add_image(t_win *win, char *path, int id)
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
	tmp->img->addr = NULL;
	if (!tmp->img->img)
		(ft_free_window(win), ft_error(IMAGE_NOT_F, "image_not_found", win));
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, \
	&tmp->img->size_line, &tmp->img->endian);
}

static void	ft_add_background(t_win *win)
{
	win->lst = malloc(sizeof(*(win->lst)));
	if (!win->lst)
		ft_error(MALLOC_FAILED, "malloc_failed", win);
	win->lst->next = NULL;
	win->lst->img = malloc(sizeof(*(win->lst->img)));
	if (!win->lst->img)
		ft_error(MALLOC_FAILED, "malloc_failed", win);
	win->lst->img->img = mlx_xpm_file_to_image(win->mlx, \
	"image/noir.xpm", &win->lst->img->width, &win->lst->img->height);
	if (!win->lst->img->img)
		ft_error(IMAGE_NOT_F, "image_not_found", win);
	win->lst->img->addr = mlx_get_data_addr(win->lst->img->img, \
	&win->lst->img->bpp, &win->lst->img->size_line, &win->lst->img->endian);
	win->lst->img->id = BACKGROUND;
}

static char	*ft_get_image_path(char **file, char *str)
{
	char	**line;
	char	*ret;
	int		i;

	i = -1;
	while (file[++i])
	{
		line = ft_split(file[i], ' ');
		if (!line)
			return (NULL);
		if (!ft_strncmp(str, line[0], ft_strlen(str)))
		{
			ret = ft_strdup(line[0]);
			if (!ret)
				return (ft_free_all_str(line), NULL);
			break ;
		}
		ft_free_all_str(line);
	}
	return (ft_free_all_str(line), ret);
}

static void	ft_get_wall_image(t_win *win, char **file, char *str)
{
	char	*path;

	path = ft_get_image_path(file, str);
	if (!path)
		(ft_free_all_str(file), ft_error(MALLOC_FAILED, M_F, win));
	(ft_add_image(win, path, NORTH), free(path));
}

void	ft_add_all_image(t_win *win, char **file)
{
	if (!win->lst)
		ft_add_background(win);
	ft_get_wall_image(win, file, "NO");
	ft_get_wall_image(win, file, "SO");
	ft_get_wall_image(win, file, "EA");
	ft_get_wall_image(win, file, "WE");
}
