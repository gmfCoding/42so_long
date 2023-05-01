/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:53:27 by clovell           #+#    #+#             */
/*   Updated: 2023/05/01 15:56:46 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define TILE_WALL	0
# define TILE_FLOOR	1
# define TILE_COUNT 2

# define TTEX_FLOOR 0
# define TTEX_CORNER 1
# define TTEX_INVCON 2
# define TTEX_WALL 3
# define TTEX_COUNT 4

# define TILE_RES 32
# define REND_RES 96
# define TILE_PX_SCALE 3

typedef struct s_themeinfo	t_themeinfo;
typedef struct s_gamestate	t_gamestate;
typedef struct s_tiletex	t_tiletex;

#endif
