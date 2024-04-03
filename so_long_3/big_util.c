/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:00:38 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/26 14:31:07 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*save_load_png(const char *path, mlx_t *mlx)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error(5);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		error(6);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_delete_texture(texture);
		mlx_delete_image(mlx, image);
		error(7);
	}
	mlx_delete_texture(texture);
	return (image);
}

static void	read_i(int i, t_so_long *sl, char *line)
{
	int			fd_leng;
	char		buf[2500];

	while (1)
	{
		fd_leng = read(sl->fd, buf, 2500);
		if (fd_leng <= 0 && i == -1)
		{
			close(sl->fd);
			error(6);
		}
		if (fd_leng == 0)
			break ;
		i = 0;
		line = ft_strchr(buf, '\n');
		sl->map_width = line - buf;
		while (i < fd_leng)
		{
			if (buf[i] == '\n')
				sl->map_height++;
			i++;
		}
	}
}

int	read_map1(t_so_long *sl)
{
	sl->map_height = 0;
	sl->map_width = 0;
	sl->fd = open(sl->argv[1], O_RDONLY);
	if (sl->fd < 0 || !map_correct(sl))
	{
		close(sl->fd);
		error(6);
	}
	read_i(-1, sl, NULL);
	sl->map_height++;
	if (close(sl->fd) == -1)
		error(6);
	return (0);
}
