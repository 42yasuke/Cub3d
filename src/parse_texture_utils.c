/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:57:34 by jralph            #+#    #+#             */
/*   Updated: 2023/10/31 21:14:36 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (!(ft_strlen(line[1]) > 0 && ft_strlen(line[1]) < 4))
			return (ft_free_all_str(str), ft_free_all_str(line), false);
		if (!(ft_atoi(line[1]) > -1 && ft_atoi(line[1]) < 256))
			return (ft_free_all_str(str), ft_free_all_str(line), false);
	}
	return (ft_free_all_str(line), true);
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
			ft_verif_args_help(line);
		ft_free_all_str(line);
	}
	return (true);
}
