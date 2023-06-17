/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:31:13 by jose              #+#    #+#             */
/*   Updated: 2023/06/18 00:38:31 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward(t_player *player, char **map)
{
	int	i;
	int	j;

	i = (int)player->posx;
	j = (int)(player->posy + player->diry * MOVESPEED);
	if (map[i][j] == '0')
		player->posy += player->diry * MOVESPEED;
	i = (int)(player->posx + player->dirx * MOVESPEED);
	j = (int)player->posy;
	if (map[i][j] == '0')
		player->posx += player->dirx * MOVESPEED;
}

void	ft_move_left(t_player *player, char **map)
{
	int	i;
	int	j;

	i = (int)(player->posx - player->planex * MOVESPEED);
	j = (int)player->posy;
	if (map[i][j] == '0')
		player->posx -= player->planex * MOVESPEED;
	i = (int)player->posx;
	j = (int)(player->posy - player->planey * MOVESPEED);
	if (map[i][j] == '0')
		player->posy -= player->planey * MOVESPEED;
}

void	ft_move_right(t_player *player, char **map)
{
	int	i;
	int	j;

	i = (int)(player->posx + player->planex * MOVESPEED);
	j = (int)player->posy;
	if (map[i][j] == '0')
		player->posx += player->planex * MOVESPEED;
	i = (int)player->posx;
	j = (int)(player->posy + player->planey * MOVESPEED);
	if (map[i][j] == '0')
		player->posy += player->planey * MOVESPEED;
}

void	ft_move_back(t_player *player, char **map)
{
	int	i;
	int	j;

	i = (int)player->posx;
	j = (int)(player->posy - player->diry * MOVESPEED);
	if (map[i][j] == '0')
		player->posy -= player->diry * MOVESPEED;
	i = (int)(player->posx - player->dirx * MOVESPEED);
	j = (int)player->posy;
	if (map[i][j] == '0')
		player->posx -= player->dirx * MOVESPEED;
}
