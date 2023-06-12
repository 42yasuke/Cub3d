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
	while (line)
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

static void	ft_cpy(char **file, int *nbr_str, char *line)
{
	char	*str;

	file[nbr_str[0]] = ft_strdup(line);
	if (!file[nbr_str[0]])
	{
		free(line);
		ft_free_all_str(file);
		ft_error(MALLOC_FAILED, M_F, NULL);
	}
	str = ft_strchr(file[nbr_str[0]], '\n');
	if (str)
		str[0] = '\0';
	nbr_str[0]++;
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
	while (line)
	{
		if (line[0] != '\n')
			ft_cpy(file, &nbr_str, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file);
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
