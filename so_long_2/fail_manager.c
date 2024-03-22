/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:31:19 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/19 14:38:22 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/include/MLX42/MLX42_Int.h"

void	error(int error_code)
{
	if (error_code == 1)
	write(1, "Usage: ./so_long map/***.ber\n", 30);
	else if (error_code == 2)
		write(1, "Error\nMap or rendering Problems\n", 33);
	else if (error_code == 3)
		write(1, "Error\nMap is not surrounded by walls or empty\n", 47);
	else if (error_code == 4)
		write(1, "Error\nmlx_init failed\n", 23);
	else if (error_code == 5 || error_code == 6 || error_code == 7)
		write(1, "Error\nmlx_load_png failed\n", 26);
	else if (error_code == 8)
		write(1, "Error\ndo_hero failed\n", 22);
	else if (error_code == 9)
		write(1, "Error\n the hero failed\n", 24);
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	destroy_sprite(t_sprite* sprite)
{
    if (!sprite)
        error(5);
    mlx_delete_image(sprite->mlx, sprite->sprite);
}

static int get_rgba(int r, int g, int b, int a)
{
  return (r << 24 | g << 16 | b << 8 | a);
}

int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y)
{
  if (x > image->width || y > image->height)
    return 0xFF000000;
  uint8_t* pixelstart = image->pixels + (y * image->width + x) * BPP;
  return get_rgba(pixelstart[0], pixelstart[1], pixelstart[2], pixelstart[3]);
}

void	end_cite(t_so_long *sl)
{
	
	mlx_terminate(sl->mlx);
	while (sl->map[sl->map_height])
	{
		printf("end_cite\n");
		free(sl->map[sl->map_height]);
		sl->map_height++;
	}
	free(sl->map);
	free(sl);
	exit(EXIT_SUCCESS);
}