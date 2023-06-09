/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:51:12 by jose              #+#    #+#             */
/*   Updated: 2023/06/09 21:21:36 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_verif_first_and_last_lines(char **file, int i_start, int i_end)
{
	int	j;

	j = -1;
	while (file[i_start][++j])
	{
		if (file[i_start][j] != ' ' || file[i_start][j] != '1')
			return (false);
	}
	j = -1;
	while (file[i_end][++j])
	{
		if (file[i_end][j] != ' ' || file[i_end][j] != '1')
			return (false);
	}
	return (true);
}

static int	ft_verif_first_and_last_char_of_each_line(char **file, int i_start)
{
	int		i;
	char	*line;
	char	*line2;

	i = i_start - 1;
	while (file[++i])
	{
		line = ft_strchr(file[i], '1');
		line2 = ft_strchr(file[i], '0');
		if (line2 < line)
			return (false);
		if (file[i][ft_strlen(file[i] - 1)] != '1' || \
		file[i][ft_strlen(file[i] - 1)] != ' ')
			return (false);
	}
	return (true);
}

static int	ft_verif_space_around_him(char **file, int i, int j)
{
	if (file[i - 1][j - 1] == ' ' || file[i - 1][j] == ' ' || \
	file[i - 1][j + 1] == ' ' || file[i][j - 1] == ' ' || \
	file[i][j] == ' ' || file[i][j + 1] == ' ' || \
	file[i + 1][j - 1] == ' ' || file[i + 1][j] == ' ' || \
	file[i + 1][j + 1] == ' ')
		return (false);
	return (true);
}

static int	ft_verif_all_0_and_the_player(char **file, int i_start, int i_end)
{
	int	i;
	int	j;

	i = i_start;
	while (++i != i_end)
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] == '0' || file[i][j] == 'N' || file[i][j] == 'S' || \
			file[i][j] == 'E' || file[i][j] == 'W')
			{
				if (!ft_verif_space_around_him(file, i, j))
					return (false);
			}
		}
	}
	return (true);
}

int	ft_map_closed(char **file, int i)
{
	int	i_start;

	i_start = i;
	while (file[i])
		i++;
	if (!ft_verif_first_and_last_lines(file, i_start, i - 1))
		return (false);
	if (!ft_verif_first_and_last_char_of_each_line(file, i_start))
		return (false);
	return (ft_verif_all_0_and_the_player(file, i_start, i -1));
}
