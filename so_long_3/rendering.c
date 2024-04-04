/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:05:55 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/03 17:12:22 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief checks if the argv[1] is a .ber
/// @param sl holds the data
/// @return 1 if its a .ber file, 0 if not
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
	if (!file_symbol || ft_strncmp(file_symbol,
			".ber", ft_strlen(file_symbol)) != 0)
		return (0);
	return (1);
}

/// @brief checks if the map is surrounded by walls
/// @param sl data struct
/// @return 0 if the map is surrounded by walls, 1 if not
static int	check_wall(t_so_long *sl)
{
	int	i;

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

/// @brief uses get_next_line to read the map 
/// and checks if the map is valid 
/// @param sl struct that holds the data
/// @return 0 if the map is valid else it uses end_cite2
/// to exit the program
int	read_map2(t_so_long *sl)
{
	int		i;
	char	*line;

	i = 0;
	sl->map = ft_calloc((sl->map_height + 1), sizeof(char *));
	if (!sl->map)
		end_cite2(sl, 9);
	sl->fd = open(sl->argv[1], O_RDONLY);
	if ((sl->fd < 0))
		end_cite2(sl, 9);
	i = 0;
	while (1)
	{
		line = get_next_line(sl->fd);
		sl->map[i] = line;
		i++;
		if (!line)
			break ;
	}
	if (sl->map[0][0] == '\0' || check_wall(sl) == 1)
		end_cite2(sl, 9);
	if (close(sl->fd) == -1)
		end_cite2(sl, 9);
	return (0);
}

/// @brief renders the map.. its just a extansion of rendering
/// @param sl struct that holds the data
/// @param x the x coordinate for the map double array
/// @param y the y coordinate for the map double array
static void	render_render(t_so_long *sl, int x, int y)
{
	if (sl->map[y][x] == 'E')
	{
		mlx_img_to_img(sl->map_img, sl->exit1, x * 32, y * 32);
		sl->exit1->instances[0].z = 1;
	}
	if (sl->map[y][x] == 'G')
	{
		sl->slime->instances[0].x = x * 32;
		sl->slime->instances[0].y = y * 32;
		mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
	}
	if (sl->map[y][x] == 'P')
	{
		sl->hero->instances[0].x = x * 32;
		sl->hero->instances[0].y = y * 32;
		sl->hero2->instances[0].z = 1;
		mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
	}
	if (sl->map[y][x] == 'C')
	{
		mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
		sl->gold->instances[0].z += 1;
	}
}

/// @brief reads the map and renders it the first time
/// @param sl struct that holds the data
void	rendering(t_so_long *sl)
{
	int	x;
	int	y;

	sl->exit1->instances[0].z = 0;
	sl->hero2->instances[0].z = 0;
	sl->gold->instances[0].z = 0;
	y = 0;
	if (read_map2(sl) == -1)
		end_cite2(sl, 9);
	while (sl->map_height > y)
	{
		x = 0;
		while (sl->map_width > x)
		{
			if (sl->map[y][x] == '1')
				mlx_img_to_img(sl->map_img, sl->wall, x * 32, y * 32);
			if (sl->map[y][x] == '0')
				mlx_img_to_img(sl->map_img, sl->floor, x * 32, y * 32);
			render_render(sl, x, y);
			x++;
		}
		y++;
	}
	map_ok(sl);
}
