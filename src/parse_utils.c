/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:40:09 by marvin            #+#    #+#             */
/*   Updated: 2023/06/07 23:40:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_init_file(char *str_file)
{
	int		fd;
	int		nbr_str;
	char	**file;
	char	*line;

	fd = open(str_file, O_RDONLY);
	if (fd == -1)
		ft_error(OPEN_FAILED, str_file, NULL);
	nbr_str = 0;
	line = get_next_line(fd);
	while (!line)
	{
		if (line[0] != '\n')
			nbr_str++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	file = malloc(sizeof(*file) * (nbr_str + 1));
	if (!file)
		ft_error(MALLOC_FAILED, "file : malloc failed", NULL);
	while (nbr_str > -1)
		file[nbr_str--] = NULL;
	return (file);
}

char	**ft_set_file(char *str_file)
{
	int		fd;
	int		nbr_str;
	char	**file;
	char	*line;

	file = ft_init_file(str_file);
	fd = open(str_file, O_RDONLY);
	if (fd == -1)
		ft_error(OPEN_FAILED, str_file, NULL);
	nbr_str = 0;
	line = get_next_line(fd);
	while (!line)
	{
		if (line[0] != '\n')
			file[nbr_str++] = line;
		free(line);
		line = get_next_line(fd);
	}
	return (file);
}
