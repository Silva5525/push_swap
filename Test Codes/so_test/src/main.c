#include "./mlx42/include/MLX42/mlx42.h"
#include <stdlib.h>
 
int main(void)
{
	void *mlx_ptr;
 
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	free(mlx_ptr);
	return (0);
}