/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:37 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/19 14:33:59 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_so_long *sl;

void ft_hook2(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (sl->t_hero->i < 4)
	// 	sl->t_hero->i++;
	// else
	// 	sl->t_hero->i = 0;
	if (sl->gold->instances[0].z == 0
	&& sl->map[sl->hero->instances[0].y / 32][sl->hero->instances[0].x / 32] == 'E')
					end_cite(sl);
	if (mlx_is_key_down(mlx, MLX_KEY_W)
	&& sl->map[sl->hero->instances[0].y / 32 - 1][sl->hero->instances[0].x / 32] != '1')
	{
		// sl->hero->instances[0].y -= 16;
		// aktualization(sl);
		sl->hero->instances[0].y -= 32;
		sl->hero->instances[0].z += 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S)
	&& sl->map[sl->hero->instances[0].y / 32 + 1][sl->hero->instances[0].x / 32] != '1')
	{
		// sl->hero->instances[0].y += 16;
		// aktualization(sl);
		sl->hero->instances[0].y += 32;
		sl->hero->instances[0].z += 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A)
	&& sl->map[sl->hero->instances[0].y / 32][sl->hero->instances[0].x / 32 - 1] != '1')
	{
		// sl->hero->instances[0].x -= 16;
		// aktualization(sl);
		sl->hero->instances[0].x -= 32;
		sl->hero->instances[0].z += 1;
		// sl->t_hero->mirror = 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D)
	&& sl->map[sl->hero->instances[0].y / 32][sl->hero->instances[0].x / 32 + 1] != '1')
	{
		// sl->hero->instances[0].x += 16;
		// aktualization(sl);
		sl->hero->instances[0].x += 32;
		sl->hero->instances[0].z += 1;
		// sl->t_hero->mirror = 0;
	}
}

void aktualization(void* param)
{
	mlx_img_to_img(sl->first, sl->map_img, 0, 0);
	
	rendering2((t_so_long *)param);
	mlx_img_to_img(sl->first, sl->hero, sl->hero->instances[0].x, sl->hero->instances[0].y);
	ft_printf("Gold: %d\n", sl->gold->instances[0].z);
	counter_img(sl); 
	// ft_lstiter_ptr((void *)sl->list_hero, (void *)dance_hero, (void *)sl);
	
	mlx_image_to_window(sl->mlx, sl->first, 0, 0);
}

void create_game(t_so_long *sl)
{
	read_map1(sl);
	sl->mlx = mlx_init((sl->map_width * 32), (sl->map_height * 32), "so_long", true);
	if (!sl->mlx)
		error(4);
	sl->wall = save_load_png("./images/wall32.png", sl->mlx);
	sl->floor = save_load_png("./images/floor32.png", sl->mlx);
	sl->hero = save_load_png("./images/hero1.png", sl->mlx);
	sl->hero->instances[0].z = 0;
	sl->gold = save_load_png("./images/acoin.png", sl->mlx);
	sl->gold->instances[0].z = 0;
	sl->exit = save_load_png("./images/exit.png", sl->mlx);
	sl->map_img = mlx_new_image(sl->mlx, sl->map_width * 32, sl->map_height * 32);
	sl->first = mlx_new_image(sl->mlx, sl->map_width * 32, sl->map_height * 32);
	sl->second = mlx_new_image(sl->mlx, sl->map_width * 32, sl->map_height * 32);
	rendering(sl);
}

int main(int argc, char **argv)
{
	sl = (t_so_long *)malloc(sizeof(t_so_long));
	if (argc != 2)
		error(1);
	sl->argc = argc;
	sl->argv = argv;
	create_game(sl);
	// sl->t_hero = first_hero(sl);
	// ft_lstadd_back(&sl->list_hero,
	// ft_lstnew(the_hero("./images/hero.png", sl)));
	// ft_lstadd_back(&sl->list_hero,
	// ft_lstnew(first_hero(sl)));
	mlx_loop_hook(sl->mlx, aktualization, sl);
	mlx_loop_hook(sl->mlx, ft_hook2, sl->mlx);
	mlx_loop(sl->mlx);
	// ft_lstclear(&sl->list_hero_action, free);
	// ft_lstclear(&sl->list_hero, free);
	end_cite(sl);
}
