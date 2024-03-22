#ifndef UTILS_H
# define UTILS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;	
	int		height;	
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

/*Window and Images*/
t_win	new_window(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);

#endif