/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:14:09 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/03 16:48:08 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief loads the png file to a texture struct and saves it in a image struct
/// if something went wrong it uses the error function to exit the program and 
/// puts it out once on the window to check if everything is working
/// @param path the png file path
/// @param mlx struct that holds the window data
/// @return image struct
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
		error(5);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_delete_texture(texture);
		mlx_delete_image(mlx, image);
		error(5);
	}
	mlx_delete_texture(texture);
	return (image);
}

/// @brief extends the function read_map1
/// @param i -1 for the while loop.. whenn its 0 the map is empty
/// becouse its the first read
/// @param sl struct that holds the data
/// @param line a pointer to the line where the '\n' is to suptract
/// the map width
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

/// @brief first read of the map to get the map height and width
/// @param sl struct that holds the data
/// @return 0 if the map is valid else it uses end_cite2 to exit the program
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
