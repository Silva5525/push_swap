/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:16:56 by wdegraf           #+#    #+#             */
/*   Updated: 2023/12/19 17:00:54 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *out, char *hold)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest;
	int			count;
	int			i;
	int			j;

	j = 0;
	if (rest)
	{
		if (rest[0] == '\n')
			j++;
		while (rest[j] != '\0')
		{
			if (rest[j] == '\n')
			{
				out = ft_strdup(rest, 0, j);
				rest = ft_strdup(rest, j, 0);
				return (out);
			}
			j++;
		}
		if (j == 0)
			return (NULL);
		out = ft_strdup(rest, 0, j);
		free(rest);
		rest = NULL;
	}
	count = read(fd, 0, 0);
	while (count >= 0)
	{
		i = 0;
		j = read(fd, buffer, BUFFER_SIZE);
		if (j <= 0)
			return (NULL);
		count = j;
		buffer[j] = '\0';
		while (j > i && buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
			i++;
		hold = ft_strjoin(out, buffer, i);
		if (buffer[i - 1] == '\n')
		{
			rest = ft_strdup(buffer, i, 0);
			break ;
		}
		if (buffer[i] == '\0')
			break ;
	}
	return (hold);
}

char	*get_next_line(int fd)
{
	char			*out;
	static char		*rest;

	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	out = ft_read(fd, NULL, NULL);
	if (!out || out[0] == '\0')
	{
		free(out);
		free(rest);
		return (NULL);
	}
	return (out);
}
