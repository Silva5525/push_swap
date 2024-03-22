/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:14:09 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/19 12:13:19 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t *save_load_png(const char *path, mlx_t *mlx)
{
	mlx_image_t		*image;
	mlx_texture_t 	*texture;

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

static void add_slice(t_anim *a, t_sprite *s, t_slice slice, int mirror)
{
	mlx_image_t	*content;
	int		i;
	int		j;

	i = 0;
	j = 0;
	content = mlx_new_image(s->mlx, slice.width, slice.height);
	if (!content)
		error(9);
	while (i < slice.height)
	{
		while (j < slice.width)
		{
			if (mirror)
				mlx_put_pixel(content,slice.height - j - 1, i, mlx_get_pixel(s->sprite, slice.x + j, + slice.y + i +1));
			else
				mlx_put_pixel(content, j, i, mlx_get_pixel(s->sprite, slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&a->frame, ft_lstnew(content));
}

t_anim	*slice_r(t_sprite *sprite, t_slice slices, int mirror)
{
	t_anim	*a;
	int				i;

	i = 0;
	a = (t_anim *)ft_calloc(sizeof(t_anim), 1);
	if (!a)
		error(9);
	while (i < 4)
	{
		add_slice(a, sprite, slices, mirror);
		slices.x += (int)slices.width;
		if (slices.x >= (int)sprite->sprite->width)
		{
			slices.x = 0;
			slices.y += slices.height;
		}
		i++;
	}
	return(a);
}

t_sprite	new_sprite(const char *path, mlx_t *mlx)
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
	mlx_delete_texture(texture);
	return((t_sprite){image, mlx});
}

t_hero	*first_hero(t_so_long *sl)
{
	t_hero		*hero;
	t_anim		*anim;
	t_sprite	sprite;
	int			i;

	i = 0;
	t_slice slices[4] = {
		(t_slice){0, 0, 23, 23},
    	(t_slice){47, 0, 23, 23},
   		(t_slice){95, 0, 23, 23},
   		(t_slice){143, 0, 23, 23}
	};
	hero = ft_calloc(sizeof(t_hero), 1);
	if (!hero)
		error(9);
	hero->x = sl->hero->width;
	hero->y = sl->hero->height;
	sprite = new_sprite("./images/hero.png", sl->mlx);
	while (i < 8)
	{
		bool mirror = i > 3;
		anim = slice_r(&sprite, slices[i % 4], mirror);
		ft_lstadd_back(&hero->hero_action, ft_lstnew(anim));
		i++;
	}
	destroy_sprite(&sprite);
	return(hero);
}