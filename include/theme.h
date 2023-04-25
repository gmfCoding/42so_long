/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:08:48 by clovell           #+#    #+#             */
/*   Updated: 2023/04/25 17:13:02 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_H
# define THEME_H
/* FULL TILE QUADRANTS */
# define TILE_FTL 0
# define TILE_FTR 1
# define TILE_FBL 4
# define TILE_FBR 5

/* CORNER QUADRANTS */

# define TILE_CTL 2
# define TILE_CTR 3
# define TILE_CBL 6
# define TILE_CBR 7

/* INVERTED CORNER QUADRANTS */
# define TILE_ITL 4
# define TILE_ITR 5
# define TILE_IBL 8
# define TILE_IBR 9
# define SUB_TILE_COUNT 12

# define SHEET_WIDTH 4
# define SHEET_HEIGHT 4
# define TILE_PX_SCALE 3
# define SUB_RES 16

# include "state.h"
# include "texture.h"

typedef struct s_themeinfo
{
	t_texture	entire;
	t_texture	subimgs[SUB_TILE_COUNT];

}				t_themeinfo;
t_themeinfo	*loadtheme(t_gamestate *state, const char *themeimg);
#endif
