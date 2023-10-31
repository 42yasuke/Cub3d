/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:47:10 by marvin            #+#    #+#             */
/*   Updated: 2023/06/07 23:47:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_there_is_only_digit(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (!ft_isdigit(str[i][j]))
				return (false);
		}
	}
	return (true);
}

int	ft_get_map(char **file)
{
	int		i;
	char	**line_whithout_space;

	i = -1;
	line_whithout_space = NULL;
	while (file[++i])
	{
		if (ft_strchr(file[i], '1'))
		{
			line_whithout_space = ft_split(file[i], ' ');
			if (!line_whithout_space)
				return (-1);
			if (ft_there_is_only_digit(line_whithout_space))
				break ;
			ft_free_all_str(line_whithout_space);
		}
	}
	ft_free_all_str(line_whithout_space);
	return (i);
}

static int	ft_map_verif_player(char **file, int i)
{
	static int	nb_n = 0;
	static int	nb_s = 0;
	static int	nb_e = 0;
	static int	nb_w = 0;
	int			j;

	i--;
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == 'N')
				nb_n++;
			else if (file[i][j] == 'S')
				nb_s++;
			else if (file[i][j] == 'E')
				nb_e++;
			else if (file[i][j] == 'W')
				nb_w++;
		}
	}
	return (nb_n + nb_s + nb_e + nb_w == 1);
}

static int	ft_is_good_map(char **file)
{
	int	i;

	i = ft_get_map(file);
	if (i == -1)
		ft_error(MALLOC_FAILED, "malloc failed", NULL);
	if (!file[i])
		return (false);
	if (!ft_map_closed(file, i))
		return (false);
	return (ft_map_verif_player(file, i));
}

int	ft_is_a_good_file(char **file)
{
	if (!ft_good_texture(file))
		return (ft_printf("Error: bad textures\n"), false);
	if (!ft_is_good_map(file))
		return (ft_printf("Error: bad map\n"), false);
	return (true);
}
