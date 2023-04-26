/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:08:48 by clovell           #+#    #+#             */
/*   Updated: 2023/04/26 17:48:37 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_H
# define THEME_H
#include "texture.h"

# define TILE_RES 32
# define TILE_PX_SCALE 3

typedef struct s_tiletex
{
	int subquad;
	t_texture full;

	t_texture tl;
	t_texture tr;
	t_texture bl;
	t_texture br;
}				t_tiletex;

# include "state.h"
# include "texture.h"

typedef struct s_themeinfo
{
	t_texture	entire;
	t_tiletex	tiletexs[TILE_COUNT];
}				t_themeinfo;

t_themeinfo	*loadtheme(t_gamestate *state, const char *themeimg);
#endif
