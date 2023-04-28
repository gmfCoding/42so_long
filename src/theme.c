/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:32:46 by clovell           #+#    #+#             */
/*   Updated: 2023/04/28 17:29:57 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "theme.h"
#include "vector.h"

static t_texture	get_subtile_tex(void *mlx, int x, int y, t_texture full)
{
	t_texture	tex;
	const int	res = TILE_RES * TILE_PX_SCALE / 2;
	t_vec		region[2];

	region[0] = vnew(x * res, y * res);
	region[1] = vnew(x * res + res, y * res + res);
	tex = copy_tex(mlx, full, region, 1);
	return (tex);
}

static t_tiletex	get_tile_tex(void *mlx, int i, t_texture entire)
{
	t_tiletex	tile;
	t_vec		region[2];

	region[0] = vnew(0, i * TILE_RES);
	region[1] = vnew(TILE_RES, i * TILE_RES + TILE_RES);
	tile.full = copy_tex(mlx, entire, region, TILE_PX_SCALE);
	tile.tl = get_subtile_tex(mlx, 0, 0, tile.full);
	tile.tr = get_subtile_tex(mlx, 1, 0, tile.full);
	tile.bl = get_subtile_tex(mlx, 0, 1, tile.full);
	tile.br = get_subtile_tex(mlx, 1, 1, tile.full);
	return (tile);
}

t_themeinfo	*load_theme(t_gamestate *state, const char *themeimg)
{
	t_themeinfo	*theme;
	int			i;
	int			x;

	theme = ft_calloc(1, sizeof(t_themeinfo));
	theme->entire = load_texture(state->mlx, themeimg);
	i = 0;
	while (i < TTEX_COUNT)
	{
		theme->tiletexs[i] = get_tile_tex(state->mlx, i, theme->entire);
		theme->tiletexs[i].subquad = i <= 2;
		i++;
	}
	return (theme);
}
