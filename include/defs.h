/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:53:27 by clovell           #+#    #+#             */
/*   Updated: 2023/05/19 18:49:53 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define FRAME_RATE 75

# define TILE_WALL	0
# define TILE_FLOOR	1
# define TILE_COUNT 2

/* Theme Texture (TTEX) Definitions
 * TTEX_TEX_SUB  -- Defines how many of the first x textures will be sub quads.
 * TTEX_FLOOR	 -- The Floor			theme texture index.
 * TTEX_CORNER	 -- The Corner			theme texture index.
 * TTEX_INVCON	 -- The Inverted Corner	theme texture index.
 * TTEX_WALL	 -- The Wall			theme texture index.
 * TTEX_COLL	 -- The Collectable		theme texture index.
 * TTEX_EXIT	 -- The Exit			theme texture index.
 * TTEX_PLAYER	 -- The Player			theme texture index.
 * TTEX_COUNT 	 -- The amount of theme textures in the theme image.
 * 
 * TILE_RES		 -- The resolution of each tile
 * REND_RES		 -- The rendered resolution of the tiles: TILE_RES * REND_RES.
 * TILE_PX_SCALE -- The REND_RES / TILE_RES
 * */
# define TTEX_TEX_SUB 3
# define TTEX_FLOOR 0
# define TTEX_CORNER 1
# define TTEX_INVCON 2
# define TTEX_WALL 3
# define TTEX_EXIT 4
# define TTEX_COL 5
# define TTEX_COUNT 9
# define TTEX_COLFRAMES 3

/* TTEX_PLAYER = TTEX_COUNT + TTEX_COLFRAMES */
# define TTEX_PLAYER 8

/* Update rate of the collider animation */
# define UPD_COL 6

# define TILE_RES 32
# define REND_RES 96
# define TILE_PX_SCALE 3

typedef struct s_themeinfo	t_themeinfo;
typedef struct s_gamestate	t_gamestate;
typedef struct s_tiletex	t_tiletex;
typedef struct s_playertex	t_playertex;

#endif
