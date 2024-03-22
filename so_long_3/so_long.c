/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:02:50 by wdegraf           #+#    #+#             */
/*   Updated: 2024/03/22 14:02:53 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_so_long *sl;

void	if_hook1(mlx_t	*mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		end_cite(sl);
	if (sl->map[sl->slime->instances[0].y / 32]
		[sl->slime->instances[0].x / 32] 
		== sl->map[sl->hero->instances[0].y / 32]
		[sl->hero->instances[0].x / 32])
	{
		ft_write(1, "You are eaten by slime.\n", 25);
		end_cite(sl);
	}
	if (sl->gold->instances[0].z == 0
		&& sl->map[sl->hero->instances[0].y / 32]
		[sl->hero->instances[0].x / 32] == 'E')
	{
		ft_write(1, "You won\n", 8);
		end_cite(sl);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W)
		&& sl->map[sl->hero->instances[0].y / 32 - 1]
		[sl->hero->instances[0].x / 32] != '1')
	{
		sl->hero->instances[0].y -= 32;
		sl->hero->instances[0].z += 1;
	}
}

void	ft_hook2(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if_hook1(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S)
		&& sl->map[sl->hero->instances[0].y / 32 + 1]
		[sl->hero->instances[0].x / 32] != '1')
	{
		sl->hero->instances[0].y += 32;
		sl->hero->instances[0].z += 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A)
		&& sl->map[sl->hero->instances[0].y / 32]
		[sl->hero->instances[0].x / 32 - 1] != '1')
	{
		sl->hero->instances[0].x -= 32;
		sl->hero->instances[0].z += 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D)
		&& sl->map[sl->hero->instances[0].y / 32]
		[sl->hero->instances[0].x / 32 + 1] != '1')
	{
		sl->hero->instances[0].x += 32;
		sl->hero->instances[0].z += 1;
	}
}

void	aktualization(void *param)
{
	t_so_long	*sl;

	sl = param;
	ft_printf("Gold: %d\n", sl->gold->instances[0].z);
	usleep(90000);
	rendering2(sl);
	if (sl->hero->instances[0].enabled == true)
	{
		mlx_img_to_img(sl->first, sl->hero,
			sl->hero->instances[0].x, sl->hero->instances[0].y);
		sl->hero->instances[0].enabled = false;
	}
	else
	{
		mlx_img_to_img(sl->first, sl->hero2,
			sl->hero->instances[0].x, sl->hero->instances[0].y);
		sl->hero->instances[0].enabled = true;
	}
	mlx_img_to_img(sl->first, sl->slime,
		sl->slime->instances[0].x, sl->slime->instances[0].y);
	counter_img(sl);
	mlx_image_to_window(sl->mlx, sl->first, 0, 0);
}

void	create_game(t_so_long *sl)
{
	if (read_map1(sl) != 0)
		error(6);
	sl->mlx = mlx_init((sl->map_width * 32),
			(sl->map_height * 32), "so_long", true);
	if (!sl->mlx)
		error(3);
	sl->slime = save_load_png("./images/slime.png", sl->mlx);
	sl->wall = save_load_png("./images/wall32.png", sl->mlx);
	sl->floor = save_load_png("./images/floor32.png", sl->mlx);
	sl->hero = save_load_png("./images/hero1.png", sl->mlx);
	sl->hero2 = save_load_png("./images/hero2.png", sl->mlx);
	sl->hero->instances[0].z = 0;
	sl->hero->instances[0].enabled = true;
	sl->gold = save_load_png("./images/acoin.png", sl->mlx);
	sl->gold->instances[0].z = 0;
	sl->exit1 = save_load_png("./images/exit1.png", sl->mlx);
	sl->exit2 = save_load_png("./images/exit2.png", sl->mlx);
	sl->map_img = mlx_new_image(sl->mlx,
			sl->map_width * 32, sl->map_height * 32);
	sl->first = mlx_new_image(sl->mlx, sl->map_width * 32, sl->map_height * 32);
	rendering(sl);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error(1);
	sl = NULL;
	sl = ft_calloc(1, sizeof(t_so_long));
	if (!sl)
		error(2);
	sl->argc = argc;
	sl->argv = argv;
	create_game(sl);
	mlx_loop_hook(sl->mlx, aktualization, sl);
	mlx_loop_hook(sl->mlx, ft_hook2, sl->mlx);
	mlx_loop(sl->mlx);
	if (sl->gold->instances[0].z == 0)
		ft_write(1, "You won\n", 8);
	else
		ft_write(1, "Try Again\n", 10);
	end_cite(sl);
}
