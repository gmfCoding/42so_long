/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:38:45 by clovell           #+#    #+#             */
/*   Updated: 2023/04/24 16:41:12 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "map.h"
#include "state.h"
#include "render.h"
#include <fcntl.h>
#include "ft_printf.h"
#include <stdlib.h>

void	setup_state(t_gamestate *state);
int	on_input(int key, t_gamestate *state);

int	end_program(t_gamestate *state)
{
	ft_printf("So long! Bye!");
	exit(0);
}

t_sprite	*create_player(t_gamestate *state)
{
	t_texture	img;
	t_texture	tex;

	img	= load_texture(state->mlx, "assets/player96.xpm");
	tex = copy_texture(state->mlx, img, vnew(0,0), vnew(32,32), 3);
	mlx_destroy_image(state->mlx, img.img);
	return (instance(tex, vnew(0,0)));
}

int	main(void)
{
	static	t_gamestate state;
	
	state.logfile = open("output.log", O_WRONLY);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 1920, 1080, "Hello world!");
	
	state.player = create_player(&state);
	ft_printf("Welcome to so_long!");
	setup_state(&state);
	mlx_loop_hook(state.mlx, on_frame, &state);
	mlx_hook(state.win, 2, 0, on_input, (void *)&state);
	//mlx_hook(state.win, 3, 0, on_input, (void *)&state);
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
