/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:53:37 by clovell           #+#    #+#             */
/*   Updated: 2023/04/28 21:16:36 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "movement.h"
#include "vector.h"
#include "state.h"
#include "texture.h"
#include "libft.h"
#include "ft_printf.h"
#include "render.h"

/* Sets an array of neighbours to be 1 if that neighbours is a wall */
static void	get_neighbours(int *f, t_map *map, int x, int y)
{
	const t_vec	dir[] = {vnew(0, -1), vnew(1, 0), vnew(0, 1), vnew(-1, 0)};
	int			d;
	
	d = 0;
	while (d < 4)
	{
		if (!bounds(map, x + dir[d].x, y + dir[d].y))
			f[d] = 0;
		else
			f[d] = get_tile(x + dir[d].x, y + dir[d].y, map).id == TILE_WALL;
		d++;
	}
}


void render_tile(t_gamestate *gs, t_map *map, int x, int y)
{
	const int res = TILE_RES / 2 * 3; 
	t_tiletex *texs = gs->theme->tiletexs;
	int	f[4];

	push_sprite(gs, instance(texs[TTEX_WALL].full, vnew(x * REND_RES, y * REND_RES)));
	push_tilequads(gs, vnew(x, y));	
	return ;
	get_neighbours(f, gs->map, x, y);
	if (get_tile(x, y, map).id == TILE_WALL)
	{

		if (!f[0] && !f[3])
			push_tex(gs, texs[TTEX_INVCON].tl, vnew(x * REND_RES, y * REND_RES));
		if (!f[0] && !f[1])
			push_tex(gs, texs[TTEX_INVCON].tr, vnew(x * REND_RES + res, y * REND_RES));
		if (!f[2] && !f[3])
			push_tex(gs, texs[TTEX_INVCON].bl, vnew(x * REND_RES, y * REND_RES + res));
		if (!f[2] && !f[1])
			push_tex(gs, texs[TTEX_INVCON].br, vnew(x * REND_RES + res, y * REND_RES + res));
		if (x == 0 && y == 4)
			push_debugtex(gs, x * REND_RES, y * REND_RES);
		return ;
	}
	if (f[0] && f[3])
		push_tex(gs, texs[TTEX_CORNER].tl, vnew(x * REND_RES, y * REND_RES));
	else
		push_tex(gs, texs[TTEX_FLOOR].tl, vnew(x * REND_RES, y * REND_RES));	
	if (f[0] && f[1])
		push_tex(gs, texs[TTEX_CORNER].tr, vnew(x * REND_RES + res, y * REND_RES));
	else
		push_tex(gs, texs[TTEX_FLOOR].tr, vnew(x * REND_RES + res, y * REND_RES));
	if (f[2] && f[3])
		push_tex(gs, texs[TTEX_CORNER].bl, vnew(x * REND_RES, y * REND_RES + res));
	else
		push_tex(gs, texs[TTEX_FLOOR].bl, vnew(x * REND_RES, y * REND_RES + res));
	if (f[2] && f[1])
		push_tex(gs, texs[TTEX_CORNER].br, vnew(x * REND_RES + res, y * REND_RES + res));
	else
		push_tex(gs, texs[TTEX_FLOOR].br, vnew(x * REND_RES + res, y * REND_RES + res));
}

void	render_map(t_gamestate *gs, t_map *map)
{
	int		x;
	int		y;
	t_tile	*tiles;

	tiles = map->tiles;
	y = 0;
	while (y < gs->map->size_y)
	{
		x = 0;
		while (x < gs->map->size_x)
		{
			render_tile(gs, map, x, y);
			x++;
		}
		y++;
	}
}

int	on_frame(t_gamestate *gs)
{
	t_list	*sp_next;
	int		x;
	int		y;
	void	*image;

	mlx_clear_window(gs->mlx, gs->win);
	sp_next = gs->sprites;
	x = 0;
	while (sp_next && sp_next->next)
	{
		push_sprite(gs, sp_next->content);
		sp_next = sp_next->next;
	}
	y = 0;
	render_map(gs, gs->map);
	mv_process_frame(gs->player, &gs->move);
	push_sprite(gs, gs->player);
	return (0);
}
