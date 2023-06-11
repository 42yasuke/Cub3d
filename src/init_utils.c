/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:46:44 by jose              #+#    #+#             */
/*   Updated: 2023/06/11 14:01:02 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_ceilling_and_floor_color(char *str, t_color *color)
{
	char	**line;
	char	**line2;
	int		i;

	i = -1;
	line = ft_spit(str, ' ');
	if (!line)
		return (ft_free_color(color));
	line2 = ft_split(line[1], ',');
	if (!line2)
		return (ft_free_all_str(line), ft_free_color(color));
	while(line2[++i])
	{
		if (line[1][0] == 'F')
			color->floor[i] = ft_atoi(line2[i]);
		else
			color->ceiling[i] = ft_atoi(line2[i]);
	}
}