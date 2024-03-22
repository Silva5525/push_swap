/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_?.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:10 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/19 14:39:48 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void rendering2(t_so_long *sl)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	z = sl->gold->instances[0].z;
	y = 0;
	while (sl->map_height > y)
	{
		x = 0;
		while (sl->map_width > x)
		{
			if (sl->map[y][x] == 'E')
				mlx_img_to_img(sl->first, sl->floor, x * 32, y * 32);
			if (sl->map[y][x] == '1')
				mlx_img_to_img(sl->first, sl->wall, x * 32, y * 32);
			if (sl->map[y][x] == '0' || sl->map[y][x] == 'P' )
				mlx_img_to_img(sl->first, sl->floor, x * 32, y * 32);
			if (sl->gold->instances[0].z == 0)
			{
				if (sl->map[y][x] == 'E')
				mlx_img_to_img(sl->first, sl->exit, x * 32, y * 32);
			}
			if (sl->map[y][x] == 'C')
			{
				mlx_img_to_img(sl->first, sl->gold, x * 32, y * 32);
				if (sl->map[sl->hero->instances[0].y / 32][sl->hero->instances[0].x / 32] == 'C')
				{
					sl->map[sl->hero->instances[0].y / 32][sl->hero->instances[0].x / 32] = '0';
					z--;
					sl->gold->instances[0].z = z;
				}	
			}
			x++;
		}
		y++;
	}
}

void	counter_img(t_so_long *sl)
{
	char	*str1;
	char	*str2;
	ft_printf("Steps: %d\n", sl->hero->instances[0].z);
	str1 = ft_itoa(sl->hero->instances[0].z);
	str1 = ft_strjoin("Steps: ", str1);
	str2 = ft_itoa(sl->gold->instances[0].z);
	str2 = ft_strjoin(" / Gold: ", str2);
	str1 = ft_strjoin(str1, str2);
	mlx_put_string(sl->mlx, str1, 0, 0);
	free(str1);
	free(str2);
}

void	update_all_anim(t_so_long *sl, t_anim *anim)
{
	if (anim)
	{
		anim->timer += sl->mlx->delta_time;
		if (anim->timer > anim->speed)
		{
			anim->timer = 0;
			anim->frame_count++;
			if (anim->frame_count >= ft_lstsize(anim->frame))
				anim->frame_count = 0;
		}
	}
}

void	dance_hero(void *l_hero, void *so_long)
{
	t_so_long		*sl = (t_so_long *)so_long;
	sl->list_hero	= l_hero;
	t_anim 			*hero_anim;
	int				i;
	mlx_image_t		*frame;

	i = sl->t_hero[0].i;
	hero_anim = (t_anim *)ft_lstget(sl->list_hero, i);
	frame = (mlx_image_t *)ft_lstget(hero_anim->frame, hero_anim->frame_count)->content;
	if (!frame)
		error(9);
	mlx_img_to_img(sl->first, frame, sl->t_hero[0].x, sl->t_hero[0].y);
	update_all_anim(sl, hero_anim);
}

void	mlx_img_to_img(mlx_image_t *dst, mlx_image_t *src, int x, int y)
{
	uint32_t	i;
	uint32_t	j;
	int	color;

	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			color = mlx_get_pixel(src, j, i);
			if (i < src->width && j < src->height)
				mlx_put_pixel(dst, x + j, y + i, color);
			j++;
		}
		i++;
	}
}