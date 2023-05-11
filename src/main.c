/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:38:45 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 13:14:46 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>

#include "defs.h"
#include "theme.h"
#include "map.h"
#include "state.h"
#include "render.h"
#include "ft_printf.h"
#include "input.h"
#include "vectormath.h"

void	setup_state(t_gamestate *state);

int	end_program(t_gamestate *state)
{
	mlx_destroy_window(state->mlx, state->win);
	ft_printf("So long! Bye!");
	exit(0);
}

int	main(int argc, char **argv)
{
	static t_gamestate	state;

	if (argc <= 1)
	{
		ft_printf("No map specified, please specify a map as an arg!");
		state.map_path = "assets/example.ber";
		/* PLEASE EXIT INSTEAD OF DEFAULT MAP PATH*/
	}
	else
		state.map_path = argv[1];
	setup_state(&state);
	mlx_loop_hook(state.mlx, on_frame, &state);
	mlx_hook(state.win, 2, 1L << 0, on_input, (void *)&state);
	mlx_hook(state.win, 17, 0, end_program, &state);
	mlx_loop(state.mlx);
}

void	setup_window(t_gamestate *state)
{
	int	width;
	int	height;

	width = state->map->size_x * REND_RES;
	height = state->map->size_y * REND_RES;
	state->w_width = width;
	state->w_height = height;
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, width, height, "SO_LONG");
}

void	setup_world(t_gamestate *state)
{
	int		error;
	t_map	*map;

	map = load_map(state->map_path);
	state->map = map;
	error = verify_contains(map);
	error |= verify_boundary(map);
	error |= map_completeable(map) == 0 * E_PATH;
	if (error)
	{
		ft_printf("Encountered error while verifying map: %u\n", error);
		exit(1);
	}
}

void	setup_state(t_gamestate *state)
{
	setup_world(state);
	setup_window(state);
	state->theme = load_theme(state, "assets/lava_theme.xpm");
	state->pos = state->map->start;
}
