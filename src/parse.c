/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:06:48 by marvin            #+#    #+#             */
/*   Updated: 2023/06/07 16:06:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_good_extension(char *str_file)
{
	int	i;

	i = 0;
	if (ft_strlen(str_file) < 4)
		return (false);
	while (str_file[i])
		i++;
	i--;
	if (str_file[i - 3] == '.' && str_file[i - 2] == 'c')
		if (str_file[i - 1] == 'u' && str_file[i] == 'b')
			return (true);
	return (false);
}

t_win	*ft_parsing_manager(char *str_file)
{
	char	**file;
	t_win	*win;

	win = NULL;
	file = ft_set_file(str_file);
	if (!ft_is_a_good_file(file))
		(ft_free_all_str(file), ft_error(BAD_PARAMETERS, str_file, NULL));
	return (win);
}
