/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:24:33 by clovell           #+#    #+#             */
/*   Updated: 2023/05/15 16:38:34 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "state.h"
#include "ft_printf.h"
#include "input.h"
#include "vectormath.h"
#include "stdlib.h"

static int	can_move(t_vec pos, t_vec dir, t_map *map)
{
	int		oob;
	t_vec	new;

	new = vadd(pos, dir);
	oob = bounds(map, new.x, new.y);
	return (oob && get_tile(new.x, new.y, map).id == TILE_FLOOR);
}

static void	count_move(t_gamestate *state, float *mode, float direction)
{
	*mode += direction;
	state->moves++;
	ft_printf("Move: %d\n", state->moves);
}

int	on_input(int key, t_gamestate *state)
{
	t_vec	*pos;
	t_map	*map;
	t_vec	prev;

	map = state->map;
	pos = &state->pos;
	prev = state->pos;
	if (key == KEY_W && can_move(*pos, vnew(0, -1), map))
		count_move(state, &pos->y, -1);
	if (key == KEY_A && can_move(*pos, vnew(-1, 0), map))
		count_move(state, &pos->x, -1);
	if (key == KEY_S && can_move(*pos, vnew(0, 1), map))
		count_move(state, &pos->y, 1);
	if (key == KEY_D && can_move(*pos, vnew(1, 0), map))
		count_move(state, &pos->x, 1);
	if (vmag(vsub(prev, *pos)) > 0.01f)
		state->prevpos = prev;
	state->tile_event(state, get_tile_ptr(pos->x, pos->y, map), pos->x, pos->y);
	return (0);
}

void	on_tile(t_gamestate *state, t_tile *tile, int x, int y)
{
	t_vec	*pos;
	t_map	*map;

	(void)x;
	(void)y;
	pos = &state->pos;
	map = state->map;
	if (tile->collectable > 0)
	{	
		state->collected++;
		tile->collectable = 0;
		ft_printf("Collected: %d/%d\n", state->collected, map->collectables);
	}
	if (pos->x == map->exit.x && pos->y == map->exit.y)
		if (state->collected >= map->collectables)
			state->quit_event(state);
}
