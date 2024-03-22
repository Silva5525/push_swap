/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:24 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/19 14:32:13 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_correct(t_so_long *sl)
{
	char		*file_symbol;
	size_t		symbol_len;
	char		*line;
	
	line = sl->argv[1];
	file_symbol = ft_strrchr(line, '.');
	symbol_len = ft_strlen(line);
	if (line[symbol_len - 1] == '/')
		return (0);
	if (!file_symbol || ft_strncmp(file_symbol, ".ber", ft_strlen(file_symbol)) != 0)
		return (0);
	return (1);
}

int	read_map1(t_so_long *sl)
{
	char	*line;
	char	buf[2500];
	int 	i;
	int 	fd_leng;

	sl->map_height = 0;
	sl->map_width = 0;
	sl->fd = open(sl->argv[1], O_RDONLY);
	if (sl->fd < 0 || !map_correct(sl))
		error(2);
	while (1)
	{
		fd_leng = read(sl->fd, buf, 2500);
		if (fd_leng < 0)
			error(2);
		if (fd_leng == 0)
			break ;
		i = 0;
		line = ft_strchr(buf, '\n');
		sl->map_width =  line - buf;
		while (i < fd_leng)
		{
			if (buf[i] == '\n')
				sl->map_height++;
			i++;
		}
	}
	sl->map_height++;
	if (close(sl->fd) == -1)
		error(2);
	return (0);
}

static int	check_wall(t_so_long *sl)
{
	int 	i;

	i = 0;
	while (i < sl->map_width)
	{
		if (sl->map[0][i] != '1' || sl->map[sl->map_height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < sl->map_height)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->map_width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	read_map2(t_so_long *sl)
{
	int 	i;
	char	*line;
	
	i = 0;
	sl->map = ft_calloc((sl->map_height + 1), sizeof(char *));
	if (!sl->map)
		error(2);
	sl->fd = open(sl->argv[1], O_RDONLY);
	if ((sl->fd < 0))
	{
		free(sl->map);
		error(2);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(sl->fd);
		sl->map[i] = line;
		i++;
		if (!line)
			break ;
	}
	if (sl->map[0][0] == '\0'|| check_wall(sl) == 1)
	{
		free(sl->map);
		error(3);
	}
	if (close(sl->fd) == -1)
	{
		free(sl->map);
		error(2);
	}
	return (0);
}

void rendering(t_so_long *sl)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	sl->gold->instances[0].z = 0;
	y = 0;
	if (read_map2(sl) == -1)
		error(2);
	while (sl->map_height > y)
	{
		x = 0;
		while (sl->map_width > x)
		{
			if (sl->map[y][x] == '1')
			{
				mlx_img_to_img(sl->map_img, sl->wall, x * 32, y * 32);
			}
			if (sl->map[y][x] == '0')
			{
				mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
			}
			if (sl->map[y][x] == 'P')
			{
				sl->hero->instances[0].x = x * 32;
				sl->hero->instances[0].y = y * 32;
				mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
			}
			if (sl->map[y][x] == 'C')
			{
				mlx_img_to_img(sl->second, sl->gold, x * 32, y * 32);
				sl->gold->instances[z].enabled = 1;
				z++;
				mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
	sl->gold->instances[0].z = z;
}
