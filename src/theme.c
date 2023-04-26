/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:32:46 by clovell           #+#    #+#             */
/*   Updated: 2023/04/26 18:49:18 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "theme.h"
#include "vector.h"

static t_texture	get_subtile_tex(void *mlx, int x, int y, t_texture entire)
{
	t_texture	tex;
	const int	res = TILE_RES / 4;
	t_vec		region[2];

	region[0] = vnew(x, y);
	region[1] = vnew(x + res, y + res);
	tex = copy_texture(mlx, entire, region, TILE_PX_SCALE);
	return (tex);
}

static t_tiletex	get_tile_tex(void *mlx, int i, t_texture entire)
{
	t_tiletex	tile;
	const int	res = TILE_RES / 4;

	tile.tl = get_subtile_tex(mlx, i * TILE_RES, 0, entire);
	tile.tr = get_subtile_tex(mlx, i * TILE_RES + res, 0, entire);
	tile.bl = get_subtile_tex(mlx, i * TILE_RES, res, entire);
	tile.br = get_subtile_tex(mlx, i * TILE_RES + res, res, entire);
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
	while (i < TILE_COUNT)
	{
		theme->tiletexs[i] = get_tile_tex(state->mlx, i, theme->entire);
		theme->tiletexs[i].subquad = i <= 1;
		i++;
	}
	return (theme);
}
