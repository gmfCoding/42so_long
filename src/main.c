/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:38:45 by clovell           #+#    #+#             */
/*   Updated: 2023/05/01 20:12:15 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>

#include "theme.h"
#include "map.h"
#include "state.h"
#include "render.h"
#include "ft_printf.h"
#include "input.h"
#include <stdio.h>
#include "vectormath.h"

void	setup_state(t_gamestate *state);

int	end_program(t_gamestate *state)
{
	ft_printf("So long! Bye!");
	exit(0);
}

t_sprite	*create_player(t_gamestate *state)
{
	t_texture	img;
	t_texture	tex;
	const t_vec	region[] = {vnew(0, 0), vnew(32, 32)};

	img = load_texture(state->mlx, "assets/player96.xpm");
	tex = copy_tex(state->mlx, img, region, 3);
	mlx_destroy_image(state->mlx, img.img);
	return (instance(tex, vmuls(state->map->start, REND_RES)));
}

int	main(void)
{
	static t_gamestate	state;

	state.logfile = open("output.log", O_WRONLY);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 1920, 1080, "Hello world!");
	ft_memset(&state.move, 0, sizeof(t_pmove));
	ft_printf("Welcome to so_long!");
	setup_state(&state);
	printf("start:%f %f\n", state.map->start.x, state.map->start.y);
	state.theme = load_theme(&state, "assets/lava_theme.xpm");
	mlx_loop_hook(state.mlx, on_frame, &state);
	mlx_hook(state.win, 2, 1L << 0, on_input, (void *)&state);
	mlx_hook(state.win, 17, 0, end_program, &state);
	mlx_loop(state.mlx);
}

void	setup_world(t_gamestate *state)
{
	int		x;
	int		y;
	t_map	*map;

	map = load_map("assets/example.ber");
	state->map = map;
}

void	setup_state(t_gamestate *state)
{
	setup_world(state);
	state->player = create_player(state);
}
