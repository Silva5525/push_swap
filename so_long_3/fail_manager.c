/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:56:13 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/22 14:16:42 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int error_code)
{
	if (error_code == 1)
		ft_write(1, "Usage: ./so_long map/a_6.ber\n", 30);
	if (error_code == 2)
		ft_write(1, "Error\nMap is not correct\n", 26);
	if (error_code == 3)
		ft_write(1, "Error\nmlx_init failed\n", 23);
	if (error_code == 5 || error_code == 6 || error_code == 7)
		ft_write(1, "Error\nread_map failed\n", 23);
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	int		r;
	int		g;
	int		b;
	int		a;
	uint8_t	*pixel;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	pixel = image->pixels + (y * image->width + x) * BPP;
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	end_cite2(t_so_long *sl, int error_code)
{
	if (error_code == 9)
	ft_write(1, "Error Rendering\n", 17);
	mlx_terminate(sl->mlx);
	exit(EXIT_FAILURE);
}

void	end_cite(t_so_long *sl)
{
	mlx_terminate(sl->mlx);
	exit(EXIT_SUCCESS);
}

void	map_ok(t_so_long *sl)
{
	if (sl->hero2->instances[0].z == 0
		|| sl->exit1->instances[0].z == 0
		|| sl->gold->instances[0].z == 0)
	{
		ft_write(1, "Error\nMap is not correct\n", 26);
		end_cite(sl);
	}
}
