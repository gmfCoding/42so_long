/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:50:40 by clovell           #+#    #+#             */
/*   Updated: 2023/05/19 18:49:19 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "state.h"
#include "vector.h"
#include "vectormath.h"
#include <math.h>

#include "defs.h"
#include "map.h"
#include "render.h"

#define U 0
#define R 1
#define D 2
#define L 3

static int	push_quad(t_gamestate *gs, t_texture tex, t_vec pos, int cond)
{
	if (cond)
		push_tex(gs, tex, pos);
	return (cond);
}

/* Sets an array, n, of neighbours to be 1 if that neighbours is a wall */
static void	get_neighbours(int *n, t_map *map, int x, int y)
{
	const t_vec	dir[] = {vnew(0, -1), vnew(1, 0), vnew(0, 1), vnew(-1, 0)};
	int			d;

	d = 0;
	while (d < 4)
	{
		if (!bounds(map, x + dir[d].x, y + dir[d].y))
			n[d] = TILE_FLOOR;
		else
			n[d] = get_tile(x + dir[d].x, y + dir[d].y, map).id == TILE_WALL;
		d++;
	}
}

/* p: positions
 * n: neighbours
 * texs: tile textures */
static void	p_full_con(t_gamestate *gs, t_vec *p, int *n, t_tiletex *texs)
{
	if (!push_quad(gs, texs[TTEX_CORNER].tl, p[0], n[U] && n[L]))
		push_quad(gs, texs[TTEX_FLOOR].tl, p[0], 1);
	if (!push_quad(gs, texs[TTEX_CORNER].tr, p[1], n[U] && n[R]))
		push_quad(gs, texs[TTEX_FLOOR].tr, p[1], 1);
	if (!push_quad(gs, texs[TTEX_CORNER].bl, p[2], n[D] && n[L]))
		push_quad(gs, texs[TTEX_FLOOR].bl, p[2], 1);
	if (!push_quad(gs, texs[TTEX_CORNER].br, p[3], n[D] && n[R]))
		push_quad(gs, texs[TTEX_FLOOR].br, p[3], 1);
}

/* p: positions
 * n: neighbours
 * texs: tile textures */
static void	p_invcon(t_gamestate *gs, t_vec p[4], int n[4], t_tiletex *texs)
{
	push_quad(gs, texs[TTEX_INVCON].tl, p[0], !n[U] && !n[L]);
	push_quad(gs, texs[TTEX_INVCON].tr, p[1], !n[U] && !n[R]);
	push_quad(gs, texs[TTEX_INVCON].bl, p[2], !n[D] && !n[L]);
	push_quad(gs, texs[TTEX_INVCON].br, p[3], !n[D] && !n[R]);
}

void	push_tile(t_gamestate *gs, t_vec pos)
{
	const int		res = TILE_RES / 2 * TILE_PX_SCALE;
	const t_tiletex	*texs = gs->theme->tiletexs;
	int				n[4];
	t_vec			p[4];
	t_tile			tile;

	tile = get_tile(pos.x, pos.y, gs->map);
	p[0] = vadd(vmuls(pos, REND_RES), vnew(0, 0));
	p[1] = vadd(vmuls(pos, REND_RES), vnew(res, 0));
	p[2] = vadd(vmuls(pos, REND_RES), vnew(0, res));
	p[3] = vadd(vmuls(pos, REND_RES), vnew(res, res));
	get_neighbours(n, gs->map, pos.x, pos.y);
	if (tile.id == TILE_WALL)
	{
		p_invcon(gs, p, n, (t_tiletex *)texs);
		return ;
	}
	p_full_con(gs, p, n, (t_tiletex *)texs);
	if (!tile.collectable)
		return ;
	p[0].y = p[0].y + sin(gs->frame / 2.0f * FRAME_RATE) * 10.0f;
	push_tex(gs, texs[TTEX_COL + (gs->frame / 8) % 3].full, p[0]);
}
