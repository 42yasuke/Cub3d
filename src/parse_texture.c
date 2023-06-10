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
			ft_error(MALLOC_FAILED, "line : malloc failed", NULL);
		if (ft_strncmp(line[0], "NO", 2) && \
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

static int	ft_research_texture(char *str, char **file)
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
			ft_error(MALLOC_FAILED, "line : malloc failed", NULL);
		if (!ft_strncmp(line[0], str, ft_strlen(str)))
		{
			if (line[1] && ft_strlen(str) == ft_strlen(line[0]) && !line[2]) //open(line[1]) ?
				nb++;
			else
				return (ft_free_all_str(line), false);
		}
		ft_free_all_str(line);
	}
	return (nb == 1);
}

static int	ft_look_order(char **file)
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

static int	ft_verif_args(char *str, char **file)
{
	int		i;
	int		i2;
	char	**l;
	char	**l2;

	i = -1;
	i2 = -1;
	while (file[++i])
	{
		l = ft_split(file[i], ' ');
		if (!ft_strncmp(l[0], str, ft_strlen(str)))
		{
			l2 = ft_split(l[1], ',');
			while (l2[++i2])
			{
				if (!(ft_strlen(l2[1]) > 0 && ft_strlen(l2[1]) < 4))
					return (ft_free_all_str(l), ft_free_all_str(l2), false);
				if (!(ft_atoi(l2[1]) > -1 && ft_atoi(l2[1]) < 256))
					return (ft_free_all_str(l), ft_free_all_str(l2), false);
			}
			ft_free_all_str(l2);
		}
		ft_free_all_str(l);
	}
	return (true);
}

int	ft_good_texture(char **file)
{
	if (!ft_research_texture("NO", file))
		return (false);
	if (!ft_research_texture("SO", file))
		return (false);
	if (!ft_research_texture("EA", file))
		return (false);
	if (!ft_research_texture("WE", file))
		return (false);
	if (!ft_research_texture("F", file))
		return (false);
	if (!ft_research_texture("C", file))
		return (false);
	if (!ft_research_texture(NULL, file))
		return (false);
	if (!ft_verif_args("F", file) || !ft_verif_args("C", file))
		return (false);
	if (!ft_look_order(file))
		return (false);
	return (true);
}
