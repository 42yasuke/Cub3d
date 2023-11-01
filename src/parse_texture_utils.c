/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:57:34 by jralph            #+#    #+#             */
/*   Updated: 2023/11/01 15:18:08 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}

static int	ft_verif_args_help(char **str)
{
	char	**line;
	int		i;

	i = -1;
	line = ft_split(str[1], ',');
	if (!line)
		(ft_free_all_str(str), ft_error(MALLOC_FAILED, M_F, NULL));
	while (line[++i])
	{
		if (!(ft_strlen(line[i]) > 0 && ft_strlen(line[i]) < 4))
			return (ft_free_all_str(str), ft_free_all_str(line), false);
		if (!ft_check_digit(line[i]))
			return (ft_free_all_str(str), ft_free_all_str(line), false);
		if (!(ft_atoi(line[i]) > -1 && ft_atoi(line[i]) < 256))
			return (ft_free_all_str(str), ft_free_all_str(line), false);
	}
	return (ft_free_all_str(line), true);
}

static void	ft_stick(char **file, char **line, int i)
{
	char	*new_line;
	char	*tmp;
	int		j;

	j = -1;
	new_line = NULL;
	while (line[++j])
	{
		tmp = new_line;
		if (!j)
			new_line = ft_strjoin(line[j], " ");
		else
			new_line = ft_strjoin(new_line, line[j]);
		free(tmp);
		if (!new_line)
			(ft_free_all_str(line), ft_error(MALLOC_FAILED, M_F, NULL));
	}
	tmp = file[i];
	file[i] = new_line;
	free(tmp);
}

int	ft_verif_args(char *str, char **file)
{
	int		i;
	char	**line;

	i = -1;
	while (file[++i])
	{
		line = ft_split(file[i], ' ');
		if (!line)
			ft_error(MALLOC_FAILED, M_F, NULL);
		if (!ft_strncmp(line[0], str, ft_strlen(str)))
		{
			(ft_stick(file, line, i), ft_free_all_str(line));
			line = ft_split(file[i], ' ');
			if (!ft_verif_args_help(line))
				return (false);
		}
		ft_free_all_str(line);
	}
	return (true);
}
