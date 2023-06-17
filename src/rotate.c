/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:32:48 by jose              #+#    #+#             */
/*   Updated: 2023/06/18 01:38:54 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turn(t_player *pl, double rs)
{
	double	tmp;

	tmp = pl->dirx;
	pl->dirx = pl->dirx * cos(-rs) - pl->diry * sin(-rs);
	pl->diry = tmp * sin(-rs) + pl->diry * cos(-rs);
	tmp = pl->planex;
	pl->planex = pl->planex * cos(-rs) - pl->planey * sin(-rs);
	pl->planey = tmp * sin(-rs) + pl->planey * cos(-rs);
}
