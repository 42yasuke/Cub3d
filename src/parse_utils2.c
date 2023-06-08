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

int	ft_is_a_good_file(char **file)
{
	if (!ft_good_texture(file))
		return (false);
	if (!ft_is_good_map(file))
		return (false);
	retunr (true);
}
