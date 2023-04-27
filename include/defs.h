/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:53:27 by clovell           #+#    #+#             */
/*   Updated: 2023/04/27 12:06:53 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define TILE_PLAYER	0
# define TILE_WALL		1
# define TILE_FLOOR		2
# define TILE_EXIT		3
# define TILE_COLLECT	4
# define TILE_COUNT 4

# define TILE_RES 32
# define TILE_PX_SCALE 3

typedef struct s_themeinfo	t_themeinfo;
typedef struct s_gamestate	t_gamestate;
typedef struct s_tiletex	t_tiletex;

#endif
