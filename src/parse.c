/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:06:48 by marvin            #+#    #+#             */
/*   Updated: 2023/06/07 16:06:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_good_extension(char *str_file)
{
	int	i;

	i = 0;
	if (ft_strlen(str_file) < 4)
		return (false);
	while (str_file[i])
		i++;
	i--;
	if (str_file[i - 3] == '.' && str_file[i - 2] == 'c')
		if (str_file[i - 1] == 'u' && str_file[i] == 'b')
			return (true);
	return (false);
}

static t_win	*ft_init(char **file)
{
	t_win	*win;
	t_garbe	*garbe;

	garbe = ft_get_garbe();
	win = malloc(sizeof(*win));
	if (!win)
		ft_error(MALLOC_FAILED, "malloc_window");
	garbe->win = win;
	ft_init_all(win, file);
	win->mlx = mlx_init();
	if (!win->mlx)
		ft_error(MLX_INIT_FAILED, "mlx_init");
	win->mlx_win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!win->mlx_win)
		ft_error(MLX_WIN_FAILED, "mlx_win");
	return (ft_add_all_image(win, file), win);
}

t_win	*ft_parsing_manager(char *str_file)
{
	char	**file;
	t_garbe	*garbe;

	garbe = ft_get_garbe();
	file = ft_set_file(str_file);
	garbe->file = file;
	if (!ft_is_a_good_file(file))
		ft_error(BAD_PARAMETERS, str_file);
	return (ft_init(file));
}
