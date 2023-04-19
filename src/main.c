#include <mlx.h>
#include "example.h"
#include "map.h"


typedef struct	s_gamestate
{
	void	*mlx;
	void	*win;
	
	int		w_width;
	int		w_height;

	void	*tile_images[TILE_COUNT];
	
	t_map	*map;
	t_vec playerPos;
}			t_gamestate;

int	main(void)
{
	static	t_gamestate state;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 1920, 1080, "Hello world!");
	setup_state(&state);
	mlx_loop(mlx);
}



void	*get_tile_image(t_gamestate *state, int id)
{
	int x;
	int y;

	if (!state->tile_images[id])
	{
		if (id == TILE_FLOOR)
			state->tiles_images[id] = mlx_png_file_to_image(state->mlx, "assets/tile_dirt.png", &x, &y);
		else if (id == TILE_WALL)
			state->tiles_images[id] = mlx_png_file_to_image(state->mlx, "assets/tile_wall.png", &x, &y);
	}	
	return (state->tile_images[id]);
}

void setup_world(t_gamestate *state)
{
	int x;
	int y;
	t_map	*map = load_map("assets/example.ber");
	
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			mlx_put_image_to_window(state->mlx, state->win, get_tile_image(state, map->tiles[y * map->size_x + x].id) , 96 * x, 96 * y);	
			x++;
		}
		y++;
	}

}

void	setupstate(t_gamestate *state)
{
	setup_world(state);
	
}
