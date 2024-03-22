#include "utils.h"
#include "libft.h"
#include <signal.h>

int stop_serv = 0;

// void sig_handl(int)
// {
// 	stop_serv = 42;
// 	ft_putendl_fd("Signal recieved, for now... exit without free\n", 2);
// 	exit(1);
// }

int main(void)
{
 	t_win	tutorial;
	t_img	image;

	// signal(SIGINT, sig_handl);
	tutorial = new_window(300, 300, "animations");
	if (!tutorial.win_ptr)
		return (2);
	image = new_img(300, 300, tutorial);

	{
		/* Put white pixel */
		put_pixel_img(image, 150, 150, 0x00FFFFFF);
		mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	}

	mlx_loop(tutorial.mlx_ptr);
	mlx_destroy_window(tutorial.mlx_ptr, tutorial.win_ptr);
	return (0);
}