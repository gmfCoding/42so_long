/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:05:26 by clovell           #+#    #+#             */
/*   Updated: 2023/05/01 20:27:52 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "state.h"
#include "ft_printf.h"
#include "input.h"
#include "movement.h"
#include "vectormath.h"

int	can_move(t_vec pos, t_vec dir, t_map *map)
{
	int		oob;
	t_vec	new;

	new = vadd(vmuls(pos, 1.0f / REND_RES), dir);
	oob = bounds(map, new.x, new.y);
	return (oob && get_tile(new.x, new.y, map).id == TILE_FLOOR);
}

int	on_input(int key, t_gamestate *state)
{
	t_vec	*pos;
	t_map	*map;

	map = state->map;
	pos = &state->player->pos;
	if (key == KEY_W && can_move(*pos, vnew(0, -1), map))
		pos->y -= REND_RES;
	if (key == KEY_A && can_move(*pos, vnew(-1, 0), map))
		pos->x -= REND_RES;
	if (key == KEY_S && can_move(*pos, vnew(0, 1), map))
		pos->y += REND_RES;
	if (key == KEY_D && can_move(*pos, vnew(1, 0), map))
		pos->x += REND_RES;
	return (0);
}
