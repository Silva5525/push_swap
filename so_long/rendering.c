/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:24 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/06 17:52:51 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void rendering(t_so_long *sl)
{
	int	x;
	int	y;

	y = 0;
	if (read_map2(sl) == -1)
		error(15, sl);
	sl->the_hero = (t_hero *)malloc(sizeof(t_hero));
	if (!sl->the_hero)
		error(1, (t_so_long *){0});
	while (sl->map_height > y)
	{
		x = 0;
		while (sl->map_width > x)
		{
			if (sl->map[y][x] == '*')
			{
				mlx_image_to_window(sl->mlx, sl->wall, x * 32, y * 32);
			}
			if (sl->map[y][x] == ' ')
			{
				mlx_image_to_window(sl->mlx, sl->floor, x * 32, y * 32);
			}
			if (sl->map[y][x] == 'H')
			{
				sl->the_hero->x = x;
				sl->the_hero->y = y;
				mlx_image_to_window(sl->mlx, sl->, x * 32, y * 32);
			}
			// else if (map.map1[y][x] == 'E')
			// 	mlx_put_image_to_window(mlx, so_long->exit, x * 32, y * 32);
			// else if (map.map1[y][x] == 'C')
			// 	mlx_put_image_to_window(mlx, so_long->collectible, x * 32, y * 32);
			// else if (map.map1[y][x] == '&')
			// 	mlx_image_to_window(mlx, so_long->slime, x * 32, y * 32);
			x++;
		}
		// sl->map[y] = NULL;
		y++;
	}
	// sl->map = NULL;
}

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	map_correct(t_so_long *sl)
{
	char		*file_symbol;
	size_t		symbol_len;
	char		*line;
	
	line = sl->argv[1];
	file_symbol = ft_strrchr(line, '.');
	symbol_len = ft_strlen(line);
	if (line[symbol_len - 1] == '/')
		return (0);
	if (!file_symbol || ft_strcmp(file_symbol, ".ber") != 0)
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
		error(15, sl);
	while (1)
	{
		fd_leng = read(sl->fd, buf, 2500);
		if (fd_leng < 0)
			error(15, sl);
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
		error(1, sl);
	return (0);
}

int	read_map2(t_so_long *sl)
{
	int 	i;
	char	*line;
	
	i = 0;
	sl->map = ft_calloc((sl->map_height + 1), sizeof(char *));
	if (!sl->map)
		error(15, sl);
	sl->fd = open(sl->argv[1], O_RDONLY);
	if ((sl->fd < 0))
		error(15, sl);
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
		error(15, sl);
	if (close(sl->fd) == -1)
		error(1, sl);
	return (0);
}

int	check_wall(t_so_long *sl)
{
	int 	i;

	i = 0;
	while (i < sl->map_width)
	{
		if (sl->map[0][i] != '*' || sl->map[sl->map_height - 1][i] != '*')
			return (1);
		i++;
	}
	i = 0;
	while (i < sl->map_height)
	{
		if (sl->map[i][0] != '*' || sl->map[i][sl->map_width - 1] != '*')
			return (1);
		i++;
	}
	return (0);
}