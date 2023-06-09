/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:51:12 by jose              #+#    #+#             */
/*   Updated: 2023/06/09 20:40:30 by jose             ###   ########.fr       */
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

int	ft_map_closed(char **file, int i)
{
	int	j;
	int	i_start;
	int	i_end;

	j = -1;
	i_start = i;
	while (file[i])
		i++;
	i_end = i - 1;
	if (!ft_verif_first_and_last_lines(file, i_start, i_end))
		return (false);
	if (!ft_verif_first_and_last_char_of_each_line(file, i_start))
		return (false);
	if (!ft_verif_all_0_and_the_player(file, i_start))
		retunr (false);
	return (true);
}
