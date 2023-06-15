/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/06/15 00:25:50 by jose             ###   ########.fr       */
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
# define FPS 1000
# define FOV 60

/*	keybord's macro	*/
# define KEY_ESC 65307
# define KEY_Z 119
# define KEY_Q 97
# define KEY_D 100
# define KEY_S 115

/*	mouse's macro	*/
# define CROSS_BUTTON 1840902816

/*	image's macro	*/
# define BACKGROUND 1
# define NORTH 2
# define SOUTH 3
# define EAST 4
# define WEST 5

/*	error's macro*/
# define BAD_PARAMETERS 1
# define MALLOC_FAILED 2
# define MLX_INIT_FAILED 3
# define MLX_WIN_FAILED 4
# define OPEN_FAILED 5
# define MAP_NOT_VALID 6
# define BAD_EXTENSION 7
# define IMAGE_NOT_F 8
# define M_F "malloc failed"

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
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_player;

typedef struct s_ray
{
	double	cameraX;
	double	rayPosX;
	double	rayPosY;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
}	t_ray;

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
void	ft_add_all_image(t_win *win, char **file);

/*	ft_init_player.c	*/
double	ft_get_x_player(char **file);
double	ft_get_y_player(char **file);
double	ft_get_angle_player(char **file);
void	ft_get_plane(t_player *player);

/*	event.c	*/
int		ft_close_win(t_win *window);
int		ft_event_manager(int keycode, t_win *win);

/*	draw.c	*/
int		ft_draw_window(void *win);

/*	draw_utils.c	*/
char	ft_nbr_blue(int color);
char	ft_nbr_green(int color);
char	ft_nbr_red(int color);
char	ft_nbr_alpha(int color);
int		ft_bgr_into_int(int b, int g, int r);

/*	raycasting.c	*/
void	ft_raycast_manager(t_win *win);

#endif