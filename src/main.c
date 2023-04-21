#include <mlx.h>
#include "example.h"
#include "map.h"
#include "state.h"
#include "render.h"

void	setup_state(t_gamestate *state);

int	main(void)
{
	static	t_gamestate state;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 1920, 1080, "Hello world!");
	setup_state(&state);
	
	mlx_loop_hook(mlx, frame, &state);
	mlx_loop(state.mlx);
}



void	*get_tile_image(t_gamestate *state, int id)
{
	static int x;
	static int y;

	if (!state->tile_images[id])
	{
		if (id == TILE_FLOOR)
			state->tile_images[id] =  mlx_xpm_file_to_image(state->mlx, "assets/tile_dirt.xpm", &x, &y);
		else if (id == TILE_WALL)
			state->tile_images[id] =  mlx_xpm_file_to_image(state->mlx, "assets/tile_wall.xpm", &x, &y);
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

void	setup_state(t_gamestate *state)
{
	setup_world(state);
	
}
