/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:05:26 by clovell           #+#    #+#             */
/*   Updated: 2023/05/11 13:12:57 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "state.h"
#include "ft_printf.h"
#include "input.h"
#include "vectormath.h"

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

	map = state->map;
	pos = &state->pos;
	if (key == KEY_W && can_move(*pos, vnew(0, -1), map))
		count_move(state, &pos->y, -1);
	if (key == KEY_A && can_move(*pos, vnew(-1, 0), map))
		count_move(state, &pos->x, -1);
	if (key == KEY_S && can_move(*pos, vnew(0, 1), map))
		count_move(state, &pos->y, 1);
	if (key == KEY_D && can_move(*pos, vnew(1, 0), map))
		count_move(state, &pos->x, 1);
	if (get_tile(pos->x, pos->y, map).collectable > 0)
	{	
		state->collected++;
		get_tile_ptr(pos->x, pos->y, map)->collectable = 0;
	}
	return (0);
}
