/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:32:46 by clovell           #+#    #+#             */
/*   Updated: 2023/04/25 16:00:54 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "theme.h"

static t_texture	subimage(void *mlx, int x, int y, t_texture entire)
{
	t_texture	imrg;
	t_vec		start;
	t_vec		end;

	start = vnew(x * SUB_RES, x * SUB_RES);
	end = vnew(x * SUB_RES + SUB_RES, y * SUB_RES + SUB_RES);
	img = copy_texture(mlx, entire, start, end, TILE_PX_SCALE);
	return (img);
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
	while (i < SUB_TILE_COUNT)
	{
		x = i % SHEET_WIDTH;
		theme->subimgs[i] = subimage(state->mlx, x, i / SHEET_WIDTH, tex);
		i++;
	}
	return (theme);
}
