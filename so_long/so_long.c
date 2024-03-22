/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:08:33 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/06 13:50:57 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static mlx_image_t *hero;

// void	game_update(void *ptr)
// {
// 	// static int	fps;
// 	mlx_image_t		*frame;
// 	t_so_long		*sl = (t_so_long*)ptr;

// 	memset(sl->first->pixels, 0xFF000000, sl->first->width * sl->first->height * BPP);
	
// }

void init_game(t_so_long  *sl)
{
	// t_sprite 		sprite;
	
	read_map1(sl);
	sl->mlx = mlx_init((sl->map_width * 32), (sl->map_height * 32), "so_long", false);
	if (!sl->mlx)
		error(14, (t_so_long *){0});
	sl->wall = save_load_png("./images/wall32.png", sl->mlx);
	sl->floor = save_load_png("./images/floor32.png", sl->mlx);
	// exit = save_load_png("./images/exit.png", mlx);
	// collectible = save_load_png("./images/collectible.png", mlx);
	// sl->hero = save_load_png("./images/hero.png", sl->mlx);
	// sprite = create_sprite("./images/hero.png", sl);
	// sl->hero_anim = choose_frame(&sprite, (t_sprite_slice){0, 0, 32, 32}, false, 4, 100);
	// destroy_sprite(&sprite);
	// sprite = create_sprite("./images/slime.png", mlx);
	// slime_anim = choose_frame(&sprite, (t_sprite_slice){0, 0, 32, 32}, false, 5, 100);
	// destroy_sprite(&sprite);
	rendering(sl);
}

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		hero->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		hero->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		hero->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		hero->instances[0].x += 5;
// }

int32_t	main(int argc, char **argv)
{
	t_so_long 	*sl = {0};

	sl = malloc(sizeof(t_so_long));
	if (!sl)
		error(1, sl);
	sl->argc = argc;
	sl->argv = argv;
	init_game(sl);
	my_hero(sl);
	// mlx_loop(sl.mlx, game_update, &sl);
	// mlx_loop_hook(sl.mlx, ft_hook, sl.mlx);
	mlx_loop(sl->mlx);
	// ft_lstclear(&sl.hero_anim->frames, bait);
	// ft_lstclear(&sl.hero_anim->frames, destroy_hero);
	// free(sl.hero_anim);
	mlx_terminate(sl->mlx);
	while (sl->map[sl->map_height])
	{
		free(sl->map[sl->map_height]);
		sl->map_height++;
		// should be sl->map_height--;
	}
	free(sl);
	return (EXIT_SUCCESS);
		
}