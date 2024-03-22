/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:04:33 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/22 14:04:36 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	if_1(t_so_long *sl, int x, int y, int z)
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
	return (0);
}

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

void	counter_img(t_so_long *sl)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	ft_printf("Steps: %d\n", sl->hero->instances[0].z);
	str1 = ft_itoa(sl->hero->instances[0].z);
	str3 = ft_strjoin("Steps: ", str1);
	str2 = ft_itoa(sl->gold->instances[0].z);
	str4 = ft_strjoin(" / Gold: ", str2);
	str5 = ft_strjoin(str3, str4);
	mlx_put_string(sl->mlx, str5, 0, 0);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
}

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
			color = mlx_get_pixel(src, j, i);
			mlx_put_pixel(dst, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
