/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:48:37 by wdegraf           #+#    #+#             */
/*   Updated: 2024/04/07 21:27:02 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_so_long		*g_sl;

/// @brief extends the function ft_hook2
/// @param mlx the mlx struct
void	if_hook1(mlx_t	*mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		end_cite(g_sl);
	if (g_sl->map[g_sl->slime->instances[0].y / 32]
		[g_sl->slime->instances[0].x / 32]
		== g_sl->map[g_sl->hero->instances[0].y / 32]
		[g_sl->hero->instances[0].x / 32])
	{
		write(1, "You are eaten by slime.\n", 25);
		end_cite(g_sl);
	}
	if (g_sl->gold->instances[0].z == 0
		&& g_sl->map[g_sl->hero->instances[0].y / 32]
		[g_sl->hero->instances[0].x / 32] == 'E')
	{
		write(1, "You won\n", 8);
		end_cite(g_sl);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W)
		&& g_sl->map[g_sl->hero->instances[0].y / 32 - 1]
		[g_sl->hero->instances[0].x / 32] != '1')
	{
		g_sl->hero->instances[0].y -= 32;
		g_sl->hero->instances[0].z += 1;
	}
}

/// @brief is the key hook function that checks for the key inputs
/// @param param is the game data like the g_sl struct.. just 
/// void param because of the mlx_loop_hook which is used to call it.
void	ft_hook2(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if_hook1(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_S)
		&& g_sl->map[g_sl->hero->instances[0].y / 32 + 1]
		[g_sl->hero->instances[0].x / 32] != '1')
	{
		g_sl->hero->instances[0].y += 32;
		g_sl->hero->instances[0].z += 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A)
		&& g_sl->map[g_sl->hero->instances[0].y / 32]
		[g_sl->hero->instances[0].x / 32 - 1] != '1')
	{
		g_sl->hero->instances[0].x -= 32;
		g_sl->hero->instances[0].z += 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D)
		&& g_sl->map[g_sl->hero->instances[0].y / 32]
		[g_sl->hero->instances[0].x / 32 + 1] != '1')
	{
		g_sl->hero->instances[0].x += 32;
		g_sl->hero->instances[0].z += 1;
	}
}

/// @brief {rendering} renders the map by creating the images
/// the if / else let the hero move the legs
/// {counter_img} prints the steps and gold on the screen
/// {mlx_image_to_window} prints the image to the window
/// @param param is the game data like the g_sl struct...
/// its only void param because of the mlx_loop_hook
/// which is used to call the function in a loop
void	aktualization(void *param)
{
	t_so_long	*g_sl;

	g_sl = param;
	ft_printf("Gold: %d\n", g_sl->gold->instances[0].z);
	usleep(90000);
	rendering2(g_sl);
	if (g_sl->hero->instances[0].enabled == true)
	{
		mlx_img_to_img(g_sl->first, g_sl->hero,
			g_sl->hero->instances[0].x, g_sl->hero->instances[0].y);
		g_sl->hero->instances[0].enabled = false;
	}
	else
	{
		mlx_img_to_img(g_sl->first, g_sl->hero2,
			g_sl->hero->instances[0].x, g_sl->hero->instances[0].y);
		g_sl->hero->instances[0].enabled = true;
	}
	mlx_img_to_img(g_sl->first, g_sl->slime,
		g_sl->slime->instances[0].x, g_sl->slime->instances[0].y);
	counter_img(g_sl);
	mlx_image_to_window(g_sl->mlx, g_sl->first, 0, 0);
}

/// @brief initializes the game by reading the map and creating the images
/// @param g_sl all the game data
void	create_game(t_so_long *g_sl)
{
	if (read_map1(g_sl) != 0)
		error(6);
	g_sl->mlx = mlx_init((g_sl->map_width * 32),
			(g_sl->map_height * 32), "so_long", true);
	if (!g_sl->mlx)
		error(3);
	g_sl->slime = save_load_png("./images/slime.png", g_sl->mlx);
	g_sl->wall = save_load_png("./images/wall32.png", g_sl->mlx);
	g_sl->floor = save_load_png("./images/floor32.png", g_sl->mlx);
	g_sl->hero = save_load_png("./images/hero1.png", g_sl->mlx);
	g_sl->hero2 = save_load_png("./images/hero2.png", g_sl->mlx);
	g_sl->hero->instances[0].z = 0;
	g_sl->hero->instances[0].enabled = true;
	g_sl->gold = save_load_png("./images/acoin.png", g_sl->mlx);
	g_sl->gold->instances[0].z = 0;
	g_sl->exit1 = save_load_png("./images/exit1.png", g_sl->mlx);
	g_sl->exit2 = save_load_png("./images/exit2.png", g_sl->mlx);
	g_sl->map_img = mlx_new_image(g_sl->mlx,
			g_sl->map_width * 32, g_sl->map_height * 32);
	g_sl->first = mlx_new_image
		(g_sl->mlx, g_sl->map_width * 32, g_sl->map_height * 32);
	rendering(g_sl);
}

/// @brief uses the map given as input argv[1] to create a game
/// {g_sl} is a global variable struct that holds all the game data
/// {create_game} initializes the images and renderis the map.
/// {aktualization} is the main loop of the game, it checks for all
/// the possible inputs and updates the game accordingly.
/// {ft_hook2} is the key hook function that checks for the key inputs
/// {mlx_loop(g_sl->mlx)} updates the game accordingly.
/// {end_cite} frees all the memory allocated and ends the game.
/// @param argc is the number of arguments ./so_long map/a_1.ber
/// @param argv is the map file
/// @return 
int	main(int argc, char **argv)
{
	if (argc != 2)
		error(1);
	g_sl = ft_calloc(1, sizeof(t_so_long));
	if (!g_sl)
		error(2);
	g_sl->argc = argc;
	g_sl->argv = argv;
	create_game(g_sl);
	mlx_loop_hook(g_sl->mlx, aktualization, g_sl);
	mlx_loop_hook(g_sl->mlx, ft_hook2, g_sl->mlx);
	mlx_loop(g_sl->mlx);
	if (g_sl->gold->instances[0].z == 0)
		write(1, "You won\n", 8);
	else
		write(1, "Try Again\n", 10);
	end_cite(g_sl);
}
