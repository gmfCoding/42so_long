/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:38:45 by clovell           #+#    #+#             */
/*   Updated: 2023/05/22 17:41:41 by clovell          ###   ########.fr       */
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
#include "error.h"
#include "game.h"
#include "destroy.h"

void	setup_state(t_gamestate *state);

int	end_program(t_gamestate *state)
{
	destroy_state(state);
	ft_printf("So long! Bye!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	static t_gamestate	*state;

	state = ft_calloc(1, sizeof(t_gamestate));
	if (argc <= 1)
	{
		ft_printf("Error\nNo map specified, please specify a map as an arg!");
		exit(0);
	}
	else
		state->map_path = argv[1];
	setup_state(state);
	mlx_loop_hook(state->mlx, on_frame, state);
	mlx_hook(state->win, 2, 1L << 0, on_input, (void *)state);
	mlx_hook(state->win, 17, 0, end_program, state);
	mlx_loop(state->mlx);
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
	t_error	error;
	t_map	*map;

	error = E_NONE;
	map = load_map(state->map_path, &error);
	if (!error)
	{
		if (map != NULL)
		{
			state->map = map;
			error |= verify_contains(map);
			error |= verify_boundary(map);
			error |= (map_completeable(map) == 0) * E_PATH;
		}
		else
			error = E_FILE;
	}
	if (error)
		exit_error(error);
	state->tile_event = &on_tile;
}

void	setup_state(t_gamestate *state)
{
	state->quit_event = &end_program;
	setup_world(state);
	setup_window(state);
	state->theme = load_theme(state, "assets/lava_theme.xpm");
	state->pos = state->map->start;
}
