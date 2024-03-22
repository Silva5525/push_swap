// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 1024
#define HEIGHT 1024

static mlx_image_t* image;
static mlx_image_t *img1;
static mlx_t* mlx;

// -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }



mlx_image_t *save_load_png(const char *path, mlx_t *mlx)
{
	mlx_image_t		*image;
	mlx_texture_t 	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_delete_texture(texture);
		mlx_delete_image(mlx, image);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (image);
}

void ft_randomize(void* param)
{
	
	mlx_image_to_window(param, image, image->instances[0].x, image->instances[0].y);
	mlx_image_to_window(param, img1, 0, 0);
	// {
	// 	for (uint32_t y = 0; y < image->height; ++y)
	// 	{
	// 		// uint32_t color = ft_pixel(
	// 		// 	rand() % 0xFF, // R
	// 		// 	rand() % 0xFF, // G
	// 		// 	rand() % 0xFF, // B
	// 		// 	rand() % 0xFF  // A
	// 		// );
			
	// 		// mlx_put_pixel(image, i, y, hero);
			
			
	// 		// mlx_put_pixel(image, i, y, mlx_get_pixel(hero, i, y));
	// 	}
	// }

}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t main(void)
{
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 32, 32)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	xpm_t *xpm;
	xpm = mlx_load_xpm42("./images/coolesbild.xpm42");
	img1 = mlx_texture_to_image(mlx, &xpm->texture);
	free(xpm);
	mlx_image_to_window(mlx, img1, 0, 0);
	image = save_load_png("./images/hero1.png", mlx);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	image->instances[0].z = 1;
	img1->instances[0].z = 0;
	// // xpm = mlx_load_xpm42("./images/coolesbild.xpm42");
	// mlx_image_t *img2 = mlx_texture_to_image(mlx, &xpm->texture);
	// free(xpm);
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// // Written by Bruh

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include "MLX42/MLX42.h"
// #define WIDTH 256
// #define HEIGHT 256

// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// #include "MLX42/MLX42.h"
// #include <stdlib.h>
// #include <string.h>

// // Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
// #define BPP sizeof(int32_t)

// int get_r(int rgba)
// {
//     // Move 3 bytes to the right and mask out the first byte.
//     return ((rgba >> 24) & 0xFF);
// }

// int32_t	main(void)
// {
//     // Init mlx with a canvas size of 256x256 and the ability to resize the window.
//     mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    
//     if (!mlx) exit(EXIT_FAILURE);

//     // Create a 128x128 image.
//     mlx_image_t* img = mlx_new_image(mlx, 256, 210);

//     // Set the channels of each pixel in our image to the maximum byte value of 255. 
//     memset(img->pixels, 255, img->width * img->height * BPP);

//     // Draw the image at coordinate (0, 0).
//     mlx_image_to_window(mlx, img, 0, 0);

//     // Run the main loop and terminate on quit.  
//     mlx_loop(mlx);
//     mlx_terminate(mlx);

//     return (EXIT_SUCCESS);
// }


// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include "MLX42/MLX42.h"
// #define WIDTH 5120
// #define HEIGHT 2880

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// int32_t	main(void)
// {
// 	// Start mlx
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// 	if (!mlx)
// 		error();

// 	// Try to load the file
// 	xpm_t* xpm = mlx_load_xpm42("./temp/42.xpm42");
// 	if (!xpm)
// 		error();
	
// 	// Convert texture to a displayable image
// 	mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
// 	if (!img)
// 		error();

// 	// Display the image
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
// 		error();

// 	mlx_loop(mlx);

// 	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
// 	mlx_delete_image(mlx, img);
// 	mlx_delete_xpm42(xpm);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// // Funktioniert erst einmal
// // -----------------------------------------------------------------------------

// // -----------------------------------------------------------------------------

// // -----------------------------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <MLX42/MLX42.h>

// #define WIDTH 1024
// #define HEIGHT 1024

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// // static void error(void)
// // {
// // 	puts(mlx_strerror(mlx_errno));
// // 	exit(EXIT_FAILURE);
// // }

// // int32_t	main(void)
// // {
// // 	// Start mlx
// // 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// // 	if (!mlx)
// //         error();

// // 	// Try to load the file
// // 	mlx_texture_t* texture = mlx_load_png("./images/sus.png");
// // 	if (!texture)
// //         error();
// // 	// Convert texture to a displayable image
// // 	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// // 	if (!img)
// //         error();
// // 	// Display the image
// // 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
// //         error();

// // 	mlx_loop(mlx);
// // 	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
// // 	mlx_delete_image(mlx, img);
// // 	mlx_delete_texture(texture);
// // 	mlx_terminate(mlx);
// // 	return (EXIT_SUCCESS);
// // }

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	xpm_t *xpm;
// 	xpm = mlx_load_xpm42("./images/coolesbild.xpm42");
// 	mlx_image_t *img1 = mlx_texture_to_image(mlx, &xpm->texture);
// 	free(xpm);
// 	mlx_image_to_window(mlx, img1, 0, 0);
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}

// 	// // xpm = mlx_load_xpm42("./images/coolesbild.xpm42");
// 	// mlx_image_t *img2 = mlx_texture_to_image(mlx, &xpm->texture);
// 	// free(xpm);

	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);
	
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }