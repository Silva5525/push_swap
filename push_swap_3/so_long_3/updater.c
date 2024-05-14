/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:10 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/03 17:14:22 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief extends the function rendering2 
/// @param sl the struct that holds the data
/// @param x parameter x in the while loop
/// @param y parameter y in the while loop
/// @param z for the gold instances
static void	if_1(t_so_long *sl, int x, int y, int z)
{
	if (sl->map[y][x] == '0' || sl->map[y][x] == 'P'
	|| sl->map[y][x] == 'G')
		mlx_img_to_img(sl->first, sl->floor, x * 32, y * 32);
	if (sl->gold->instances[0].z == 0)
		if (sl->map[y][x] == 'E')
			mlx_img_to_img(sl->first, sl->exit2, x * 32, y * 32);
	if (sl->map[y][x] == 'C')
	{
		mlx_img_to_img(sl->first, sl->gold, x * 32, y * 32);
		if (sl->map[sl->hero->instances[0].y / 32]
			[sl->hero->instances[0].x / 32] == 'C')
		{
			sl->map[sl->hero->instances[0].y / 32]
			[sl->hero->instances[0].x / 32] = '0';
			z--;
			sl->gold->instances[0].z = z;
		}
	}
}

/// @brief the second rendering function that renders the map while the game
/// is running. 
/// @param sl struct that holds the data
void	rendering2(t_so_long *sl)
{
	int	x;
	int	y;
	int	z;

	z = sl->gold->instances[0].z;
	y = 0;
	while (sl->map_height > y)
	{
		x = 0;
		while (sl->map_width > x)
		{
			if (sl->map[y][x] == 'E' && sl->gold->instances[0].z != 0)
			{
				mlx_img_to_img(sl->first, sl->floor, x * 32, y * 32);
				mlx_img_to_img(sl->first, sl->exit1, x * 32, y * 32);
			}
			if (sl->map[y][x] == '1')
				mlx_img_to_img(sl->first, sl->wall, x * 32, y * 32);
			if_1(sl, x, y, z);
			x++;
		}
		y++;
	}
}

/// @brief It retrieves the color of a pixel at the given coordinates and
/// returns it as an integer in the format 0xRRGGBBAA for further processing
/// in the function img_to_img.
/// @param image the image struct
/// @param x position x = j in the while loop of img_to_img
/// @param y position y = i in the while loop of img_to_img
/// @return the color of the pixel
static int	pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	int		r;
	int		g;
	int		b;
	int		a;
	uint8_t	*pixel;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	pixel = image->pixels + (y * image->width + x) * sizeof(uint32_t);
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	return (r << 24 | g << 16 | b << 8 | a);
}

/// @brief puts the color of a pixel at the given coordinates from the source
/// image to the destination image.
/// @param dst destination image {mostly the window image}
/// @param src source image {mostly the different pictures}
/// @param x destination x coordinates
/// @param y destination y coordinates
void	mlx_img_to_img(mlx_image_t *dst, mlx_image_t *src, int x, int y)
{
	uint32_t	i;
	uint32_t	j;
	int			color;

	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			color = pixel(src, j, i);
			mlx_put_pixel(dst, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
