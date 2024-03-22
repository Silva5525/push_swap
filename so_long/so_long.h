/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:22:36 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/05 18:41:30 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "libft/libft.h"

#define WID 2240
#define HEIG 672
// #define WID 96
// #define HEIG 96
#define BPP sizeof(int32_t)

typedef struct s_sprite_slice
{
	int x;
	int y;
	int width;
	int height;
}	t_sprite_slice;

typedef struct s_sprite
{
	mlx_image_t	*sprite_image;
	mlx_t		*mlx;
}	t_sprite;

enum e_hero_move
{
	STAND = 1,
	Go1 = 2,
	Go2 = 3,
	Go3 = 4
};

typedef struct s_anim 
{
	t_list		*frames;
	int			speed;
	double		accumulated_time;
	int			current_frame;
	int			mirrored;
	long int	when_updated;
	long int	count;
}	t_anim;

// enum e_slime_move
// {
// 	STAND = 1,
// 	Go1 = 2,
// 	Go2 = 3,
// 	Go3 = 4,
// 	Go4 = 5
// };

typedef struct s_animation
{
	mlx_image_t	*hero;
}	t_animation;

typedef struct s_hero 
{
	int32_t				x;
	int32_t				y;
	enum e_hero_move	hero_move;
	bool				mirrored;
	t_list				*hero_action;
}	t_hero;

typedef struct s_so_long 
{
	mlx_t			*mlx;
	int 			argc;
	char			**argv;
	t_hero			*the_hero;
	t_list			*list_hero;	
	// t_list			*the_slime;
	// mlx_image_t		*exit;
	// mlx_image_t		*collectible;
	mlx_image_t		*first;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*hero;
	char			**map;
	int				map_height;
	int				map_width;
	int 			fd;
	// mlx_image_t		*slime;
	t_anim			*hero_anim;
	// t_anim			*slime_anim;

}	t_so_long;

///small_util.c
// int put_pixel_valid(mlx_image_t* img, uint32_t x, uint32_t y);
t_list	*ft_lstget(t_list *lst, int index);
int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y);
void	destroy_hero(void *ptr);
void	my_hero(t_so_long *sl);
void	destroy_sprite(t_sprite *sprite);
void	bait(void *ptr);
void	error(int errnum, t_so_long *sl);
// static void	destroy_animation(void *ptr);
///big_util.c
t_sprite create_sprite(char *path, struct s_so_long *sl);
t_anim *choose_frame(t_sprite *sprite, t_sprite_slice slice, int mirrored, int frames, int wait);
// static void add_frame(t_anim *animation, t_sprite *sprite, t_sprite_slice slice, int mirrored);
void  put_img_to_img(mlx_image_t* dst, mlx_image_t* src, int x, int y);
t_hero	*do_hero(char *path, t_so_long *sl);
mlx_image_t *save_load_png(const char *path, mlx_t *mlx);
void update_hero(t_hero	*hero, t_so_long *sl);
int get_rgba(int r, int g, int b, int a);
///rendering.c
void rendering(t_so_long *sl);
int	read_map1(t_so_long *sl);
int	read_map2(t_so_long *sl);
int	map_correct(t_so_long *sl);
int	check_wall(t_so_long *sl);

///so_long.c
void init_game(t_so_long  *sl);
void ft_hook(void* param);

#endif