/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:10:16 by jralph            #+#    #+#             */
/*   Updated: 2023/10/31 15:03:16 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getlines(char *stash)
{
	char	*res;

	res = ft_strdup(stash);
	if (!res)
		return (NULL);
	return (res);
}

static void	ft_loop(char **stash, int fd)
{
	char		*tmp;
	int			len;
	char		*buf;

	len = BUFFER_SIZE;
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (!ft_strchr(*stash, '\n') && len == BUFFER_SIZE)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		tmp = *stash;
		*stash = ft_strjoin(tmp, buf);
		if (!*stash)
		{
			*stash = NULL;
			free(tmp);
			return (free(buf));
		}
		free(tmp);
	}
	free(buf);
}

static char	*ft_last_line(char **stash)
{
	char	*lines;

	lines = ft_strdup(*stash);
	if (!lines)
		return (NULL);
	return (free(*stash), *stash = NULL, lines);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*lines;

	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_loop(&stash, fd);
	if (ft_strchr(stash, '\n'))
	{
		lines = ft_getlines(stash);
		if (!lines)
			return (free(stash), NULL);
		return (free(stash), stash = NULL, lines);
	}
	else if (stash && *stash)
		return (ft_last_line(&stash));
	return (free(stash), stash = NULL, NULL);
}
