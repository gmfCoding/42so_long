/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:21:37 by clovell           #+#    #+#             */
/*   Updated: 2023/05/22 15:35:17 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "defs.h"
# include "vector.h"
# include "error.h"

typedef enum e_prop
{
	TPROP_NONE = 0,
	TPROP_POS = 1,
	TPROP_EXIT = 2,
	TPROP_COLLECT = 3
}			t_prop;

typedef struct s_tile
{
	int	id;
	int	collectable;
	int	property;
}				t_tile;

typedef struct s_map
{
	int		size_x;
	int		size_y;
	int		collectables;

	t_vec	start;
	t_vec	exit;

	t_tile	*tiles;
}			t_map;

/* map.c */
t_tile	*get_tile_ptr(int x, int y, t_map *map);
t_tile	get_tile(int x, int y, t_map *map);
t_map	*load_map(const char *path, t_error *failed);

/* tile.c */
t_tile	new_c_tile(int id, int collectable);
t_tile	new_tile(int id);
t_tile	new_e_tile(int floor);
t_tile	new_s_tile(int floor);

/* map_verify.c */
t_error	verify_contains(t_map *map);
t_error	verify_boundary(t_map *map);
int		bounds(t_map *map, int x, int y);

/* map_verify_fill.c */
int		map_completeable(t_map *map);
#endif
