/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:53:27 by clovell           #+#    #+#             */
/*   Updated: 2023/05/02 07:47:11 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define TILE_WALL	0
# define TILE_FLOOR	1
# define TILE_COUNT 2

/* Tile Texture (TTEX) Definitions
 * TTEX_TEX_SUB  -- Defines how many of the first x textures will be sub quads.
 * TTEX_FLOOR	 -- The Floor			tile texture index.
 * TTEX_CORNER	 -- The Corner			tile texture index.
 * TTEX_INVCON	 -- The Inverted Corner	tile texture index.
 * TTEX_WALL	 -- The Wall			tile texture index.
 * TTEX_COLL	 -- The Collectable		tile texture index.
 * TTEX_EXIT	 -- The Exit			tile texture index.
 * TTEX_PLAYER	 -- The Player			tile texture index.
 * TTEX_COUNT 	 -- The amount of tile textures in the theme image.
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
# define TTEX_COLL 4
# define TTEX_EXIT 5
# define TTEX_PLAYER 6
# define TTEX_COUNT 7

# define TILE_RES 32
# define REND_RES 96
# define TILE_PX_SCALE 3

typedef struct s_themeinfo	t_themeinfo;
typedef struct s_gamestate	t_gamestate;
typedef struct s_tiletex	t_tiletex;

#endif
