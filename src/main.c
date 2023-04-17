#include <mlx.h>
#include "example.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int height;
	int width;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_png_file_to_image(mlx, "assets/tile_dirt.png", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 96 * 0, 96 * 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 96 * 1, 96 * 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 96 * 2, 96 * 0);
	mlx_put_image_to_window(mlx, mlx_win, img, 96 * 0, 96 * 1);
	mlx_put_image_to_window(mlx, mlx_win, img, 96 * 1, 96 * 1);
	mlx_put_image_to_window(mlx, mlx_win, img, 96 * 2, 96 * 1);
	mlx_loop(mlx);
}

