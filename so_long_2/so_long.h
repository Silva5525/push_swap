/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:09:39 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/19 12:01:43 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "libft/libft.h"

// enum e_hero_move
// {
// 	STAND = 1,
// 	Go1 = 2,
// 	Go2 = 3,
// 	Go3 = 4
// };

typedef struct 		s_slice
{
	int 			x;
	int 			y;
	int 			width;
	int 			height;
}	t_slice;

typedef struct 		s_sprite
{
	mlx_image_t		*sprite;
	mlx_t			*mlx;
}	t_sprite;

typedef struct 		s_anim
{
	t_list			*frame;
	long int		frame_count;
	int				mirror;
	int				timer;
	double 			speed;
}	t_anim;

typedef struct 		s_hero
{
	int 			x;
	int 			y;
	int 			i;
	bool 			mirror;
	t_list 			*hero_action;
}	t_hero;

typedef struct 		s_so_long 
{
	mlx_t			*mlx;
	int 			argc;
	char			**argv;
	t_list			*list_hero;	
	mlx_image_t		*the_hero;
	mlx_image_t		*map_img;
	mlx_image_t		*first;
	mlx_image_t		*second;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*exit;
	mlx_image_t		*hero;
	mlx_image_t		*hero2;
	mlx_image_t		*gold;
	char			**map;
	int				map_height;
	int				map_width;
	int 			fd;
	t_anim			*hero_anim;
	t_hero			*t_hero;
}	t_so_long;

void		aktualization(void* param);
// rendering.c
void		rendering(t_so_long *sl);
int			read_map1(t_so_long *sl);
void		aktual_map(t_so_long *sl);
// fail_manager.c
void		error(int error_code);
void		end_cite(t_so_long *sl);
void    	destroy_sprite(t_sprite* sprite);
void		mlx_img_to_img(mlx_image_t* dst, mlx_image_t* src, int x, int y);
int32_t 	mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y);
// big_util.c
mlx_image_t *save_load_png(const char *path, mlx_t *mlx);
t_hero		*first_hero(t_so_long *sl);
t_sprite	new_sprite(const char *path, mlx_t *mlx);
t_anim		*slice_r(t_sprite *sprite, t_slice slices, int mirror);
// wall_?.c
void		rendering2(t_so_long *sl);
void		open_door(t_so_long *sl);
void		counter_img(t_so_long *sl);
void		dance_hero(void *l_hero, void *so_long);
void		update_all_anim(t_so_long *sl, t_anim *anim);

#endif
