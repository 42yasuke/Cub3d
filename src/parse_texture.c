/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:49:28 by jose              #+#    #+#             */
/*   Updated: 2023/06/09 19:49:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_research_bad_texture(char **file)
{
	int		i;
	char	**line;

	i = -1;
	while (file[++i])
	{
		line = ft_split(file[i], ' ');
		if (!line)
			ft_error(MALLOC_FAILED, "line : malloc failed");
		if (ft_strlen(line[0]) > 0 && \
			ft_strncmp(line[0], "NO", 2) && \
			ft_strncmp(line[0], "SO", 2) && \
			ft_strncmp(line[0], "EA", 2) && \
			ft_strncmp(line[0], "WE", 2) && \
			ft_strncmp(line[0], "F", 1) && \
			ft_strncmp(line[0], "C", 1) && \
			ft_strncmp(line[0], "0", 1) && \
			ft_strncmp(line[0], "1", 1))
			return (ft_free_all_str(line), false);
		ft_free_all_str(line);
	}
	return (true);
}

static int	ft_verif_texture(char **line, char *str, int *nb)
{
	int	fd;

	if (!*(str + 1) && (*str == 'F' || *str == 'C'))
		return (nb[0]++, true);
	if (line[1] && ft_strlen(str) == ft_strlen(line[0]) && !line[2])
	{
		nb[0]++;
		if (ft_strlen(str) == 2)
		{
			fd = open(line[1], O_RDONLY);
			if (fd == -1)
				return (false);
			close (fd);
		}
	}
	else
		return (false);
	return (true);
}

int	ft_research_texture(char *str, char **file)
{
	int		i;
	int		nb;
	char	**line;

	i = -1;
	nb = 0;
	if (!str)
		return (ft_research_bad_texture(file));
	while (file[++i])
	{
		line = ft_split(file[i], ' ');
		if (!line)
			ft_error(MALLOC_FAILED, "line : malloc failed");
		if (!ft_strncmp(line[0], str, ft_strlen(line[0])))
		{
			if (!ft_verif_texture(line, str, &nb))
				return (ft_free_all_str(line), false);
		}
		ft_free_all_str(line);
	}
	return (nb == 1);
}

int	ft_look_order(char **file)
{
	int		i;
	int		j;

	i = 0;
	while (file[i])
		i++;
	i--;
	j = -1;
	while (file[i][++j])
	{
		if (file[i][j] != ' ' && file[i][j] != '1')
			return (false);
	}
	return (true);
}
