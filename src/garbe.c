/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:22:30 by jralph            #+#    #+#             */
/*   Updated: 2023/10/31 21:22:46 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_garbe	*ft_get_garbe(void)
{
	static t_garbe	*garbe = NULL;

	if (!garbe)
	{
		garbe = malloc(sizeof(*garbe));
		if (!garbe)
			(ft_printf("Error: garbe malloc failed\n"), exit(EXIT_FAILURE));
		garbe->file = NULL;
		garbe->win = NULL;
	}
	return (garbe);
}
