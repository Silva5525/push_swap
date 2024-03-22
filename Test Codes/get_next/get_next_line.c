/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:23:33 by wdegraf           #+#    #+#             */
/*   Updated: 2023/12/19 18:25:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*single_line(t_file *file)
{
	char	*line;
	char	*hold;
	int		i;

	i = 0;
	while (file->content[i] != '\n' && file->content[i])
		i++;
	if (file->content[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	ft_memcpy(line, file->content, i);
	hold = ft_strdup(file->content + i);
	if (hold == NULL)
	{
		free(line);
		return (NULL);
	}
	free(file->content);
	file->content = hold;
	return (line);
}

static int	ft_read(int fd, t_file *file)
{
	int		ret;
	char	tmp[BUFFER_SIZE + 1];
	char	*hold;

	while (!ft_strchr(file->content, '\n') && !file->swich)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		file->swich = ret != BUFFER_SIZE;
		tmp[ret] = '\0';
		hold = ft_strjoin(file->content, tmp);
		if (hold == NULL)
			return (0);
		if (file->content != NULL)
			free(file->content);
		file->content = hold;
	}
	return (1);
}

char	*handle_file(int fd, int swich, t_file *file)
{
	if (!swich)
	{
		free(file->content);
		file->content = NULL;
		file->swich = 0;
		file->fd = -1;
	}
	else
		file->fd = fd;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_file	file[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (file[fd].fd)
		handle_file(fd, 1, &file[fd]);
	if (!file[fd].swich && !ft_read(fd, &file[fd]))
		return (handle_file(fd, 0, &file[fd]));
	if (file[fd].swich && file[fd].content[0] == '\0')
		return (handle_file(fd, 0, &file[fd]));
	line = single_line(&file[fd]);
	if (line == NULL)
		return (handle_file(fd, 0, &file[fd]));
	return (line);
}
