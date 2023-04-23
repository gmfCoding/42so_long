#include <mlx.h>
#include "map.h"
#include "state.h"
#include "render.h"
#include <fcntl.h>
#include "ft_printf.h"

void	setup_state(t_gamestate *state);
void on_input(int key, t_gamestate *state);

int	end_program(t_gamestate *state)
{
	ft_printf("closed!");
	exit(0);
}

int	main(void)
{
	static	t_gamestate state;
	
	state.logfile = open("output.log", O_WRONLY);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 1920, 1080, "Hello world!");

	ft_printf("world");
	setup_state(&state);
	mlx_loop_hook(state.mlx, on_frame, &state);
	mlx_hook(state.win, 2, 0, on_input, (void *)&state);
	mlx_hook(state.win, 3, 0, on_input, (void *)&state);
	mlx_hook(state.win, 17, 0, end_program, &state);
	mlx_loop(state.mlx);
}

void setup_world(t_gamestate *state)
{
	int x;
	int y;
	t_map	*map = load_map("assets/example.ber");
	state->map = map;	
	// y = 0;
	// while (y < map->size_y)
	// {
	// 	x = 0;
	// 	while (x < map->size_x)
	// 	{
	// 		mlx_put_image_to_window(state->mlx, state->win, get_tile_image(state, map->tiles[y * map->size_x + x].id) , 96 * x, 96 * y);	
	// 		x++;
	// 	}
	// 	y++;
	// }

}

void	setup_state(t_gamestate *state)
{
	setup_world(state);
	
}
