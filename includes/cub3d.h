/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/06/11 17:19:21 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx42/mlx.h"
# include "../mlx42/mlx_int.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

/*	window's macro	*/
# define WIDTH 800
# define HEIGHT 600
# define SQ 64

/*	error's macro*/
# define BAD_PARAMETERS 1
# define MALLOC_FAILED 2
# define MLX_INIT_FAILED 3
# define MLX_WIN_FAILED 4
# define OPEN_FAILED 5
# define MAP_NOT_VALID 6
# define BAD_EXTENSION 7
# define IMAGE_NOT_F 8

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		id;
	int		screened;
}	t_image;

typedef struct s_data_image
{
	struct s_image		*img;
	struct s_data_image	*next;
}	t_data_img;

typedef struct s_color
{
	int	*floor;
	int	*ceiling;
}	t_color;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	t_data_img	*lst;
	char		**map;
	t_color		*color;
	t_player	*player;
}	t_win;

/*	parse.c	*/
int		ft_good_extension(char *str_file);
t_win	*ft_parsing_manager(char *str_file);

/*	parse_utils.c	*/
char	**ft_set_file(char *str_file);
int		ft_good_texture(char **file);

/*	parse_file.c	*/
int		ft_get_map(char **file);
int		ft_is_a_good_file(char **file);

/*	parse_texture.c	*/
int		ft_research_texture(char *str, char **file);
int		ft_look_order(char **file);
int		ft_verif_args(char *str, char **file);

/*	parse_map.c	*/
int		ft_map_closed(char **file, int i);

/*	error.c	*/
void	ft_error(int err, char *err_msg, t_win *win);

/*	free.c	*/
void	ft_free_all_str(char **map);
void	ft_free_all_image(void *mlx, t_data_img *lst);
void	ft_free_window(t_win *window);
void	ft_free_color(t_color *color);

/*	init.c	*/
void	ft_init_all(t_win *win, char **file);

/*	init_utils.c	*/
void	ft_get_ceilling_and_floor_color(char *str, t_color *color);

/*	ft_init_image.c	*/

/*	ft_init_player.c	*/
double	ft_get_x_player(char **file, t_player *player);
double	ft_get_y_player(char **file, t_player *player);
double	ft_get_angle_player(char **file, t_player *player);

#endif