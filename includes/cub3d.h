/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/06/08 09:15:38 by marvin           ###   ########.fr       */
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

typedef struct s_wall
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_wall;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	t_data_img	*lst;
	char		**map;
	t_wall		*wall;
}	t_win;

/*	parse.c	*/
int		ft_good_extension(char *str_file);
t_win	*ft_parsing_manager(char *str_file);

/*	parse_utils.c	*/
char	**ft_set_file(char *str_file);

/*	parse_utils2.c	*/

/*	parse_utils3.c	*/
int		ft_good_texture(char **file);

/*	error.c	*/
void	ft_error(int err, char *err_msg, t_win *win);

/*	free.c	*/
void	ft_free_all_str(char **map);

#endif