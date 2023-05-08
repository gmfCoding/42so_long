/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:38:45 by clovell           #+#    #+#             */
/*   Updated: 2023/05/08 23:21:01 by clovell          ###   ########.fr       */
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
#include "vectormath.h"

void	setup_state(t_gamestate *state);

int	end_program(t_gamestate *state)
{
	ft_printf("So long! Bye!");
	exit(0);
}

int	main(void)
{
	static t_gamestate	state;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 1920, 1080, "Hello world!");
	ft_printf("Welcome to so_long!");
	setup_state(&state);
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
	int		error;

	map = load_map("assets/example.ber");
	state->map = map;
	error = verify_contains(map);
	error |= verify_boundary(map);
	error |= map_completeable(map) == 0 * 16;
	if (error)
	{
		ft_printf("Encountered error while verifying map: %u\n", error);
		exit(1);
	}
}

void	setup_state(t_gamestate *state)
{
	setup_world(state);
	state->theme = load_theme(state, "assets/lava_theme.xpm");
	state->pos = state->map->start;
}
