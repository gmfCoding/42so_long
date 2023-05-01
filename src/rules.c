/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:50:40 by clovell           #+#    #+#             */
/*   Updated: 2023/05/01 23:12:42 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "state.h"
#include "vector.h"
#include "vectormath.h"

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

/* Sets an array, f, of neighbours to be 1 if that neighbours is a wall */
void	get_neighbours(int *f, t_map *map, int x, int y)
{
	const t_vec	dir[] = {vnew(0, -1), vnew(1, 0), vnew(0, 1), vnew(-1, 0)};
	int			d;

	d = 0;
	while (d < 4)
	{
		if (!bounds(map, x + dir[d].x, y + dir[d].y))
			f[d] = TILE_FLOOR;
		else
			f[d] = get_tile(x + dir[d].x, y + dir[d].y, map).id == TILE_WALL;
		d++;
	}
}

/* q: quads pos
 * f: neighbours
 * texs: tile textures */
static void	p_full_con(t_gamestate *gs, t_vec *q, int *f, t_tiletex *texs)
{
	if (!push_quad(gs, texs[TTEX_CORNER].tl, q[0], f[U] && f[L]))
		push_quad(gs, texs[TTEX_FLOOR].tl, q[0], 1);
	if (!push_quad(gs, texs[TTEX_CORNER].tr, q[1], f[U] && f[R]))
		push_quad(gs, texs[TTEX_FLOOR].tr, q[1], 1);
	if (!push_quad(gs, texs[TTEX_CORNER].bl, q[2], f[D] && f[L]))
		push_quad(gs, texs[TTEX_FLOOR].bl, q[2], 1);
	if (!push_quad(gs, texs[TTEX_CORNER].br, q[3], f[D] && f[R]))
		push_quad(gs, texs[TTEX_FLOOR].br, q[3], 1);
}

/* q: quads
 * f: neighbours
 * texs: tile textures */
static void	p_invcon(t_gamestate *gs, t_vec q[4], int f[4], t_tiletex *texs)
{
	push_quad(gs, texs[TTEX_INVCON].tl, q[0], !f[U] && !f[L]);
	push_quad(gs, texs[TTEX_INVCON].tr, q[1], !f[U] && !f[R]);
	push_quad(gs, texs[TTEX_INVCON].bl, q[2], !f[D] && !f[L]);
	push_quad(gs, texs[TTEX_INVCON].br, q[3], !f[D] && !f[R]);
}

void	push_tile(t_gamestate *gs, t_vec pos)
{
	const int		res = TILE_RES / 2 * 3;
	const t_tiletex	*texs = gs->theme->tiletexs;
	int				f[4];
	t_vec			q[4];
	t_tile tile;

	tile = get_tile(pos.x, pos.y, gs->map);
	q[0] = vadd(vmuls(pos, REND_RES), vnew(0, 0));
	q[1] = vadd(vmuls(pos, REND_RES), vnew(res, 0));
	q[2] = vadd(vmuls(pos, REND_RES), vnew(0, res));
	q[3] = vadd(vmuls(pos, REND_RES), vnew(res, res));
	get_neighbours(f, gs->map, pos.x, pos.y);
	if (tile.id == TILE_WALL)
	{
		p_invcon(gs, q, f, (t_tiletex *)texs);
		return ;
	}
	
	p_full_con(gs, q, f, (t_tiletex *)texs);
	if (tile.collectable)
		push_tex(gs, texs[TTEX_COLL].full, q[0]);

}
