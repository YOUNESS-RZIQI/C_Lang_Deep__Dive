/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrziqi <yrziqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 05:59:38 by yrziqi            #+#    #+#             */
/*   Updated: 2025/11/16 05:28:35 by yrziqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	updat_lef_after_extract(int i, char **newline, char **leftover
	, char **new_leftover)
{
	if (!(*leftover)[i])
	{
		free(*leftover);
		*leftover = NULL;
	}
	else
	{
		*new_leftover = ft_strdup(*newline + 1);
		free(*leftover);
		*leftover = *new_leftover;
	}
}

static char	*get_line_from_leftover(char **leftover)
{
	char	*newline;
	char	*line;
	char	*new_leftover;
	int		i;

	newline = ft_strchr(*leftover, '\n');
	if (!newline)
		return (NULL);
	i = 0;
	while ((*leftover)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while ((*leftover)[++i] != '\n')
		line[i] = (*leftover)[i];
	line[i++] = '\n';
	line[i] = '\0';
	updat_lef_after_extract(i, &newline, leftover, &new_leftover);
	return (line);
}

static int	read_until_newline(int fd, char **leftover)
{
	char		*buffer;
	ssize_t		bytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*leftover), (*leftover) = NULL, -1);
	bytes = 1;
	while (1)
	{
		bytes = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (bytes == 0)
			return (free(buffer), 0);
		if (bytes == -1)
			return (free(buffer), free(*leftover), (*leftover) = NULL, -1);
		buffer[bytes] = '\0';
		(*leftover) = ft_strjoin((*leftover), buffer);
		if (!(*leftover))
			return (free(buffer), -1);
		if (ft_strchr((*leftover), '\n'))
			break ;
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);
	if (read_until_newline(fd, &leftover[fd]) == -1 || !leftover[fd])
		return (NULL);
	line = get_line_from_leftover(&leftover[fd]);
	if (line)
		return (line);
	line = ft_strdup(leftover[fd]);
	free(leftover[fd]);
	leftover[fd] = NULL;
	return (line);
}
