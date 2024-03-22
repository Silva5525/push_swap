/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:03:15 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/22 14:03:31 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "libft/libft.h"

# define BPP sizeof(int32_t)

typedef struct s_anim
{
	t_list			*frame;
	long int		frame_count;
	int				mirror;
}	t_anim;

typedef struct s_hero
{
	int			x;
	int			y;
	int			i;
	bool		mirror;
	t_list		*hero_action;
}	t_hero;

typedef struct s_so_long
{
	mlx_t			*mlx;
	int				argc;
	char			**argv;
	mlx_image_t		*map_img;
	mlx_image_t		*first;
	mlx_image_t		*second;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*exit1;
	mlx_image_t		*exit2;
	mlx_image_t		*hero;
	mlx_image_t		*hero2;
	mlx_image_t		*gold;
	mlx_image_t		*slime;
	char			**map;
	int				map_height;
	int				map_width;
	int				fd;
}	t_so_long;

void		aktualization(void *param);
// rendering.c
void		rendering(t_so_long *sl);
int			read_map1(t_so_long *sl);
int			read_map2(t_so_long *sl);
int			map_correct(t_so_long *sl);
// fail_manager.c
void		error(int error_code);
void		end_cite(t_so_long *sl);
void		end_cite2(t_so_long *sl, int error_code);
void		mlx_img_to_img(mlx_image_t *dst, mlx_image_t *src, int x, int y);
int			mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y);
void		map_ok(t_so_long *sl);
// int32_t		mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y);
// big_util.c
mlx_image_t	*save_load_png(const char *path, mlx_t *mlx);
ssize_t		write(int fd, const void *buf, size_t count);
// wall_?.c
void		rendering2(t_so_long *sl);
void		counter_img(t_so_long *sl);

#endif
