/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:46:48 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/06 15:34:56 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite create_sprite(char *path, struct s_so_long *sl)
{
	mlx_image_t		*img;
	mlx_texture_t	*t;

	t = mlx_load_png(path);
	if (!t)
		error(1, (t_so_long *){0});
	img = mlx_texture_to_image(sl->mlx, t);
	if (!img)
		error(1, (t_so_long *){0});
	mlx_delete_texture(t);
	return ((t_sprite){img, sl->mlx});
}

static void frame(t_anim *animation, t_sprite *sprite, t_sprite_slice slice, int mirrored)
{
	mlx_image_t		*frame_img;
	int				i;
	int				j;

	j = 0;
	i = 0;
	frame_img = mlx_new_image(sprite->mlx, slice.width, slice.height);
	if (!frame_img)
		error(1, (t_so_long *){0});
	while (i < slice.height)
	{
		while (j < slice.width)
		{
			if (mirrored)
				mlx_put_pixel(frame_img,  slice.height - j - 1, i, mlx_get_pixel(sprite->sprite_image, slice.x + j, slice.y + i));
			else
				mlx_put_pixel(frame_img, j, i, mlx_get_pixel(sprite->sprite_image, slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&animation->frames, ft_lstnew(frame_img));
}

t_anim *choose_frame(t_sprite *sprite, t_sprite_slice slice, int mirrored, int frames, int wait)
{
	t_anim *animation;
	int			i;

	i = 0;
	animation = (t_anim *)malloc(sizeof(t_anim));
	if (!animation)
			error(1, &(t_so_long){0});
	*animation = (t_anim){NULL, wait, 0, 0, mirrored, 0, 0};
	while (i < frames)
	{
		frame(animation, sprite, slice, mirrored);
		slice.x += slice.width;
		if ((uint32_t)slice.x >= sprite->sprite_image->width)
		{
			slice.x = 0;
			slice.y += slice.height;
		}
		i++;
	}
	write(1, "choose_frame\n", 13);
	return (animation);
}

t_hero	*do_hero(char *path, struct s_so_long *sl)
{
	int				frame[4] = {1, 1, 1, 1};
	t_hero			*hero;
	t_anim			*hero_hold;
	t_sprite		hero_sprite;
	bool			mirror;
	int				i;

	i = 0;
	t_sprite_slice slices[4] = {
		{0, 0, 23, 23},
		{48, 0, 23, 23},
		{96, 0, 23, 23},
		{144, 0, 23, 23}
	};
	hero = (t_hero *)malloc(sizeof(t_hero));
	if (!hero)
		error(1, sl);

	hero->hero_action = (struct s_list *)1;
	hero->y = sl->the_hero->y;
	hero->x = sl->the_hero->x;
	hero_sprite = create_sprite(path, sl);
	while (i < 8)
	{
		mirror = i >= 4;
		hero_hold = choose_frame(&hero_sprite, slices[i % 4], mirror, frame[i % 4], 300);
		ft_lstadd_back(&hero->hero_action, ft_lstnew(hero_hold));
		i++;
	}
	write(1, "do_hero\n", 8);
	destroy_sprite(&hero_sprite);
	return (hero);
}

mlx_image_t *save_load_png(const char *path, mlx_t *mlx)
{
	mlx_image_t		*image;
	mlx_texture_t 	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error(1, (t_so_long *){0});
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		error(1, (t_so_long *){0});
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		error(1, (t_so_long *){0});
	mlx_delete_texture(texture);
	return (image);
}

// void  put_img_to_img(mlx_image_t* dst, mlx_image_t* src, int x, int y)
// {
//   int i;
//   int j;

//   i = 0;
//   while((const uint32_t)i < src->width) {
//     j = 0;
//     while ((const uint32_t)j < src->height) {
//       if (put_pixel_valid(src, i, j))
//         mlx_put_pixel(dst, x + i, y + j, mlx_get_pixel(src, i, j));
//       j++;
//     }
//     i++;
//   }
// }

// void update_hero(t_hero	*hero, t_so_long *sl)
// {
// 	t_anim	*animation;
// 	mlx_image_t	*frame;
// 	int		i;

// 	i = (int)(hero->hero_action - 1) + hero->mirrored;
// 	animation = (t_anim *)ft_lstget(hero->hero_action, i)->content;
// 	frame = (mlx_image_t *)ft_lstget(animation->frames, animation->current_frame)->content;
// 	if (!frame)
// 		error(1, sl);
// 	put_img_to_img(sl->first, frame, hero->x, hero->y);
// 	// update_animation(animation, sl->mlx->delta_time);
// 	/// here we need to check if hero is looking right or left and set mirrored to 1 or 0
// 	/// also if he is mooving up or down
// 	if (hero->hero_action != (struct s_list *)STAND)
// 	{
// 		if (hero->mirrored)
// 			hero->x -= 5;
// 		else
// 			hero->x += 5;
// 	}
// }

int get_rgba(int r, int g, int b, int a) 
{
  return (r << 24 | g << 16 | b << 8 | a);
}
