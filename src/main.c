#include <mlx.h>
#include "example.h"
#include "map.h"


typedef struct	s_gamestate
{
	void	*mlx;
	int		w_width;
	int		w_height;
	void	*mlx_win;
	void	*tile_images[TILE_COUNT];
	
	t_map	*map;
	int		playerX;
	int		playerY;
}			t_gamestate;

int	main(void)
{
	static	t_gamestate state;
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
	mlx_put_image_to_window(mlx, mlx_win, img, 1 + 96 * 2, 1+ 96 * 1);
	mlx_loop(mlx);
}



void	*get_tile_image(t_gamestate *state, int id)
{
	if (!images[id])
	{
		if (id == TILE_FLOOR)
			state->tiles_images[id] = mlx_png_file_to_image(state->mlx, "assets/tile_dirt.png");

	}	
	return (images[id]);
}

void setup_world()
{
	int x;
	int y;
	t_map	*map = loadmap("assets/example.ber");
	
	x = 0;
	y = 0;
	while (y < map->sizeY)
	{
		while (x < map->sizeX)
		{
			
		}
	}
}
