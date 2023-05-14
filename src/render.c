/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:53:37 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 08:19:20 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "state.h"
#include "texture.h"
#include "libft.h"
#include "ft_printf.h"
#include "render.h"
#include "vectormath.h"

static void	render_tile(t_gamestate *gs, int x, int y)
{
	const t_tiletex	*texs = (const t_tiletex*)&gs->theme->tiletexs;

	push_tex(gs, texs[TTEX_WALL].full, vnew(x * REND_RES, y * REND_RES));
	push_tile(gs, vnew(x, y));
}

static void	render_map(t_gamestate *gs)
{
	int		x;
	int		y;

	y = 0;
	while (y < gs->map->size_y)
	{
		x = 0;
		while (x < gs->map->size_x)
		{
			render_tile(gs, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_other(t_gamestate *gs)
{
	t_tiletex	*texs;

	texs = gs->theme->tiletexs;
	push_tex(gs, texs[TTEX_EXIT].full, vmuls(gs->map->exit, REND_RES));
	push_tex(gs, texs[TTEX_PLAYER].full, vmuls(gs->pos, REND_RES));
}

int	on_frame(t_gamestate *gs)
{
	mlx_clear_window(gs->mlx, gs->win);
	render_map(gs);
	draw_other(gs);
	return (0);
}
