/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:08:48 by clovell           #+#    #+#             */
/*   Updated: 2023/05/15 19:48:21 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_H
# define THEME_H
# include "texture.h"
# include "defs.h"
# include "state.h"

struct s_tiletex
{
	int			subquad;

	t_texture	full;
	t_texture	tl;
	t_texture	tr;
	t_texture	bl;
	t_texture	br;
};

struct s_playertex
{
	t_texture	top;
	t_texture	left;
	t_texture	right;
	t_texture	down;
};

struct s_themeinfo
{
	t_texture	entire;
	t_tiletex	tiletexs[TTEX_COUNT];
	t_playertex	player;
};

t_themeinfo	*load_theme(t_gamestate *state, char *themeimg);
#endif
