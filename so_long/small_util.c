/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:53:40 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/06 15:34:33 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int errnum, t_so_long *sl) 
{
	int		i;

	i = sl->map_height - 1;
	if (!sl->map)
	{
		while (sl->map[i])
		{
			free(sl->map[i]);
			i--;
		}
	}
	free(sl->map);
	if (errnum == 15)
	{
		close(sl->fd);
		printf("map error\n");
	}
  puts(mlx_strerror(mlx_errno));
  exit(EXIT_FAILURE);
}

void	bait(void *ptr)
{
	(void)ptr;
}

// int put_pixel_valid(mlx_image_t* img, uint32_t x, uint32_t y)
// {
//     return (x < img->width && y < img->height);
// }

int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y)
{
  if (x > image->width || y > image->height)
    return 0xFF000000;
  uint8_t* pixelstart = image->pixels + (y * image->width + x) * BPP;
  return get_rgba(*(pixelstart), *(pixelstart + 1),
    * (pixelstart + 2), *(pixelstart + 3));
}

void	destroy_sprite(t_sprite *sprite)
{
	if (!sprite)
		error(1, (t_so_long *){0});
	mlx_delete_image(sprite->mlx, sprite->sprite_image);
}

static void	destroy_animation(void *ptr)
{
	t_anim	*animation;

	animation = (t_anim *)ptr;
	ft_lstclear(&animation->frames, bait);
	free(animation);
}

void	destroy_hero(void *ptr)
{
	t_hero	*hero;

	hero = (t_hero *)ptr;
	ft_lstclear(&hero->hero_action, destroy_animation);
	free(hero);
}

// void	destroy_slime(void *ptr)
// {
// 	t_hero	*hero;
// 	hero = (t_hero *)ptr;
// 	ft_lstclear(&slime->slime_action, destroy_animation);
// 	free(hero);
// }

void my_hero(t_so_long *sl)
{
	ft_lstadd_back(&sl->list_hero, ft_lstnew(do_hero("./images/hero.png", sl)));
}

t_list	*ft_lstget(t_list *lst, int index)
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = lst;
	if (index < 0 || !lst)
		return (NULL);
	while (tmp != NULL)
	{
		if (i >= index)
			return (tmp);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
