/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:32:46 by clovell           #+#    #+#             */
/*   Updated: 2023/04/26 17:02:38 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "theme.h"

static t_texture get_subtile_tex(void *mlx, int x, int y, t_texture enitre)
{
	t_texture	tex;
	t_vec		start;
	t_vec		end;
	const int res = TILE_RES/4;
	
	start = vnew(x, y);
	end = vnew(x * SUB_RES + SUB_RES, y * SUB_RES + SUB_RES);
	tex = copy_texture(mlx, entire, start, end, TILE_PX_SCALE);
	return (tex);
}


static t_tiletex	get_tile_tex(void *mlx, int x, t_texture entire)
{
	t_tiletex	tile;
	
	tile.tl = get_subtile_tex(mlx, x * TILE_RES, 0, entire);	
	tile.tr = get_subtile_tex(mlx, x * TILE_RES + SUB_RES, 0, entire);	
	tile.bl = get_subtile_tex(mlx, x * TILE_RES, SUB_RES, entire);	
	tile.br = get_subtile_tex(mlx, x * TILE_RES + SUB_RES, SUB_RES, entire);	
	return (tile);
}

t_themeinfo	*load_theme(t_gamestate *state, const char *themeimg)
{
	t_themeinfo	*theme;
	t_texture	tex;
	int			i;
	int			x;

	theme = ft_calloc(1, sizeof(t_themeinfo));
	theme->entire = load_texture(state->mlx, themeimg);
	i = 0;
	while (i < TILE_COUNT)
	{
		theme->subimgs[i] = subimage(state->mlx, i, tex);
		i++;
	}
	return (theme);
}
