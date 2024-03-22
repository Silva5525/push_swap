/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:16:56 by wdegraf           #+#    #+#             */
/*   Updated: 2024/02/12 18:24:53 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/// @brief seperates the line from the content of the file struct
/// and returns it as a string. The content of the file struct is
/// updated accordingly.
/// @param file the file struct to be handled.
/// @return the line as a string or NULL if an error occurred.
static char	*seperate_line(t_struct *file)
{
	char		*line;
	char		*hold;
	size_t		i;

	i = 0;
	i = file->leng;
	if (file->content[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	ft_memcpy(line, file->content, i);
	hold = ft_strdup2(file->content + i, file->ret - i);
	if (!hold)
	{
		free(line);
		return (NULL);
	}
	free(file->content);
	file->content = hold;
	return (line);
}

/// @brief reads from the file descriptor and stores the content
/// in the file struct. Counts the number of bytes read and saves it in struct
/// ret and sets the swich if ret is not equal to BUFFER_SIZE,
/// file->swich is set to true (or 1), otherwise, it is set to false (or 0). 
/// @param fd the file descriptor to read from.
/// @param file struct to be handled.
/// @return 0 if an error occurred, 1 if the file was read successfully.
static int	ft_read(int fd, t_struct *file)
{
	ssize_t		ret;
	char		buf[BUFFER_SIZE + 1];
	char		*hold;

	ret = 0;
	file->ret = 0;
	if (file->content)
		file->ret = ft_strlen(file->content);
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (0);
		file->ret += ret;
		file->swich = ret != BUFFER_SIZE;
		buf[ret] = '\0';
		hold = ft_strjoin2(file, buf, ret);
		if (!hold)
			return (0);
		free(file->content);
		file->content = hold;
		file->leng = file->ret - (BUFFER_SIZE - ret);
		if (ft_strchr(buf, '\n') || file->swich)
			return (1);
	}
}

/// @brief frees the file struct and sets the file descriptor to -1
/// if to_be is 0. If to_be is 1 the struct-file descriptor is set 
/// to fd.
/// @param fd the file descriptor to read from
/// @param to_be the handle order to be executed
/// @param file struct to be handled
/// @return NULL to be returned by get_next_line after successful execution
char	*handle_file(int fd, int to_be, t_struct *file)
{
	if (!to_be)
	{
		free(file->content);
		file->content = NULL;
		file->swich = 0;
		file->ret = 0;
		file->fd = -1;
	}
	else
		file->fd = fd;
	return (NULL);
}

/// @brief gets the next line from a file descriptor and returns it as a string
/// if it is not empty.
/// @param BUFFER_SIZE is the number of bytes to read from the file descriptor.
/// @param fd is the file descriptor to read from.
/// @return the next line from the file descriptor as a string or NULL if there
/// is nothing left to read or an error occurred.
char	*get_next_line(int fd)
{
	static t_struct	file[1024];
	char			*out;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (file[fd].fd)
		handle_file(fd, 1, &file[fd]);
	if (!file[fd].swich && !ft_read(fd, &file[fd]))
		return (handle_file(fd, 0, &file[fd]));
	if (file[fd].swich && file[fd].content[0] == '\0')
		return (handle_file(fd, 0, &file[fd]));
	out = seperate_line(&file[fd]);
	if (!out)
		return (handle_file(fd, 0, &file[fd]));
	return (out);
}
